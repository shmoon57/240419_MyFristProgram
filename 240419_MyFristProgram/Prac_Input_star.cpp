// [����] �ǽ�. �Է��� ���ڸ�ŭ �� ���

#include <iostream>

int main()
{
	int num = 0;
	int i;
	int j;

	std::cout << "input : ";
	std::cin >> num;

	for (i = 1; i <= num; i++)
	{

		for (j = 0; j < i ; j++)
		{
			std::cout << '*';
		}
	
		std::cout << std::endl;
	}

}