// Winsock ���̺귯�� ����
#pragma comment(lib, "ws2_32.lib") 

#include <WinSock2.h> 

#include <string>
#include <iostream>
#include <thread>
#include <vector>

#define MAX_BUFF_SIZE 1024 // ������ ���� : ����
#define MAX_CLIENT 3

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::thread;

struct SOCKET_INFO
{
	SOCKET socket; // ���� �ڷ��� ����
	string user;

};

// client ������ ���� ���� ����
vector<SOCKET_INFO> socket_list;

SOCKET_INFO server_socket;

int client_count = 0;

// ���� �ʱ�ȭ, for socket() ~ listen()
void server_init();
// 1���� Ŭ���̾�Ʈ�� ���� ������ ����
void add_client();
void send_msg(const char* message);
void recv_msg(int idx);
void del_client(int idx);


int main() {

	// for WSAStartup() : Windows Socket API �ʱ�ȭ
	WSADATA wsa;

	int code = WSAStartup(MAKEWORD(2, 2), &wsa);

	// �ʱ�ȭ ���� : Winsock ����غ�
	if (code == 0)
	{
		server_init();

		// �迭�� ������ ��ü 3�� ����
		thread client_threads[MAX_CLIENT];

		for (int i = 0; i < MAX_CLIENT; i++)
		{
			client_threads[i] = thread(add_client);
		}

		// ������ �޼����� ���������� ����?
		while (true)
		{
			string text, message = "";

			// ���κ��� getline �Ǵ� ���ΰ�, ����� �Է��� �ƴ��װ�
			// ����� �Է��� �´�, ������ ���� �ְ�޴� ����
			std::getline(std::cin, text);
			const char* buffer = text.c_str();

			message = server_socket.user + ": " + buffer;
			send_msg(message.c_str());
		}

		for (int i = 0; i < MAX_CLIENT; i++)
		{
			client_threads[i].join();
		}

		closesocket(server_socket.socket);
	}

	// �ʱ�ȭ ���� 
	else
	{
		cout << "���α׷� ����. (Error Code: " << code << ")";
	}

	WSACleanup();

	return 0;
}

// ���� �ʱ�ȭ
void server_init() {

	// 1. ���� ���� - socket()
	server_socket.socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	// ���� �ּ� ���� - �ʱ�ȭ 
	SOCKADDR_IN server_addr = {};

	// ���� �ּ� ���� - �ּ� ü��
	server_addr.sin_family = AF_INET;

	// ���� �ּ� ���� - ��Ʈ
	// �ٸ���Ʈ�� ����
	server_addr.sin_port = htons(7777); // host to network (Big-endian ��ȯ) 

	// ���� �ּ� ���� - IP 
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY - ��� ȯ�濡���� ���� IP�� �ǹ� -> �� ��ǻ�Ϳ��� ���

	// 2. ������ ���Ͽ� �ּ� �ο� - bind()
	bind(server_socket.socket, (sockaddr*)&server_addr, sizeof(server_addr));

	// 3. ���� Ȱ��ȭ - Ŭ���̾�Ʈ ��û ��ٸ� - listen()
	listen(server_socket.socket, SOMAXCONN);

	server_socket.user = "server"; // ä�� ID : server
	cout << "Server On \n";

}

void add_client() {

	// ���� �ּ� ���� �ʱ�ȭ
	SOCKADDR_IN addr = {}; 
	int addrsize = sizeof(addr);

	// 8byte ���� 1024�� : �а� ���� ���� �뵵
	char buffer[MAX_BUFF_SIZE] = { };

	ZeroMemory(&addr, addrsize);

	SOCKET_INFO new_client = {};

	// client���� connect() ���� ������ ���ο� ���� ����
	// recv() �Ǹ� client ������ ���� �Ѿ��
	new_client.socket = accept(server_socket.socket, (sockaddr*)&addr, &addrsize);

	// client ������ ����ִ� ������ ���� : accept ��� , client���� send()�� recv()��
	recv(new_client.socket, buffer, MAX_BUFF_SIZE, 0);

	// ����� ������ ����
	new_client.user = string(buffer);
	string message = "[�ý���] " + new_client.user + " ���� �����߽��ϴ�.";

	// �������� ���ŵ� client ������ SOCKET_INFO ����� ���� ����ü ���Ϳ� ����
	socket_list.push_back(new_client);

	// client�� ������ ������ ���������� ������ ������ ����
	thread recv_thread(recv_msg, client_count);

	client_count++;

	cout << "[�ý���] ���� ������ ��: " << client_count << "��" << endl;
	send_msg(message.c_str());

	recv_thread.join();
}

// �������� client�� �޽��� ����
// send �Լ� c��Ÿ�� ���ڿ� const char* �ʿ�
void send_msg(const char* message)
{
	for (int i = 0; i < client_count; i++)
	{
		// ������ ���� char* ���� ����
		send(socket_list[i].socket, message, MAX_BUFF_SIZE, 0);
	}
}

void recv_msg(int idx) {

	char buffer[MAX_BUFF_SIZE];
	string message = "";

	while (true)
	{
		ZeroMemory(&buffer, MAX_BUFF_SIZE);

		// ���ŵ� ���
		if (recv(socket_list[idx].socket, buffer, MAX_BUFF_SIZE, 0) > 1)
		{
			message = socket_list[idx].user + ": " + buffer;
			cout << message << endl;
			// c_str() for send()
			send_msg(message.c_str());

		}

		else
		{
			message = "[�ý���] " + socket_list[idx].user + "���� �����߽��ϴ�.";
			cout << message << endl;
			send_msg(message.c_str());
			del_client(idx); // Ŭ���̾�Ʈ ���� ���� ����
			return;
		}
	}
}

void del_client(int idx)
{
	closesocket(socket_list[idx].socket);
	client_count--;
}