// 실습 8 vector 증복삭제

#include <iostream>
#include <vector>
#include <algorithm> // sort , 

using namespace std;

void main()
{
	vector<int> myVector = { 10,20,30,20,40,10,50 };

	cout << "기존 벡터 값 :";

	cout << '{';
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << ' ' << myVector.at(i) << ' ';
	}
	cout << '}' << endl << endl;

	cout << "중복삭제 적용 이후 :";
	
	// sort 정렬 필요 , velog 참고
	sort(myVector.begin(), myVector.end());
	
	// erase , unique 함수 사용
	myVector.erase(unique(myVector.begin(), myVector.end()), myVector.end());

	cout << '{';
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << ' ' << myVector.at(i) << ' ';
	}
	cout << '}';
}