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
		cout << "�غ��� ���̴� : " << m_base << endl;
		cout << "���� ������ : " << m_side_num << endl;
	}
};

class Rectangle : Shape
{
public:
	Rectangle() {}
	float m_col; // ���� 
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

};

class Triangle : Shape
{
public:
	Triangle() {}
	float m_height; // ����
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

};

int main()
{
	int side_num;
	float base;
	float height;
	float col;

	cout << "���� ������ �Է����ּ��� : ";
	cin >> side_num;
	cout << "�غ��� ���̸� �Է����ּ��� : ";
	cin >> base;
	Shape shape(side_num, base);
	cout << endl << "�Է��Ͻ� ����� ����մϴ�" << endl;
	shape.printinfo();
	cout << endl;


	cout << "�ﰢ���� ���̸� �Է����ּ��� : ";
	cin >> height;
	Triangle triangle(base, height, side_num);
	cout << "�ﰢ���� ���̴� : " << triangle.T_area() << endl;

	cout << "�簢���� ���� ���̸� �Է����ּ��� : ";
	cin >> col;
	Rectangle rectangle(base, col, side_num);
	cout << "�簢���� ���̴� : " << rectangle.R_area() << endl;

	return 0;
}