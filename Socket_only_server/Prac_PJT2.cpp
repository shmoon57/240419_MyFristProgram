// Winsock ���̺귯�� ����
#pragma comment(lib, "ws2_32.lib") 
	
#include <WinSock2.h> 

#include <string>
#include <iostream>
#include <thread>
#include <vector>


// MySQL ���� �������
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#define MAX_BUFF_SIZE 1024 // ������ ���� : ����
#define PORT 7777

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::thread;

// ����ü�� ���� �ʿ�
SOCKET serverSocket;
SOCKET clientSocket;

// Ŭ���̾�Ʈ ���� �޴� �Լ�
void handleClient(SOCKET client_socket);
void insertDataToDatabase(float data);


int main() {

	// for WSAStartup() : Windows Socket API �ʱ�ȭ
	WSADATA wsaData;

	int code = WSAStartup(MAKEWORD(2, 2), &wsaData);

	// �ʱ�ȭ ���� : Winsock ����غ�
	if (code == 0)
	{
		// 1. ���� ���� - socket()
		serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
		
		// 2. ������ ���Ͽ� �ּ� �ο� - bind()
		// ���� �ּ� ���� - �ʱ�ȭ 
		SOCKADDR_IN server_addr = {};
		// ���� �ּ� ���� - �ּ� ü��
		server_addr.sin_family = AF_INET;
		// ���� �ּ� ���� - ��Ʈ
		server_addr.sin_port = htons(PORT); // host to network (Big-endian ��ȯ) 
		// ���� �ּ� ���� - IP 
		server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY - ��� ȯ�濡���� ���� IP�� �ǹ� -> �� ��ǻ�Ϳ��� ���
		
		bind(serverSocket, (sockaddr*)&server_addr, sizeof(server_addr));

		// 3. ���� Ȱ��ȭ - Ŭ���̾�Ʈ ��û ��ٸ� - listen()
		listen(serverSocket, SOMAXCONN);

		cout << "������ ��Ʈ���� ���� �� �Դϴ� (��Ʈ : " << PORT << ')' << endl;

		// accept() ����
		while (true)
		{
			
			SOCKADDR_IN client_addr = {}; // client ���� �ּ� ���� - �ʱ�ȭ
			int client_addrsize = sizeof(client_addr);

			// 8byte ���� 1024�� : �а� ���� ���� �뵵
			char buffer[MAX_BUFF_SIZE] = { };

			ZeroMemory(&client_addr, client_addrsize);

			SOCKET clientSocket = {};

			// client���� connect() ���� ������ ���ο� ���� ����
			clientSocket = accept(serverSocket, (sockaddr*)&client_addr, &client_addrsize);

			// client ����  ���� 
			if (clientSocket != INVALID_SOCKET) {
				cout << "Client connected!" << endl;

				//thread clientThread(handleClient, clientSocket);
				handleClient(clientSocket);

				// ���� ������� �и��Ͽ� ���������� ����
				//clientThread.detach();  
			}
			else {
				cout << "Client connection failed!" << endl;
			}
			
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

	while (true)
	{
		// client ������ ����ִ� ������ ���� : accept ��� , client���� send()�� recv()��
		// ������ �޾ƿ� �������� ���� ����
		int byteReceived = recv(clientSocket, buffer, MAX_BUFF_SIZE, 0);

		// ���� case
		if (byteReceived == SOCKET_ERROR)
		{
			cout << "������ �߻��߽��ϴ�. \n";
			closesocket(clientSocket);
			break;
		}

		// Ŭ���̾�Ʈ ���� case
		if (byteReceived == 0)
		{
			cout << "Ŭ���̾�Ʈ���� ������ ����Ǿ����ϴ�.\n";
			closesocket(clientSocket);
			break;
		}
		
		// ���� case
		/* C�� C++���� ���ڿ��� �� ����('\0')�� ������ �մϴ�.
		�̴� ���ڿ��� ���� ��Ÿ����, ���ڿ� �Լ����� �� ���ڸ� ���� �������� ó���� �ϵ��� �մϴ�.
		��Ʈ��ũ ��ſ��� recv �Լ��� ����Ͽ� �����͸� ������, ���� �����ʹ� �ܼ��� ���ڿ��� ����ϱ⿡ �ռ� �� ����('\0')�� ������ �ʽ��ϴ�.
		���� ���� �������� ���� ���� �� ����('\0')�� �߰�����߸� C ��Ÿ�� ���ڿ� �Լ����� �̸� �ùٸ��� ó���� �� �ֽ��ϴ�.
		*/

		buffer[byteReceived] = '\0';

		cout << "Recieved Data : " << buffer << endl;

		// float ��ȯ
		float buffer_f = std::stof(buffer);

		// DB�� ����
		insertDataToDatabase(buffer_f);

		// Ŭ���̾�Ʈ���� ���� ���� C# - String Ÿ������ �ؽ�Ʈ ������ ǥ�� 
		string response = "Login successful!";
		send(clientSocket, response.c_str(), response.size(), 0);
		
	}
}

	// ��� ����
void insertDataToDatabase(float data) {
	try {
		sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
		std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "user", "1234"));
		con->setSchema("AcCumsum");

		std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("INSERT INTO Power (aircon_p, refri_p) VALUES (?,?)"));
		pstmt->setDouble(1, data);
		pstmt->setDouble(2, data);
		pstmt->executeUpdate();
	}
	catch (sql::SQLException& e) {
		std::cerr << "MySQL error: " << e.what() << std::endl;
	}
}

