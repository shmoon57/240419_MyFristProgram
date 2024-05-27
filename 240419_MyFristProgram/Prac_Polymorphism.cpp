// 240516 ������ �ǽ�
/*
���� �Լ��� snackBasket �̸��� �迭�� �����
1. Candy, Chocolate Ŭ���� ���� 2�� ��ü �����
2. �� 4���� ��ü�� snackBasket �迭�� �ֱ�
3. �ν��Ͻ��� �ְ� �ݸ��� ���� snackBasket �ȿ� ���ĵ��� ��ǰ �̸��� ���
*/

#include <iostream>
#include <string>

using namespace std;

class Snack
{
protected:
	string m_name;
	string m_factory_name;
	//int m_price;

public:
	string get_name()
	{
		return m_name;
	}
};

class Candy : public Snack
{
public:
	Candy(string name)
	{
		this->m_name = name;
	}

private:
	string m_flavor;
};

class Chocolate : public Snack
{
public:
	Chocolate(string name)
	{
		this->m_name = name;
	}

private:
	string m_shape;
};

int main()
{
	// stack ���� ��� case
	// Ư¡
	// ���α׷� ���� ���� �Ҵ� �޸�
	// new Ű���� �̿� ����
	// ���� �� ���� , �ü�� �� �޸� �뷮 �Ѱ�

	// 1. Candy, Chocolate Ŭ���� ���� 2�� ��ü �����
	/*Candy candy1("������");
	Candy candy2("�˻���");
	Chocolate chocolate1("����");
	Chocolate chocolate2("�Ƹ���");
	*/

	// 2. �� 4���� ��ü�� snackBasket �迭�� �ֱ�
	/* call by value : ���� ����
	Snack snackBasket[4];
	snackBasket[0] = candy1;
	snackBasket[1] = candy2;
	snackBasket[2] = chocolate1;
	snackBasket[3] = chocolate2;

	3. �ν��Ͻ��� �ְ� �ݸ��� ���� snackBasket �ȿ� ���ĵ��� ��ǰ �̸��� ���
		for (int i = 0; i < 4; i++)
	{
		cout << snackBasket[i].get_name() << endl;
	}
	*/

	// heap ���� ��� case
	// -> ���α׷��� ����Ǵ� �߿� ���Ǵ� �޸�
	// -> 100% ����ڰ� ����(new , delete)
	// 
	// call by reference : ���� �ν��Ͻ��� �����ؾ� �� ���
	/*
	Snack* snackBasket[4];
	snackBasket[0] = &candy1;
	snackBasket[1] = &candy2;
	snackBasket[2] = &chocolate1;
	snackBasket[3] = &chocolate2;
	*/

	// �������� ��ü�� �����Ͽ� �����Ϳ� �Ҵ� 
	Snack* snackBasket[4];
	snackBasket[0] = new Candy("������");
	snackBasket[1] = new Candy("�˻���");
	snackBasket[2] = new Chocolate("����");
	snackBasket[3] = new Chocolate("ũ��Ű");

	// auto : �ڷ��� �ڵ����� �����ش�(��� ����)
	// snackBasket �迭�� Snack* Ÿ���� ������ �迭
	for (Snack* snack : snackBasket)
	{
		cout << snack->get_name() << endl;
	}

	// �������� �Ҵ�� �޸� ����
	for (Snack* snack : snackBasket)
	{
		delete snack;
	}

	return 0;

}


/*
 vector<Snack*> ��� ����
1. ������ : Candy�� Chocolate Ŭ������ Snack Ŭ�������� �Ļ��� Ŭ�����̱� ������, Candy�� Chocolate ��ü�� �����͸� vector<Snack*>�� �Բ� ���� ����, �̸� ���� ���� �ٸ� ������ ������ ����� �������̽��� ���� �ٷ� �� �ֽ��ϴ�.
2. ���� �Ҵ� : new Ű���带 ����Ͽ� ��ü�� �������� �����ϰ�, �ش� ��ü�� �����͸� ���Ϳ� ���� ���� �̷��� �ϸ� ��ü�� ����Ǵ� ��� �����ͷ� �����Ǳ� ������ �����̽�(slicing) ������ �߻����� �ʽ��ϴ�.
3. ������ : ���� �߿� ���� ��ü�� ���Ϳ� �߰��ϰ� ������ �� �־� ���α׷��� �� ���������ϴ�
*/