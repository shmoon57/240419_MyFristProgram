#include<iostream>

int main()
{
	int age;
	
	std::cout << "���̸� �Է��ϼ���\n";
	std::cin >> age;

	if (7 > age)
	{
		std::cout << "����";
	}

	else if (13 >= age)
	{
		std::cout << "�ʵ��л�";
	}
	
	else if (16 >= age)
	{
		std::cout << "���л�";
	}
	
	else if (19 >= age)
	{
		std::cout << "����л�";
	}

	else if (age >= 20)
	{
		std::cout << "����";
	}

	else if (age >= 200)
	{
		std::cout << "���̰� �ʹ� �����ϴ�..!";
	}
}