// 로또 번호 추첨 프로그램 만들기
/*
(1) 1 ~ 45 사이의 수 중 랜덤으로 6개 번호를 추출하는 프로그램
(2) 중복 불가능
(3) 추출이 완료되면 6개의 당첨번호 출력하기

*/

#include <iostream>
#include <cstdlib> // 난수 생성 
#include <ctime>

using namespace std;

int main()
{
	cout << "로또 추첨 프로그램" << endl;

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