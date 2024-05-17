// 실습 3 로그인 성공시 전화번호 저장하기


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
	cout << "비밀번호를 입력하세요. ";
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
		cout << "전화번호를 입력해주세요 ex) 010-0000-0000 : ";
		cin >> input_phone_num;

		ifstream phone_num_file("member_tel.txt");
		vector<string> tel_info;	
		string member_tel_line;

		// 0. input_name -> tel_info에 있는지 체크
		// 홍길동 010-1234-56578
		
		// 2. 있다 -> member_tel.txt 쓰기로 열기
		// 2-1. 기본 벡터에서 이름을 찾아서 그 벡터 요소의 전화번호만 변경 string 함수
		// 2-2. 벡터 전체를 파일에 쓰기
		if (tel_info.size() > 0)
		{
			for (int i = 0; i < tel_info.size(); i++)
			{
				// 1. tel.inpo 벡터를 돌며 input_name이 member_tel.txt에 있을 경우 
				if (tel_info[i].find(input_name) == 0) 
				{
					// string 함수, 문자열 삭제, 문자열 추가
					// 1. 전화번호 삭제
					// 2. 새 전화번호 추가
					int phone_idx = tel_info[i].find(' ') + 1; // 전화번호가 시작하는 인덱스
					tel_info[i].erase(phone_idx, 13);
					tel_info[i].insert(phone_idx, " ");
					tel_info[i].insert(phone_idx + 1, input_phone_num);
				}

			}
			// 벡터 전체를 파일에 쓰기
			ofstream new_phone_num_file("member_tel.txt");

			for (int i = 0; i < tel_info.size(); i++)
			{
				new_phone_num_file << tel_info.at(i) << endl;
			}

			new_phone_num_file.close();
		}			
		else // 2. tel.inpo 벡터를 돌며 input_name이 member_tel.txt에 없을 경우
		{
			// 2-1-1) 기존 벡터(tel_info) 새로운 이름 + 전화번호 추가 
			while (getline(phone_num_file, member_tel_line)) // member_tel.txt 한 줄 : member_tel_line에 저장하기
			{
				tel_info.push_back(member_tel_line);
			}
			phone_num_file.close();
		
			// 2-1-2) tel_info 벡터에 새롭게 입력받은 사용자 이름 + " " + 전화번호 추가
			tel_info.push_back(input_name + " " + input_phone_num);
				
			// 2-2) 벡터 전체를 파일에 쓰기
			ofstream new_phone_num_file("member_tel.txt");

			for (int i = 0; i < tel_info.size(); i++)
			{
				new_phone_num_file << tel_info.at(i) << endl;
			}
				
			new_phone_num_file.close();
		}
	
	}

	else
	{
		cout << "로그인 실패" << endl;
	}


}



