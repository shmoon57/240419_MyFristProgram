// while�� ����غ��� (2)

#include <iostream>

int main()
{
	int num;
	int i = 1;
	int sum = 0;

	std::cout << "����(��������)�� �Է��ϼ���\n";
	std::cin >> num;


	while (i <= num )
	{
		sum = sum + i;
		i++;
	}

	std::cout << "1���� " << num << " ������ ���� : " << sum;
}