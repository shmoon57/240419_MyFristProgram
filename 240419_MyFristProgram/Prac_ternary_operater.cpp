// �ǽ� 5 ���� ������

#include <iostream>

int main()
{
	int num;

	std::cout << "���ڸ� �Է����ּ���\n";
	std::cin >> num;

	num % 5 == 0 ? std::cout << "5�� ����Դϴ�." : std::cout << "5�ǹ���� �ƴϳ׿�̤�";

}