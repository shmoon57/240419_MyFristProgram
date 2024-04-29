// 실습 1 list 사용

#include <iostream>
#include <list>

using namespace std;

void main()
{
	// 리스트 (myList) 생성
	list<int> myList = { 5,4,3,4,2,1,1 };

	// 리스트 제어용 반복자 생성
	list<int>::iterator iter = myList.begin();

	// 4의 개수 출력
	int number = 0;

	for (iter = myList.begin(); iter != myList.end(); iter++)
	{
		if (*iter == 4)
		{
			number++;
		}
	}
	cout << "4의 개수는 : " << number << endl;

	// sort 사용 - 오름차순 정리
	myList.sort();
	
	cout << endl<< "sort() 함수를 사용한 결과"<< endl;
	for (iter = myList.begin(); iter != myList.end(); iter++)
	{
		cout << *iter<< " ";
	}

	cout << endl;

	// unique 사용 - 중복 요소 제거
	myList.unique();

	cout << endl << "unique() 함수를 사용한 결과" << endl;
	for (iter = myList.begin(); iter != myList.end(); iter++)
	{
		cout << *iter << " ";
	}

	cout << endl << endl;

	// {6, 7} 추가 및 출력
	list<int> addList1 = { 6,7 };
	myList.merge(addList1);
	
	cout << "리스트에 {6, 7}추가 \n";

	for (list<int>::iterator iter = myList.begin(); iter != myList.end(); ++iter) 
	{
		cout << *iter << " ";
	}

	cout << "\n\n";

	// {0} 추가 및 출력
	list<int> addList2 = { 0 };
	myList.merge(addList2);

	cout << "리스트에 {0}추가 \n";

	for (list<int>::iterator iter = myList.begin(); iter != myList.end(); ++iter) 
	{
		cout << *iter << " ";
	}

}
