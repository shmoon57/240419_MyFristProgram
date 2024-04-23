// while문 사용해보기 (2)

#include <iostream>

int main()
{
	int num;
	int i = 1;
	int sum = 0;

	std::cout << "숫자(양의정수)를 입력하세요\n";
	std::cin >> num;


	while (i <= num )
	{
		sum = sum + i;
		i++;
	}

	std::cout << "1부터 " << num << " 까지의 합은 : " << sum;
}