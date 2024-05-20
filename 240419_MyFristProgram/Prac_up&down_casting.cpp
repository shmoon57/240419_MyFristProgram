// 업캐스팅, 다운캐스팅 실습 240520
/*
1. 앞 실습 포인터로 만들어서 처리
2. Candy, Chocolate 생성자에서 각각제조사 입력 받기
3. Candy, Chocolate 각각 제조사 출력하는 메소드 만들고 , 다운 캐스팅하여 실행하기
*/

#include <iostream>
#include <string>

using namespace std;

// 부모 클래스 Snack
class Snack
{
public:

	void PrintFactoryName()
	{
		cout << "제조사는 : " << m_factory_name << endl;
	}

protected:
	string m_name;
	string m_factory_name;
};

// 자식 클래스 Candy
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
		cout << "제조사는 : " << m_factory_name << endl;
	}

};

// 자식 클래스 Chocolate
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
		cout << "제조사는 : " << m_factory_name << endl;
	}
};

void main()
{
	Candy candy1("grape", "별사탕","해태");
	Candy candy2("orange", "알사탕", "농심");
	Chocolate chocolate1("circle", "가나","오뚜기");
	Chocolate chocolate2("triangle", "아몰라","수제");

	Snack *snackBasket[4];

	// 업 캐스팅
	snackBasket[0] = &candy1;
	snackBasket[1] = &candy2;
	snackBasket[2] = &chocolate1;
	snackBasket[3] = &chocolate2;

	// 부모 클래스 
	cout << "업캐스팅 한 결과 " << endl;

	for (auto p : snackBasket)
	{
		p->PrintFactoryName();
	}

	cout << endl;

	cout << "다운캐스팅한 결과 " << endl;

	Candy *downcasting_candy1 = (Candy*)snackBasket[0];
	downcasting_candy1->PrintFactoryName();
	Candy *downcasting_candy2 = (Candy*)snackBasket[1];
	downcasting_candy2->PrintFactoryName();
	Chocolate *downcasting_chocolate1 = (Chocolate*)snackBasket[2];
	downcasting_chocolate1->PrintFactoryName();
	Chocolate *downcasting_chocolate2 = (Chocolate*)snackBasket[3];
	downcasting_chocolate2->PrintFactoryName();
}