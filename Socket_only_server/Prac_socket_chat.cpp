// Winsock 라이브러리 연결
#pragma comment(lib, "ws2_32.lib") 

#include <WinSock2.h> 

#include <string>
#include <iostream>
#include <thread>
#include <vector>

#define MAX_BUFF_SIZE 1024 // 데이터 공간 : 버퍼
#define MAX_CLIENT 3

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::thread;

struct SOCKET_INFO
{
	SOCKET socket; // 소켓 자료형 변수
	string user;

};

// client 정보를 받을 벡터 선언
vector<SOCKET_INFO> socket_list;

SOCKET_INFO server_socket;

int client_count = 0;

// 서버 초기화, for socket() ~ listen()
void server_init();
// 1개의 클라이언트로 부터 정보를 얻음
void add_client();
void send_msg(const char* message);
void recv_msg(int idx);
void del_client(int idx);


int main() {

	// for WSAStartup() : Windows Socket API 초기화
	WSADATA wsa;

	int code = WSAStartup(MAKEWORD(2, 2), &wsa);

	// 초기화 성공 : Winsock 사용준비
	if (code == 0)
	{
		server_init();

		// 배열로 스레드 객체 3개 생성
		thread client_threads[MAX_CLIENT];

		for (int i = 0; i < MAX_CLIENT; i++)
		{
			client_threads[i] = thread(add_client);
		}

		// 들어오는 메세지를 돌려보내는 역할?
		while (true)
		{
			string text, message = "";

			// 어디로부터 getline 되는 것인가, 사용자 입력은 아닐테고
			// 사용자 입력이 맞다, 서버랑 서로 주고받는 구조
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

	// 초기화 실패 
	else
	{
		cout << "프로그램 종료. (Error Code: " << code << ")";
	}

	WSACleanup();

	return 0;
}

// 서버 초기화
void server_init() {

	// 1. 소켓 생성 - socket()
	server_socket.socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	// 소켓 주소 정의 - 초기화 
	SOCKADDR_IN server_addr = {};

	// 소켓 주소 정의 - 주소 체계
	server_addr.sin_family = AF_INET;

	// 소켓 주소 정의 - 포트
	// 다른포트로 연결
	server_addr.sin_port = htons(7777); // host to network (Big-endian 전환) 

	// 소켓 주소 정의 - IP 
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY - 어느 환경에서든 나의 IP를 의미 -> 내 컴퓨터에서 통신

	// 2. 생성된 소켓에 주소 부여 - bind()
	bind(server_socket.socket, (sockaddr*)&server_addr, sizeof(server_addr));

	// 3. 소켓 활성화 - 클라이언트 요청 기다림 - listen()
	listen(server_socket.socket, SOMAXCONN);

	server_socket.user = "server"; // 채팅 ID : server
	cout << "Server On \n";

}

void add_client() {

	// 소켓 주소 정의 초기화
	SOCKADDR_IN addr = {}; 
	int addrsize = sizeof(addr);

	// 8byte 공간 1024개 : 읽고 쓰기 위한 용도
	char buffer[MAX_BUFF_SIZE] = { };

	ZeroMemory(&addr, addrsize);

	SOCKET_INFO new_client = {};

	// client에서 connect() 이후 서버에 새로운 소켓 생성
	// recv() 되면 client 정보가 같이 넘어옴
	new_client.socket = accept(server_socket.socket, (sockaddr*)&addr, &addrsize);

	// client 정보가 들어있는 소켓을 수신 : accept 대기 , client에서 send()시 recv()함
	recv(new_client.socket, buffer, MAX_BUFF_SIZE, 0);

	// 사용자 정보를 보냄
	new_client.user = string(buffer);
	string message = "[시스템] " + new_client.user + " 님이 입장했습니다.";

	// 소켓으로 수신된 client 정보를 SOCKET_INFO 사용자 설정 구조체 벡터에 저장
	socket_list.push_back(new_client);

	// client가 보내는 소켓을 지속적으로 수신할 스레드 생성
	thread recv_thread(recv_msg, client_count);

	client_count++;

	cout << "[시스템] 현재 접속자 수: " << client_count << "명" << endl;
	send_msg(message.c_str());

	recv_thread.join();
}

// 서버에서 client로 메시지 보냄
// send 함수 c스타일 문자열 const char* 필요
void send_msg(const char* message)
{
	for (int i = 0; i < client_count; i++)
	{
		// 소켓을 통해 char* 값을 전달
		send(socket_list[i].socket, message, MAX_BUFF_SIZE, 0);
	}
}

void recv_msg(int idx) {

	char buffer[MAX_BUFF_SIZE];
	string message = "";

	while (true)
	{
		ZeroMemory(&buffer, MAX_BUFF_SIZE);

		// 수신된 경우
		if (recv(socket_list[idx].socket, buffer, MAX_BUFF_SIZE, 0) > 1)
		{
			message = socket_list[idx].user + ": " + buffer;
			cout << message << endl;
			// c_str() for send()
			send_msg(message.c_str());

		}

		else
		{
			message = "[시스템] " + socket_list[idx].user + "님이 퇴장했습니다.";
			cout << message << endl;
			send_msg(message.c_str());
			del_client(idx); // 클라이언트 소켓 연결 종료
			return;
		}
	}
}

void del_client(int idx)
{
	closesocket(socket_list[idx].socket);
	client_count--;
}