#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <conio.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

#define MAX_SIZE 1024
#define ENTER 13
#define BACK_SPACE 8

using std::cout;
using std::cin;
using std::endl;
using std::string;

SOCKET client_sock;
string my_id;

// MySQL Connector/C++ �ʱ�ȭ
sql::Driver* driver;
sql::Connection* con;
sql::Statement* stmt;
sql::PreparedStatement* pstmt;
sql::ResultSet* result;

// �����ͺ��̽� �ּ�, �����, ��й�ȣ
const string server = "tcp://127.0.0.1:3306";
const string username = "user";
const string password = "1234";

bool login(string id, string pw);
bool idCheck(string id);
void signup(string id, string pw);
void chatHistory();

int chat_recv();

int main() {

    // �����ͺ��̽� ���� ����
    try {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException& e) {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        exit(1);
    }

    // �����ͺ��̽� ����
    con->setSchema("chatting_project");

    // db �ѱ� ������ ���� ���� 
    stmt = con->createStatement();
    stmt->execute("set names euckr");
    if (stmt) { delete stmt; stmt = nullptr; }

    // �α��� �Ǵ� ȸ������
    while (1) {
        bool isSignup = false;

        cout << "----------------------------------------------------------" << endl;
        cout << "---------------------------�α���-------------------------" << endl;
        cout << "----------------------------------------------------------" << endl;

        while (1) {
            string id, pw;
            cout << "���̵� �Է��ϼ���: (���̵� ���� ��� signup �Է�) ";
            cin >> id;
            if (id == "signup") {
                isSignup = true;
                break;
            }

            // ��й�ȣ *ǥ��
            cout << "��й�ȣ�� �Է��ϼ���: ";
            while (1) {
                char c = _getch();
                if (c == ENTER) break;
                else if (c >= 33 && c <= 126) {
                    pw += c;
                    cout << "*";
                }
                else if (c == BACK_SPACE) {
                    pw = pw.substr(0, pw.size() - 1);
                    cout << "\b \b";
                }
            }
            cout << endl;

            if (login(id, pw)) {
                my_id = id;
                break;
            }
            else {
                cout << "���̵� �Ǵ� ��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
                cout << "----------------------------------------------------------" << endl;
            }
        }

        if (isSignup) {
            string id_in, pw_in;

            cout << "----------------------------------------------------------" << endl;
            cout << "--------------------------ȸ������------------------------" << endl;
            cout << "----------------------------------------------------------" << endl;

            while (1) {
                cout << "���̵� �Է��ϼ���: ";
                cin >> id_in;
                if (!idCheck(id_in)) break;
                cout << "�̹� �����ϴ� ���̵��Դϴ�." << endl;
            }
            cout << "��й�ȣ�� �Է��ϼ���: ";
            cin >> pw_in;
            signup(id_in, pw_in);
            continue;
        }
        break;
    }

    // �ܼ� â Ŭ����
    system("cls");

    // ä�� ���� �ҷ�����
    chatHistory();
    cout << "----------------------------------------------------------" << endl;

    WSADATA wsa;
    int code = WSAStartup(MAKEWORD(2, 2), &wsa);

    // code == 0 : ���� ����
    if (!code) {

        client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

        SOCKADDR_IN client_addr = {};
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(7777);
        InetPton(AF_INET, TEXT("127.0.0.1"), &client_addr.sin_addr);

        while (1) {
            if (!connect(client_sock, (SOCKADDR*)&client_addr, sizeof(client_addr))) {
                // ���� �� ������ ���̵� ����
                send(client_sock, my_id.c_str(), my_id.length(), 0);
                break;
            }
            cout << "Connecting..." << endl;
        }

        std::thread th2(chat_recv);

        while (1) {
            string text;
            std::getline(cin, text);
            const char* buffer = text.c_str(); // string���� char* Ÿ������ ��ȯ
            send(client_sock, buffer, strlen(buffer), 0);
        }
        th2.join();
        closesocket(client_sock);
    }

    WSACleanup();
    return 0;
}

// �α���
bool login(string id, string pw) {
    pstmt = con->prepareStatement("SELECT * FROM user WHERE id = ? AND pw = ?");
    pstmt->setString(1, id);
    pstmt->setString(2, pw);
    result = pstmt->executeQuery();

    bool isSuccess = false;

    while (result->next()) {
        isSuccess = true;
    }

    return isSuccess;
}

// ���̵� �ߺ� üũ
bool idCheck(string id) {
    pstmt = con->prepareStatement("SELECT * FROM user WHERE id = ?");
    pstmt->setString(1, id);
    result = pstmt->executeQuery();

    bool isExist = false;

    while (result->next()) {
        isExist = true;
    }

    return isExist;
}

// ȸ������
void signup(string id, string pw) {
    pstmt = con->prepareStatement("INSERT INTO user(id, pw) VALUES(?,?)");

    pstmt->setString(1, id);
    pstmt->setString(2, pw);
    pstmt->execute();
    cout << "ȸ�������� �Ϸ�Ǿ����ϴ�." << endl;
}

// ä�� ���� �ҷ�����
void chatHistory() {
    string from, to, msg;
    stmt = con->createStatement();
    result = stmt->executeQuery("SELECT * FROM chat");

    while (result->next()) {
        from = result->getString(2).c_str();
        to = result->getString(3).c_str();
        msg = result->getString(4).c_str();

        if (to == "") cout << from << " : " << msg << endl;
        else cout << from << "(" << to << ") : " << msg << endl;
    }

    delete stmt;
}

// �����κ��� ���� �޼��� ���
int chat_recv() {
    char buf[MAX_SIZE] = { };
    string msg;

    while (1) {
        ZeroMemory(&buf, MAX_SIZE);
        if (recv(client_sock, buf, MAX_SIZE, 0) > 0) {
            msg = buf;
            std::stringstream ss(msg);  // ���ڿ��� ��Ʈ��ȭ
            string user;
            ss >> user; // ��Ʈ���� ����, ���ڿ��� ���� �и��� ������ �Ҵ�
            if (user != my_id) cout << buf << endl; // ���� ���� �� �ƴ� ��쿡�� ����ϵ���.
        }
        else {
            cout << "Server Off" << endl;
            return -1;
        }
    }
}