// �ݺ��� ������ 1 ~ 9 �� �����
#include <iostream>

int main()
{
	int i;
	int j;
	std::cout << " 1~9 �����\n";

	for (i = 1; i <= 9; i++)
	{
		std::cout << "-----" << i << "��------" << std::endl;

		for (j = 1; j <= 9; j++)
		{
				std::cout << i << " * " << j << " = " << i * j << std::endl ;

		}		
	}

}