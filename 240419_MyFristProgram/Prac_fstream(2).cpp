/* 
실습 1 회원 명부 작성하기

추가 내용
1. "사용자이름 비밀번호" 양식과는 다르게 값을 1개만 또는 3개 이상 입력할 경우 오류 메시지 + 다시 입력 가능하도록
2. 비밀번호는 6자리 이상 ~ 18자리 미만으로 적도록
3. 정상적으로 입력 받았을 경우에만 파일에 쓰기!

- 새록님 코드 참고 해보기
*/

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
	
	read_file.close();

}