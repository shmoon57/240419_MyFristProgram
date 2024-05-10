// 실습 Class 사용해보기

#include <iostream>

using namespace std;

// Rectangle 클래스 만들기
class Rectangle
{
public:
	// 사각형 넓이를 반환하는 area 메소드 생성
	float area()
	{
		return m_width * m_height;
	}
	// 생성자에서 멤버 변수 초기화 
	 Rectangle(float width , float height)
	{
		m_width = width;
		m_height = height;
	}
	 //방법 2)  Rectangle(float width , float height) : m_width(width),m_height(height) {}

private:
	// 필드 m_width , m_height 생성
	float m_width;
	float m_height;
};

void main()
{
	float width;
	float height;

	cout << "사각형의 가로와 세로 길이를 입력해주세요. (띄어쓰기로 구분) ";
	cin >> width >> height;
	
	// 인스턴스 생성 + 생성자 실행 ,필드 초기화
	Rectangle rectangle(width, height); 
	// 방법 2) Rectangle rectangle = {width, height}; 
	
	cout << "넓이는 : " << rectangle.area() << endl;

	// 클래스를 다른 클래스 변수에 복사(복사 생성자 이용)
	Rectangle copy1(rectangle);
	
	// 복사한 변수 넓이 구하기
	cout << "다른 클래스로 변수에 복사한 넓이는 : " << copy1.area() << endl;

	// 기본 생성자로 생성된 다른 클래스 변수에 복사(할당 이용)
	Rectangle R2(12, 5);
	Rectangle copy2 = R2;
	
	// 할당 이용 넓이 구하기
	cout << "가로 12 , 세로 5로 할당된 넓이는 : " << copy2.area();
}