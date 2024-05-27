// 240520 static �ǽ�
// <���� �ٱ��� ���α׷�> 

#include <iostream>
#include <string>
#include <vector>

using namespace std;
// new keyword �ν��Ͻ� ����
// snack vector push 
class Snack
{
protected:
	string m_name;
	string m_factory_name;
	// int m_price;
	// ���� �ʵ� ����
	static int snack_count;

public:
	// ������
	Snack()
	{
		snack_count++;
	}
	// �Ҹ��� 
	virtual ~Snack()
	{
		snack_count--;
	}
	string get_name()
	{
		return m_name;
	}

	// snack_count �ʵ� protect�� �������� getter �Լ� ����
	// Ư¡)���� �޼ҵ� �ȿ����� �Ϲ� ����� ���� X
	static int get_count()
	{
		return snack_count;
	}

	virtual void show_info()
	{
		cout << "�����Դϴ�";
	}
};

class Candy : public Snack
{
private:
	string m_flavor;

public:
	Candy(string flavor)
	{
		this->m_flavor = flavor;
	}

	void show_info() override
	{
		cout << m_flavor << "�� ĵ��" << endl;
	}

};

class Chocolate : public Snack
{
private:
	string m_shape;

public:
	Chocolate(string shape)
	{
		this->m_shape = shape;
	}

	void show_info() override
	{
		cout << m_shape << "��� ���ݸ�" << endl;
	}

};

// ���� �ʵ� �ʱ�ȭ
int Snack::snack_count = 0;

int main()
{
	int type;
	string favor;
	string shape;

	// ��ĳ���� - �θ� ��ü ������ ������
	vector<Snack*> snack_basket;

	while (true)
	{
		cout << "���� �ٱ��Ͽ� �߰��� ������ ���ÿ�.( 1: ����, 2: ���ݸ�, 0: ���� ) : ";
		cin >> type;
		switch (type)
		{
			// ����
		case 1:
			cout << "���� �Է��ϼ���. : ";
			cin >> favor;
			snack_basket.push_back(new Candy(favor));
			break;

		case 2:
			cout << "����� �Է��ϼ���. : ";
			cin >> shape;
			snack_basket.push_back(new Chocolate(shape));
			break;

		case 0:
			cout << "���� �ٱ��Ͽ� ��� ������ " << Snack::get_count() << "�� �Դϴ�" << endl;;
			break;
			continue;
		}

		if (type == 0)
		{
			break;
		}
	}

	cout << endl << "<���� �ٱ��Ͽ� ��� ���� Ȯ��> " << endl;

	for (Snack* snack : snack_basket)
	{
		snack->show_info();
	}

	// �޸� ����
	for (Snack* snack : snack_basket) {
		delete snack;
	}

	return 0;

}