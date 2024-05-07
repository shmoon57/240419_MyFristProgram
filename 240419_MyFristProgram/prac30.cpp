#include <iostream>
#include <fstream> // 파일 읽고 쓰기 위한 기능 제공 헤더
#include <vector>
#include <string> // getline 사용 위한 라이브러리

using namespace std;

int main()
{
	ifstream in_file1; // 파일을 담을 file1 변수 생성
	in_file1.open("test1.txt"); // test1.txt 파일 열기
	
	string line;

	vector<string> Test1Content;
	
	// 엔터까지 읽어서 변수 line에 저장 
	while (getline(in_file1, line))
	{
		Test1Content.push_back(line);
	} 

	/* pushback 확인 여부
	for (int i = 0; i < Test1Content.size(); i++)
	{
		cout << Test1Content.at(i) << endl;
	}
	*/

	in_file1.close();

	ofstream out_file1("output.txt"); // output.txt 파일 생성
	
	for (int i = Test1Content.size()-1; i >= 0 ; i--)
	{
		out_file1 <<  Test1Content[i] << endl;
	}
 
	out_file1.close();

	return 0;

}