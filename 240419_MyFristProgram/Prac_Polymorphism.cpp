// 240516 다형성 실습
/*
메인 함수에 snackBasket 이름의 배열을 만들기
1. Candy, Chocolate 클래스 각각 2개 객체 만들기
2. 총 4개의 객체를 snackBasket 배열에 넣기
3. 인스턴스를 넣고 반목문을 통해 snackBasket 안에 간식들의 상품 이름을 출력
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
	// stack 영역 사용 case
	// 특징
	// 프로그램 실행 전에 할당 메모리
	// new 키워드 이외 모든것
	// 조금 더 빠름 , 운영체제 별 메모리 용량 한계

	// 1. Candy, Chocolate 클래스 각각 2개 객체 만들기
	/*Candy candy1("별사탕");
	Candy candy2("알사탕");
	Chocolate chocolate1("가나");
	Chocolate chocolate2("아몰라");
	*/

	// 2. 총 4개의 객체를 snackBasket 배열에 넣기
	/* call by value : 값을 복사
	Snack snackBasket[4];
	snackBasket[0] = candy1;
	snackBasket[1] = candy2;
	snackBasket[2] = chocolate1;
	snackBasket[3] = chocolate2;

	3. 인스턴스를 넣고 반목문을 통해 snackBasket 안에 간식들의 상품 이름을 출력
		for (int i = 0; i < 4; i++)
	{
		cout << snackBasket[i].get_name() << endl;
	}
	*/

	// heap 영역 사용 case
	// -> 프로그램이 실행되는 중에 사용되는 메모리
	// -> 100% 사용자가 관리(new , delete)
	// 
	// call by reference : 원본 인스턴스에 접근해야 할 경우
	/*
	Snack* snackBasket[4];
	snackBasket[0] = &candy1;
	snackBasket[1] = &candy2;
	snackBasket[2] = &chocolate1;
	snackBasket[3] = &chocolate2;
	*/

	// 동적으로 객체를 생성하여 포인터에 할당 
	Snack* snackBasket[4];
	snackBasket[0] = new Candy("별사탕");
	snackBasket[1] = new Candy("알사탕");
	snackBasket[2] = new Chocolate("가나");
	snackBasket[3] = new Chocolate("크런키");

	// auto : 자료형 자동으로 정해준다(사용 비추)
	// snackBasket 배열은 Snack* 타입의 포인터 배열
	for (Snack* snack : snackBasket)
	{
		cout << snack->get_name() << endl;
	}

	// 동적으로 할당된 메모리 해제
	for (Snack* snack : snackBasket)
	{
		delete snack;
	}

	return 0;

}


/*
 vector<Snack*> 사용 이점
1. 다형성 : Candy와 Chocolate 클래스가 Snack 클래스에서 파생된 클래스이기 때문에, Candy와 Chocolate 객체의 포인터를 vector<Snack*>에 함께 저장 가능, 이를 통해 서로 다른 종류의 간식을 공통된 인터페이스를 통해 다룰 수 있습니다.
2. 동적 할당 : new 키워드를 사용하여 객체를 동적으로 생성하고, 해당 객체의 포인터를 벡터에 저장 가능 이렇게 하면 객체가 복사되는 대신 포인터로 참조되기 때문에 슬라이싱(slicing) 문제가 발생하지 않습니다.
3. 유연성 : 실행 중에 간식 객체를 벡터에 추가하고 제거할 수 있어 프로그램이 더 유연해집니다
*/