// �ǽ� 4 ����ڰ� �Է��� ���� ���ϱ�

#include <iostream>

int main()
{
	int num = 1;
	int sum = 0;

	std::cout << "����ڰ� �Է��� ���� ���ϱ�\n\n";

	while (num != 0)
	{
		std::cout << "���ڸ� �Է��ϼ���(0: exit)";

		std::cin >> num;
		sum = sum + num;

	}

	std::cout << "����ڰ� �Է��� ���� ���� : " << sum;

}