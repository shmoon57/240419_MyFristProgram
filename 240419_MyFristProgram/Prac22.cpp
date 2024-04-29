// �ǽ� 1 list ���

#include <iostream>
#include <list>

using namespace std;

void main()
{
	// ����Ʈ (myList) ����
	list<int> myList = { 5,4,3,4,2,1,1 };

	// ����Ʈ ����� �ݺ��� ����
	list<int>::iterator iter = myList.begin();

	// 4�� ���� ���
	int number = 0;

	for (iter = myList.begin(); iter != myList.end(); iter++)
	{
		if (*iter == 4)
		{
			number++;
		}
	}
	cout << "4�� ������ : " << number << endl;

	// sort ��� - �������� ����
	myList.sort();
	
	cout << endl<< "sort() �Լ��� ����� ���"<< endl;
	for (iter = myList.begin(); iter != myList.end(); iter++)
	{
		cout << *iter<< " ";
	}

	cout << endl;

	// unique ��� - �ߺ� ��� ����
	myList.unique();

	cout << endl << "unique() �Լ��� ����� ���" << endl;
	for (iter = myList.begin(); iter != myList.end(); iter++)
	{
		cout << *iter << " ";
	}

	cout << endl << endl;

	// {6, 7} �߰� �� ���
	list<int> addList1 = { 6,7 };
	myList.merge(addList1);
	
	cout << "����Ʈ�� {6, 7}�߰� \n";

	for (list<int>::iterator iter = myList.begin(); iter != myList.end(); ++iter) 
	{
		cout << *iter << " ";
	}

	cout << "\n\n";

	// {0} �߰� �� ���
	list<int> addList2 = { 0 };
	myList.merge(addList2);

	cout << "����Ʈ�� {0}�߰� \n";

	for (list<int>::iterator iter = myList.begin(); iter != myList.end(); ++iter) 
	{
		cout << *iter << " ";
	}

}
