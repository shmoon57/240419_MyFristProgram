// getter & setter 사용
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
	Rectangle(float width, float height)
	{
		m_width = width;
		m_height = height;
	}

	// getter 함수 선언
	float get_m_width() {
		return	m_width;
	}

	float get_m_height() {
		return m_height;
	}

	// setter 함수 선언
	void set_m_width(float m_width) {
		this->m_width = m_width;
	}

	void set_m_height(float m_height) {
		this->m_height = m_height;
	}

private:
	// 필드(멤버 변수) m_width , m_height 생성
	float m_width;
	float m_height;
};

void main()
{
	float width;
	float height;

	Rectangle rect(1, 2);
	cout << "Rectangle rect(1, 2)로 설정한 넓이는 : "<< rect.area() << endl;

	cout << "사각형의 가로와 세로 길이를 입력해주세요. (띄어쓰기로 구분) ";
	cin >> width >> height;

	// setter 메소드를 이용해 user에게 입력받은 width, height를 class 필드에 저장
	rect.set_m_height(height);
	rect.set_m_width(width);

	cout << "넓이는 : " << rect.area() << endl;
	cout << "가로 : " << rect.get_m_width() << endl;
	cout << "세로 : " << rect.get_m_height() << endl;

}




