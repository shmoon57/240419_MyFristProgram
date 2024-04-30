// 실습 3 string 사용해보기

#include <iostream>
#include <string>

using namespace std;

void main()
{
	string s = "Codingon";

	// 첫번째 문자 소문자로 변경 :  .replace(n,k str2)
	cout << "첫번째 문자 소문자로 변경 : " << s.replace(0, 1, "c") << endl;
	string replace_s = s.replace(0, 1, "c");


	// "ding" 이라는 부분 문자열 반환
	cout << "문자반환 결과 : " << s.substr(2, 4) << endl;
   //codingon 
	// coooooon 으로 변경
	cout << "문자변경 결과 : " << replace_s.replace(2, 4,"oooo") << endl; 

	// con 으로 변경
	cout << "문자변경 결과(2) : " << replace_s.erase(2, 5) << endl;

}
