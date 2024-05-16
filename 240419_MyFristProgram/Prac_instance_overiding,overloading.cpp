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

	/* �������̵�
	void printinfo()
	{
		cout << "�簢���� ���̴� : " << (m_col * m_base) << endl;
	}*/

	// �����ε�
	void printinfo(float base, float col)
	{
		cout << "�簢���� ���̴� : " << (col * base) << endl;
	}

};

class Triangle : Shape
{
public:
	
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
	/* �������̵�
	void printinfo()
	{
		cout << "�ﰢ���� ���̴� : " << (m_height * m_base) / 2 << endl;
	}
	*/

	// �����ε�
	void printinfo(float base, float height)
	{
		cout << "�ﰢ���� ���̴� : " << (height * base) / 2 << endl;
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

	if (side_num == 3)
	{
		cout << "�ﰢ���� ���̸� �Է����ּ��� : ";
		cin >> height;
		Triangle triangle(base, height, side_num);
		// cout << "�ﰢ���� ���̴� : " << triangle.T_area() << endl;
		/*�������̵� case
		triangle.printinfo();
		*/
		// �����ε�
		triangle.printinfo(base, height);
		cout << endl;
	}
	
	else if (side_num ==4)
	{
		cout << "�簢���� ���� ���̸� �Է����ּ��� : ";
		cin >> col;
		Rectangle rectangle(base, col, side_num);
		// cout << "�簢���� ���̴� : " << rectangle.R_area() << endl;
		/* �������̵� case
		rectangle.printinfo();
		*/
		//�����ε�
		rectangle.printinfo(base, col);
		cout << endl;
	}
	
	else
	{
		cout << "�ش�Ǵ� ������ ���� " << endl;	
	}

	return 0;
}