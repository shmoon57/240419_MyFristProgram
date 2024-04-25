// 포인터 실습

#include <iostream>
#define Size 5;

using namespace std;

void reverse(int * array)
{
	for (int i = 0; i < 5 / 2; i++)
	{
		int temp = array[i];
		array[i] = array[5 - i - 1]; 
		array[5 - i - 1] = temp;		
	}
}

/*
*/


int main()
{

	int array[5] = { 1,2,3,4,5 };

	reverse(array);

	for (int i = 0; i < 5 ; i++)
	{
		cout << array[i];
	}
	
	
}