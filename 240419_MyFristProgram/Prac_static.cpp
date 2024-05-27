// 240520 static 실습
// <간식 바구니 프로그램> 

#include <iostream>
#include <string>
#include <vector>

using namespace std;
// new keyword 인스턴스 생성
// snack vector push 
class Snack
{
protected:
	string m_name;
	string m_factory_name;
	// int m_price;
	// 정적 필드 정의
	static int snack_count;

public:
	// 생성자
	Snack()
	{
		snack_count++;
	}
	// 소멸자 
	virtual ~Snack()
	{
		snack_count--;
	}
	string get_name()
	{
		return m_name;
	}

	// snack_count 필드 protect로 선언으로 getter 함수 선언
	// 특징)정적 메소드 안에서는 일반 멤버에 접근 X
	static int get_count()
	{
		return snack_count;
	}

	virtual void show_info()
	{
		cout << "과자입니다";
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
		cout << m_flavor << "맛 캔디" << endl;
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
		cout << m_shape << "모양 초콜릿" << endl;
	}

};

// 정적 필드 초기화
int Snack::snack_count = 0;

int main()
{
	int type;
	string favor;
	string shape;

	// 업캐스팅 - 부모 객체 포인터 가져옴
	vector<Snack*> snack_basket;

	while (true)
	{
		cout << "과자 바구니에 추가할 간식을 고르시오.( 1: 사탕, 2: 초콜릿, 0: 종료 ) : ";
		cin >> type;
		switch (type)
		{
			// 사탕
		case 1:
			cout << "맛을 입력하세요. : ";
			cin >> favor;
			snack_basket.push_back(new Candy(favor));
			break;

		case 2:
			cout << "모양을 입력하세요. : ";
			cin >> shape;
			snack_basket.push_back(new Chocolate(shape));
			break;

		case 0:
			cout << "과자 바구니에 담긴 개수는 " << Snack::get_count() << "개 입니다" << endl;;
			break;
			continue;
		}

		if (type == 0)
		{
			break;
		}
	}

	cout << endl << "<과자 바구니에 담긴 간식 확인> " << endl;

	for (Snack* snack : snack_basket)
	{
		snack->show_info();
	}

	// 메모리 해제
	for (Snack* snack : snack_basket) {
		delete snack;
	}

	return 0;

}