//  �ǽ� 1 string ����غ���

#include <iostream>
#include <string>

using namespace std;

void main()
{
	string s = "Police say two people are suspected of trying to create a shortcut for their construction work.The two have been detained and the case is under further investigation.The 38 - year - old man and 55 - year - old woman were working near the affected area, the 32nd Great Wall.";

	// s.size() : ���ڿ� ���� �Լ� ���
	cout << "s ���ڿ� ���� �� : " << s.size() << endl;
	
	//s[99] : 100 ���� ���� ���
	cout << "s�� 100��° ���ڴ� : " << s[99] << endl;

	// "two" ��� ���ڰ� ó�� ������ index 
	string ss = "two";
	cout << "two ��� ���ڰ� ó�� ������ �ε����� : " << s.find(ss) << endl;

	// "two" ��� ���ڰ� �ι��� ������ index
	cout << "two ��� ���ڰ� �ι�° ������ �ε����� : " << s.find(ss,12) << endl;
}