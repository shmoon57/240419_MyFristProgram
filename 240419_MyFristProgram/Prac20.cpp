// �ǽ� 8 vector ��������

#include <iostream>
#include <vector>
#include <algorithm> // sort , 

using namespace std;

void main()
{
	vector<int> myVector = { 10,20,30,20,40,10,50 };

	cout << "���� ���� �� :";

	cout << '{';
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << ' ' << myVector.at(i) << ' ';
	}
	cout << '}' << endl << endl;

	cout << "�ߺ����� ���� ���� :";
	
	// sort ���� �ʿ� , velog ����
	sort(myVector.begin(), myVector.end());
	
	// erase , unique �Լ� ���
	myVector.erase(unique(myVector.begin(), myVector.end()), myVector.end());

	cout << '{';
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << ' ' << myVector.at(i) << ' ';
	}
	cout << '}';
}