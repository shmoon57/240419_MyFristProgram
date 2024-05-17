//  실습 1 string 사용해보기

#include <iostream>
#include <string>

using namespace std;

void main()
{
	string s = "Police say two people are suspected of trying to create a shortcut for their construction work.The two have been detained and the case is under further investigation.The 38 - year - old man and 55 - year - old woman were working near the affected area, the 32nd Great Wall.";

	// s.size() : 문자열 길이 함수 사용
	cout << "s 문자열 길이 는 : " << s.size() << endl;
	
	//s[99] : 100 번쨰 문자 출력
	cout << "s의 100번째 문자는 : " << s[99] << endl;

	// "two" 라는 문자가 처음 나오는 index 
	string ss = "two";
	cout << "two 라는 문자가 처음 나오는 인덱스는 : " << s.find(ss) << endl;

	// "two" 라는 문자가 두번쨰 나오는 index
	cout << "two 라는 문자가 두번째 나오는 인덱스는 : " << s.find(ss,12) << endl;
}