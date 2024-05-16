#include <iostream>

using namespace std;

class Shape
{
protected:
	int m_side_num;
	float m_base;

public:
	Shape() {}
	Shape(int side_num, float base)
	{
		this->m_side_num = side_num;
		this->m_base = base;
	}

	void printinfo()
	{
		cout << "밑변의 길이는 : " << m_base << endl;
		cout << "변의 개수는 : " << m_side_num << endl;
	}
};

class Rectangle : Shape
{
public:

	float m_col; // 세로 
	Rectangle(float base, int col, int side_num)
	{
		this->m_side_num = side_num;
		this->m_base = base;
		this->m_col = col;
	}

	float R_area()
	{
		return (m_base * m_col);
	}

	/* 오버라이딩
	void printinfo()
	{
		cout << "사각형의 넓이는 : " << (m_col * m_base) << endl;
	}*/

	// 오버로딩
	void printinfo(float base, float col)
	{
		cout << "사각형의 넓이는 : " << (col * base) << endl;
	}

};

class Triangle : Shape
{
public:
	
	float m_height; // 높이
	Triangle(float base, int height, int side_num)
	{
		this->m_side_num = side_num;
		this->m_base = base;
		this->m_height = height;
	}
	float T_area()
	{
		return (m_height * m_base) / 2;
	}
	/* 오버라이딩
	void printinfo()
	{
		cout << "삼각형의 넓이는 : " << (m_height * m_base) / 2 << endl;
	}
	*/

	// 오버로딩
	void printinfo(float base, float height)
	{
		cout << "삼각형의 넓이는 : " << (height * base) / 2 << endl;
	}

};

int main()
{
	int side_num;
	float base;
	float height;
	float col;

	cout << "변의 개수를 입력해주세요 : ";
	cin >> side_num;
	cout << "밑변의 길이를 입력해주세요 : ";
	cin >> base;
	Shape shape(side_num, base);
	cout << endl << "입력하신 결과를 출력합니다" << endl;
	shape.printinfo();
	cout << endl;

	if (side_num == 3)
	{
		cout << "삼각형의 높이를 입력해주세요 : ";
		cin >> height;
		Triangle triangle(base, height, side_num);
		// cout << "삼각형의 넓이는 : " << triangle.T_area() << endl;
		/*오버라이딩 case
		triangle.printinfo();
		*/
		// 오버로딩
		triangle.printinfo(base, height);
		cout << endl;
	}
	
	else if (side_num ==4)
	{
		cout << "사각형의 세로 길이를 입력해주세요 : ";
		cin >> col;
		Rectangle rectangle(base, col, side_num);
		// cout << "사각형의 넓이는 : " << rectangle.R_area() << endl;
		/* 오버라이딩 case
		rectangle.printinfo();
		*/
		//오버로딩
		rectangle.printinfo(base, col);
		cout << endl;
	}
	
	else
	{
		cout << "해당되는 데이터 없음 " << endl;	
	}

	return 0;
}