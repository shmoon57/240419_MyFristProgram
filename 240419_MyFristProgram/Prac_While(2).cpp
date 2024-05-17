// while문 사용해보기 - 구구단

#include <iostream>

int main()
{
	int i = 1;
	int j = 1;
	std::cout << "1 ~ 9단출력\n";

	while (i <= 9)
	{
		std::cout << "-----" << i << "단-----\n";
		j = 1;
		while (j <= 9)
		{
			std::cout << i << " * " << j << " = " << i * j << std::endl;
			j++;
		}

		i++;
	}
	
}