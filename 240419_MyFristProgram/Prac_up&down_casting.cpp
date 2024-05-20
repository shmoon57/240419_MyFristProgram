// ��ĳ����, �ٿ�ĳ���� �ǽ� 240520
/*
1. �� �ǽ� �����ͷ� ���� ó��
2. Candy, Chocolate �����ڿ��� ���������� �Է� �ޱ�
3. Candy, Chocolate ���� ������ ����ϴ� �޼ҵ� ����� , �ٿ� ĳ�����Ͽ� �����ϱ�
*/

#include <iostream>
#include <string>

using namespace std;

// �θ� Ŭ���� Snack
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
};

// �ڽ� Ŭ���� Candy
class Candy : public Snack
{
public:
	string m_flavor;
	int m_price;

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

// �ڽ� Ŭ���� Chocolate
class Chocolate : public Snack
{
public:
	string m_shape;
	int m_price;

	Chocolate(string shape, string name, string factory_name)
	{
		this->m_shape = shape;
		this->m_name = name;
		this->m_factory_name = factory_name;
	}

	void PrintFactoryName()
	{
		cout << "������� : " << m_factory_name << endl;
	}
};

void main()
{
	Candy candy1("grape", "������","����");
	Candy candy2("orange", "�˻���", "���");
	Chocolate chocolate1("circle", "����","���ѱ�");
	Chocolate chocolate2("triangle", "�Ƹ���","����");

	Snack *snackBasket[4];

	// �� ĳ����
	snackBasket[0] = &candy1;
	snackBasket[1] = &candy2;
	snackBasket[2] = &chocolate1;
	snackBasket[3] = &chocolate2;

	// �θ� Ŭ���� 
	cout << "��ĳ���� �� ��� " << endl;

	for (auto p : snackBasket)
	{
		p->PrintFactoryName();
	}

	cout << endl;

	cout << "�ٿ�ĳ������ ��� " << endl;

	Candy *downcasting_candy1 = (Candy*)snackBasket[0];
	downcasting_candy1->PrintFactoryName();
	Candy *downcasting_candy2 = (Candy*)snackBasket[1];
	downcasting_candy2->PrintFactoryName();
	Chocolate *downcasting_chocolate1 = (Chocolate*)snackBasket[2];
	downcasting_chocolate1->PrintFactoryName();
	Chocolate *downcasting_chocolate2 = (Chocolate*)snackBasket[3];
	downcasting_chocolate2->PrintFactoryName();
}