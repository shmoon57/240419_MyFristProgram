#include <iostream>

// 2���� ������ �����ڸ� �Է¹޾� ����� �� �ִ� ���α׷� �����(Switch ��)


int main()
{
	float x;
	float y;
	char opr;


	std::cout << "�Ǽ� 1�� �Է��ϼ���\n";
	std::cin >> x;

	std::cout << "�Ǽ� 2�� �Է��ϼ���\n";
	std::cin >> y;

	std::cout << "� ������ �Ͻðڽ��ϱ�? ���� : + ���� : - ���� : * ������ : / ";
	std::cin >> opr;


	switch (opr)
	{
	case '+' :

		std::cout << x + y;// opr�� ���� + �� ��� �۵��� �ڵ�

		break;
	case '-':

		std::cout << x - y;// opr�� ���� - �� ��� �۵��� �ڵ�

		break;

	case '*':

		std::cout << x * y;// opr�� ���� * �� ��� �۵��� �ڵ�

		break;

	case '/':

		std::cout << x / y;// opr�� ���� / �� ��� �۵��� �ڵ�

		break;

	}

}