// �ǽ� 3 string ����غ���

#include <iostream>
#include <string>

using namespace std;

void main()
{
	string s = "Codingon";

	// ù��° ���� �ҹ��ڷ� ���� :  .replace(n,k str2)
	cout << "ù��° ���� �ҹ��ڷ� ���� : " << s.replace(0, 1, "c") << endl;
	string replace_s = s.replace(0, 1, "c");


	// "ding" �̶�� �κ� ���ڿ� ��ȯ
	cout << "���ڹ�ȯ ��� : " << s.substr(2, 4) << endl;
   //codingon 
	// coooooon ���� ����
	cout << "���ں��� ��� : " << replace_s.replace(2, 4,"oooo") << endl; 

	// con ���� ����
	cout << "���ں��� ���(2) : " << replace_s.erase(2, 5) << endl;

}
