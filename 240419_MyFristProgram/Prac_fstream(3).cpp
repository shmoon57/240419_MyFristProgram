// 실습 2 회원 명부를 응용한 로그인 기능
/*
회원 가입 기능 추가
아이디 중복 불가능
비밀번호 패턴을 일반적인 홈페이지 가입과 같이 대문자, 소문자, 특수문자 포함 8자리 이상 20글자 미만으로 설정
해당 계정으로 로그인까지!
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string input_name;
	string input_pw;
	string input_phone_num;
	vector<string> info;
	bool Login = false;
	
	// 파일을 불러오는 과정
	ifstream info_file("member.txt"); // member.txt 파일을 담을 변수 선언과 동시에 열기
	string str;

	// 띄어쓰기 전까지 읽고 str이라는 변수에 저장
	while (info_file >> str)
	{
		info.push_back(str);
	}

	// 파일 닫기
	info_file.close();

	// 입력부
	cout << "이름을 입력하세요. ";
	cin >> input_name;
	cout << "비번을 입력하세요. ";
	cin >> input_pw;
	cout << endl;
	
	// 검사 Part : for문을 돌며 벡터에 저장된 인덱스 값 비교
	for (int i = 0; i < info.size(); i++)
	{
		if (input_name == info.at(i)) 
		{
			if (input_pw == info.at(i + 1))
			{
				Login = true;
				break;
			}
		}
	}
	
	if (Login == true)
	{
		cout << "로그인 성공" << endl;
	}

	else
	{
		cout << "로그인 실패" << endl;
	}

}
	
	

