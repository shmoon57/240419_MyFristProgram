// Winsock ���̺귯�� ����
#pragma comment(lib, "ws2_32.lib") 

#include <WinSock2.h> 

#include <string>
#include <iostream>
#include <thread>
#include <vector>

#define MAX_BUFF_SIZE 1024 // ������ ���� : ����
#define PORT 7777

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::thread;


SOCKET serverSocket;
SOCKET clientSocket;

void handleClient(SOCKET client_socket);

int main() {

	// for WSAStartup() : Windows Socket API �ʱ�ȭ
	WSADATA wsaData;

	int code = WSAStartup(MAKEWORD(2, 2), &wsaData);

	// �ʱ�ȭ ���� : Winsock ����غ�
	if (code == 0)
	{

		// 1. ���� ���� - socket()
		serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

		// ���� �ּ� ���� - �ʱ�ȭ 
		SOCKADDR_IN server_addr = {};

		// ���� �ּ� ���� - �ּ� ü��
		server_addr.sin_family = AF_INET;

		// ���� �ּ� ���� - ��Ʈ
		server_addr.sin_port = htons(PORT); // host to network (Big-endian ��ȯ) 

		// ���� �ּ� ���� - IP 
		server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY - ��� ȯ�濡���� ���� IP�� �ǹ� -> �� ��ǻ�Ϳ��� ���

		// 2. ������ ���Ͽ� �ּ� �ο� - bind()
		bind(serverSocket, (sockaddr*)&server_addr, sizeof(server_addr));

		// 3. ���� Ȱ��ȭ - Ŭ���̾�Ʈ ��û ��ٸ� - listen()
		listen(serverSocket, SOMAXCONN);


		cout << "Server is listening on port" << PORT << endl;

		while (true)
		{
			// client adress ����
			SOCKADDR_IN client_addr = {}; // ���� �ּ� ���� �ʱ�ȭ
			int client_addrsize = sizeof(client_addr);

			// 8byte ���� 1024�� : �а� ���� ���� �뵵
			char buffer[MAX_BUFF_SIZE] = { };

			ZeroMemory(&client_addr, client_addrsize);

			SOCKET clientSocket = {};

			// client���� connect() ���� ������ ���ο� ���� ����
			clientSocket = accept(serverSocket, (sockaddr*)&client_addr, &client_addrsize);

			// Ŭ���̾�Ʈ ��û ó��
			handleClient(clientSocket);
		}

	}

	// �ʱ�ȭ ���� 
	else
	{
		cout << "���α׷� ����. (Error Code: " << code << ")";
	}


	// ����
	closesocket(serverSocket);
	WSACleanup();

	return 0;
}

void handleClient(SOCKET clientSocket) {

	// C++������ ��Ʈ��ũ ������ ���� ���� �����͸� char �迭�� ó��
	char buffer[MAX_BUFF_SIZE];

	// client ������ ����ִ� ������ ���� : accept ��� , client���� send()�� recv()��
	// ������ �޾ƿ� �������� ���� ����
	int byteReceived = recv(clientSocket, buffer, MAX_BUFF_SIZE, 0);

	/* C�� C++���� ���ڿ��� �� ����('\0')�� ������ �մϴ�.
	�̴� ���ڿ��� ���� ��Ÿ����, ���ڿ� �Լ����� �� ���ڸ� ���� �������� ó���� �ϵ��� �մϴ�.
	��Ʈ��ũ ��ſ��� recv �Լ��� ����Ͽ� �����͸� ������, ���� �����ʹ� �ܼ��� ���ڿ��� ����ϱ⿡ �ռ� �� ����('\0')�� ������ �ʽ��ϴ�.
	���� ���� �������� ���� ���� �� ����('\0')�� �߰�����߸� C ��Ÿ�� ���ڿ� �Լ����� �̸� �ùٸ��� ó���� �� �ֽ��ϴ�.
	*/

	buffer[byteReceived] = '\0';
	cout << "Received message : " << buffer << endl;

	// Ŭ���̾�Ʈ���� ���� ���� C# - String Ÿ������ �ؽ�Ʈ ������ ǥ�� 
	string response = "Login successful!";
	send(clientSocket, response.c_str(), response.size(), 0);

	closesocket(clientSocket);
}

