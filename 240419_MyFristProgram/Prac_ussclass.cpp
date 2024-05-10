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
		return m_width * m_heigh;
	}

	Rectangle(float width , float heigh) : m_width(width),m_heigh(heigh) {}

private:
	// 필드 width , height 생성
	float m_width;
	float m_heigh;
};


void main()
{
	float width;
	float height;

	cout << "사각형읙 가로와 세로 길이를 입력해주세요. (띄어쓰기로 구분) ";
	cin >> width >> height;
		
	Rectangle rectangle = {width, height}; // 인스턴스 생성 + 생성자 실행 ,필드 초기화
	
	cout << "넓이는 : " << rectangle.area();

}