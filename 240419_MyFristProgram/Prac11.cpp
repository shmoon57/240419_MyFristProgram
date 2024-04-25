// 실습 1 사칙연산 함수 만들기

#include <iostream>

using namespace std;

int add(int num1,int num2)
{
	return num1 + num2; 
}

int sub(int num1, int num2)
{
	return num1 >= num2 ? (num1 - num2) : (num2 - num1); // 삼항 연산자 사용
}

int mul(int num1, int num2)
{
	return num1 * num2;
}

/*double devide(int num1, int num2)
{
	return num1 >= num2 ? (num1 / num2) : (num2 / num1); // 정수 정수 연산 -> 정수 
}*/

float devide (int num1, int num2)
{
	float fn1 = num1; //강제 실수형 변환 ( 정수 -> 실수 )
	float fn2 = num2; 

	return fn1 >= fn2 ? (fn1 / fn2) : (fn2 / fn1);
}

int main()
{
	int num1, num2;
	
	cout << "첫번째 값을 입력해주세요 : ";
	cin >> num1;

	cout << "두번째 값을 입력해주세요 : ";
	cin >> num2;

	int addResult = add(num1, num2); 
	int subResult = sub(num1, num2);
	int mulResult = mul(num1, num2);
	double devideResult = devide(num1, num2); 

	cout << " 더하기 : "<< addResult << endl;
	cout << " 빼기 : " << subResult << endl;
	cout << " 곱하기 : " << mulResult << endl;
	cout << " 나누기 : " << devideResult << endl;

	return 0;
}