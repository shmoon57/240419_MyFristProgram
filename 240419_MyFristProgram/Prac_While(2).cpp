// while�� ����غ��� - ������

#include <iostream>

int main()
{
	int i = 1;
	int j = 1;
	std::cout << "1 ~ 9�����\n";

	while (i <= 9)
	{
		std::cout << "-----" << i << "��-----\n";
		j = 1;
		while (j <= 9)
		{
			std::cout << i << " * " << j << " = " << i * j << std::endl;
			j++;
		}

		i++;
	}
	
}