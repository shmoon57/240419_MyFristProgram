// ������ �ǽ�

#include <iostream>
#define Size 5

using namespace std;

// �Լ��� �迭�� �ٲ��ִ� reverse �Լ� 
void reverse(int * array)
{
	for (int i = 0; i < Size / 2; i++)
	{
		int temp = array[i];
		array[i] = array[Size - i - 1]; 
		array[Size - i - 1] = temp;		
	}
}

int main()
{
	int array[Size] = { 1,2,3,4,5 };
	// �迭 ��ü ������ : (&)array
	reverse(array);

	for (int i = 0; i < Size ; i++)
	{
		cout << array[i];
	}
	
}