// �ݺ��� ������ 5�� �����
#include <iostream>

int main()
{
	int i;
	
	std::cout << "5�����\n";

	for (i = 1; i <= 9; i++)
	{
		int k = 5 * i;
		std::cout << "\n5 * " << i << " = " << k;
	}

}