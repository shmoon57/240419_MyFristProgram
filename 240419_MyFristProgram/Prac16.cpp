// 2차원 동적 배열 240426
/*
1) 사용자로 부터 x , y 2개 자연수 입력 받기
2) 사용자가 x,y 에 0 or 음수 입력시 에러 메시지 출력 후 재입력 받기
3) x * y 크기를 갖는 이차원 동적 배열 arr 선언
4) arr[0][0] 부터 arr[x][y] 까지 순서대로 1부터 x*y 저장
5) arr[0][0] 부터 arr[x][y] 까지 저장된 값 출력
*/

#include <iostream>
using namespace std;

void main()
{
	int x;
	int y;

	while (1)
	{
		// x , y 2개 자연수 입력 받기
		cout << "x를 입력하세요 : ";
		cin >> x;
		cout << "y를 입력하세요 : ";
		cin >> y;

		// 0 , 음수 입력시 에러메시지 출력
		if (x <= 0 || y <= 0)
		{
			cout << "x와 y 모두 양수를 입력해주세요.\n";
		}

		else
		{
			// x * y 크기를 갖는 이차원 동적 배열 arr 선언 
			int** arr = new int* [x];

			for (int i = 0; i < x; i++)
			{
				arr[i] = new int[y];
			}

			// arr[0][0] 부터 arr[x][y] 까지 저장된 값 출력
			int num = 1;
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < y; j++)
				{
					arr[i][j] = num;
					num++;
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}

			for (int i = 0; i < x; i++)
			{
				delete[] arr[i];
			}
				delete[] arr;
				break;
		}


	}
}