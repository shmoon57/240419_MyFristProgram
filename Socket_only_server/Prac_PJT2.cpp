// Winsock 라이브러리 연결
#pragma comment(lib, "ws2_32.lib") 

#include <WinSock2.h> 

#include <string>
#include <iostream>
#include <thread>
#include <vector>

#define MAX_BUFF_SIZE 1024 // 데이터 공간 : 버퍼
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

	// for WSAStartup() : Windows Socket API 초기화
	WSADATA wsaData;

	int code = WSAStartup(MAKEWORD(2, 2), &wsaData);

	// 초기화 성공 : Winsock 사용준비
	if (code == 0)
	{

		// 1. 소켓 생성 - socket()
		serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

		// 소켓 주소 정의 - 초기화 
		SOCKADDR_IN server_addr = {};

		// 소켓 주소 정의 - 주소 체계
		server_addr.sin_family = AF_INET;

		// 소켓 주소 정의 - 포트
		server_addr.sin_port = htons(PORT); // host to network (Big-endian 전환) 

		// 소켓 주소 정의 - IP 
		server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY - 어느 환경에서든 나의 IP를 의미 -> 내 컴퓨터에서 통신

		// 2. 생성된 소켓에 주소 부여 - bind()
		bind(serverSocket, (sockaddr*)&server_addr, sizeof(server_addr));

		// 3. 소켓 활성화 - 클라이언트 요청 기다림 - listen()
		listen(serverSocket, SOMAXCONN);


		cout << "Server is listening on port" << PORT << endl;

		while (true)
		{
			// client adress 정보
			SOCKADDR_IN client_addr = {}; // 소켓 주소 정의 초기화
			int client_addrsize = sizeof(client_addr);

			// 8byte 공간 1024개 : 읽고 쓰기 위한 용도
			char buffer[MAX_BUFF_SIZE] = { };

			ZeroMemory(&client_addr, client_addrsize);

			SOCKET clientSocket = {};

			// client에서 connect() 이후 서버에 새로운 소켓 생성
			clientSocket = accept(serverSocket, (sockaddr*)&client_addr, &client_addrsize);

			// 클라이언트 요청 처리
			handleClient(clientSocket);
		}

	}

	// 초기화 실패 
	else
	{
		cout << "프로그램 종료. (Error Code: " << code << ")";
	}


	// 종료
	closesocket(serverSocket);
	WSACleanup();

	return 0;
}

void handleClient(SOCKET clientSocket) {

	// C++에서는 네트워크 소켓을 통해 받은 데이터를 char 배열로 처리
	char buffer[MAX_BUFF_SIZE];

	// client 정보가 들어있는 소켓을 수신 : accept 대기 , client에서 send()시 recv()함
	// 실제로 받아온 데이터의 길이 저장
	int byteReceived = recv(clientSocket, buffer, MAX_BUFF_SIZE, 0);

	/* C와 C++에서 문자열은 널 문자('\0')로 끝나야 합니다.
	이는 문자열의 끝을 나타내며, 문자열 함수들이 이 문자를 만날 때까지만 처리를 하도록 합니다.
	네트워크 통신에서 recv 함수를 사용하여 데이터를 받으면, 받은 데이터는 단순히 문자열로 사용하기에 앞서 널 문자('\0')로 끝나지 않습니다.
	따라서 받은 데이터의 끝에 직접 널 문자('\0')을 추가해줘야만 C 스타일 문자열 함수들이 이를 올바르게 처리할 수 있습니다.
	*/

	buffer[byteReceived] = '\0';
	cout << "Received message : " << buffer << endl;

	// 클라이언트에게 응답 전송 C# - String 타입으로 텍스트 데이터 표현 
	string response = "Login successful!";
	send(clientSocket, response.c_str(), response.size(), 0);

	closesocket(clientSocket);
}

