// �ζ� ��ȣ ��÷ ���α׷� �����
/*
(1) 1 ~ 45 ������ �� �� �������� 6�� ��ȣ�� �����ϴ� ���α׷�
(2) �ߺ� �Ұ���
(3) ������ �Ϸ�Ǹ� 6���� ��÷��ȣ ����ϱ�

*/

#include <iostream>
#include <cstdlib> // ���� ���� 
#include <ctime>

using namespace std;

int main()
{
	cout << "�ζ� ��÷ ���α׷�" << endl;

	srand(time(NULL));
	int randomnumber = rand();
	
	int num = randomnumber % 45 + 1;



	int* array = new int[5];

	for (int i = 0; i < 5; i++)
	{
		array[i] = num;
		if (array[i])
		{

		}
	}

	for (int i = 0; i < 5; i++)
	{
		cout << array[i] << ' ';
	}


}