// 1���� n������ �� ���ϱ�

#include <iostream>

int main()
{
	int num;
	int i;
	int sum = 0;

	std::cout << "����(���� ����)�� �Է��ϼ��� : ";
	std::cin >> num;

	for (i = 1; i <= num; i++)
	{
		sum = sum + i;

	}

	std::cout << "1���� "<< num <<" ������ ���� :" << sum;
}
