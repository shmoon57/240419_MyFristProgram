#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string input_name;
	string input_pw;
	vector<string> info_name;
	vector<string> info_pw;

	cout << "3명의 회원에 대한 이름 비밀 번호를 순차적으로 입력하세요 Ex) 홍길동 134" <<  endl;

	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << "번째 회원 : ";
		cin >> input_name >> input_pw;
		info_name.push_back(input_name);
		info_pw.push_back(input_pw);
		cout << endl;
	}
	// 사용자로부터 입력된 정보를  member.txt에 기록
	ofstream write_file;
	write_file.open("member.txt");

	for (int i = 0; i < 3; i++)
	{
		write_file << info_name[i] << " "<< info_pw[i] << endl;
	}

	write_file.close();

	cout << "----------회원 명부 파일 읽기----------" << endl;
	
	// member.txt에 저장된 회원 명부 출력

	ifstream read_file;
	read_file.open("member.txt");
	string line;
	
	while (getline(read_file, line))
	{
		cout << line << endl;
	}
	



}