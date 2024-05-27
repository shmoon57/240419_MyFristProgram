// ��ĳ����, �ٿ�ĳ���� �ǽ� 240520
/*
1. �� �ǽ� �����ͷ� ���� ó��
2. Candy, Chocolate �����ڿ��� ���������� �Է� �ޱ�
3. Candy, Chocolate ���� ������ ����ϴ� �޼ҵ� ����� , �ٿ� ĳ�����Ͽ� �����ϱ�
*/

#include <iostream>
#include <string>

using namespace std;

class Snack
{
public:
	void PrintFactoryName()
	{
		cout << "������� : " << m_factory_name << endl;
	}

protected:
	string m_name;
	string m_factory_name;
	//int m_price;
};

class Candy : public Snack
{
	string m_flavor;

public:
	Candy(string flavor, string name, string factory_name)
	{
		this->m_flavor = flavor;
		this->m_name = name;
		this->m_factory_name = factory_name;
	}


	void PrintFactoryName()
	{
		cout << "������� : " << m_factory_name << endl;
	}

};

class Chocolate : public Snack
{
public:

	Chocolate(string shape, string name, string factory_name)
	{
		this->m_shape = shape;
		this->m_name = name;
		this->m_factory_name = factory_name;
	}

	string m_shape;

	void PrintFactoryName()
	{
		cout << "������� : " << m_factory_name << endl;
	}
};

void main()
{
	/*
	//�� ĳ���� ��� 1. Call by reference
	Candy candy1("grape", "������", "����");
	Candy candy2("orange", "�˻���", "���");
	Chocolate chocolate1("circle", "����", "���ѱ�");
	Chocolate chocolate2("triangle", "�Ƹ���", "����");

	Snack* snackBasket[4];

	snackBasket[0] = &candy1;
	snackBasket[1] = &candy2;
	snackBasket[2] = &chocolate1;
	snackBasket[3] = &chocolate2;
	// Snack* snackBasket[4] = { &candy1, &candy2, &chocolate1, &chocolate2 };
*/

	// ��ĳ���� ��� 2. �����Ҵ�
	Snack* snackBasket[4];

	snackBasket[0] = new Candy("grape", "������", "����");
	snackBasket[1] = new Candy("orange", "�˻���", "���");
	snackBasket[2] = new Chocolate("circle", "����", "���ѱ�");
	snackBasket[3] = new Chocolate("triangle", "�Ƹ���", "����");

	cout << "��ĳ���� �� ��� " << endl;

	for (auto p : snackBasket)
	{
		p->PrintFactoryName();
	}

	cout << endl;
	cout << "�ٿ�ĳ������ ��� " << endl;

	// �ٿ� ĳ����
	((Candy*)snackBasket[0])->PrintFactoryName();
	Candy* downcasting_candy2 = (Candy*)snackBasket[1];
	downcasting_candy2->PrintFactoryName();
	Chocolate* downcasting_chocolate1 = (Chocolate*)snackBasket[2];
	downcasting_chocolate1->PrintFactoryName();
	Chocolate* downcasting_chocolate2 = (Chocolate*)snackBasket[3];
	downcasting_chocolate2->PrintFactoryName();

	// �������� �Ҵ�� �޸� ����
	for (Snack* snack : snackBasket)
	{
		delete snack;
	}

}