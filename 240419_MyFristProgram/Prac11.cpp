// �ǽ� 1 ��Ģ���� �Լ� �����

#include <iostream>

using namespace std;

int add(int num1,int num2)
{
	return num1 + num2; 
}

int sub(int num1, int num2)
{
	return num1 >= num2 ? (num1 - num2) : (num2 - num1); // ���� ������ ���
}

int mul(int num1, int num2)
{
	return num1 * num2;
}

/*double devide(int num1, int num2)
{
	return num1 >= num2 ? (num1 / num2) : (num2 / num1); // ���� ���� ���� -> ���� 
}*/

float devide (int num1, int num2)
{
	float fn1 = num1; //���� �Ǽ��� ��ȯ ( ���� -> �Ǽ� )
	float fn2 = num2; 

	return fn1 >= fn2 ? (fn1 / fn2) : (fn2 / fn1);
}

int main()
{
	int num1, num2;
	
	cout << "ù��° ���� �Է����ּ��� : ";
	cin >> num1;

	cout << "�ι�° ���� �Է����ּ��� : ";
	cin >> num2;

	int addResult = add(num1, num2); 
	int subResult = sub(num1, num2);
	int mulResult = mul(num1, num2);
	double devideResult = devide(num1, num2); 

	cout << " ���ϱ� : "<< addResult << endl;
	cout << " ���� : " << subResult << endl;
	cout << " ���ϱ� : " << mulResult << endl;
	cout << " ������ : " << devideResult << endl;

	return 0;
}