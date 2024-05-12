// 포인터 실습

#include <iostream>
#define Size 5

using namespace std;

// 함수의 배열을 바꿔주는 reverse 함수 
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
	// 배열 자체 포인터 : (&)array
	reverse(array);

	for (int i = 0; i < Size ; i++)
	{
		cout << array[i];
	}
	
}