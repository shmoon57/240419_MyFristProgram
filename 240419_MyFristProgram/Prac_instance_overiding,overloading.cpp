// 240516 ��� �ǽ�
// �������̵� ���� �ε� �߰�
// �߻� Ŭ���� �߰�

#include <iostream>

using namespace std;

class Shape
{
protected:
	int m_side_num;
	float m_base;
	
public:
	// ���� ���� �Լ� : �������̵� ����
	virtual void draw() = 0;

	// ��� ���迡�� �ڽ� Ŭ���� ������ ���� �θ� Ŭ���� ������ ���� ����
	Shape() {}
	Shape(int side_num, float base)
	{
		this->m_side_num = side_num;
		this->m_base = base;
	}

	void printinfo()
	{
		cout << "�Է��Ͻ� ����� ����մϴ�" << endl;
		cout << "�غ��� ���̴� : " << m_base << endl;
		cout << "���� ������ : " << m_side_num << endl;
	}
};

class Rectangle : public Shape
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

	// �������̵�
	void printinfo()
	{
		cout << "�簢���� ���̴�(�������̵� ���): " << (m_col * m_base) << endl;
	}

	// �����ε�
	void printinfo(float base, float col)
	{
		cout << "�簢���� ���̴�(�����ε� ���) : " << (col * base) << endl;
	}
	
	// virtual draw() �������̵� ����
	void draw() override
	{
		cout << "�簢��" << endl;
	}
};

class Triangle : public Shape
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
	// �������̵�
	void printinfo()
	{
		cout << "�ﰢ���� ���̴�(�������̵� ���) : " << (m_height * m_base) / 2 << endl;
	}
	

	// �����ε�
	void printinfo(float base, float height)
	{
		cout << "�ﰢ���� ���̴�(�����ε� ���) : " << (height * base) / 2 << endl;
	}

	// virtual draw() �������̵� ����
	void draw() override
	{
		cout << "�ﰢ��" << endl;
	}
};

class Circle : public Shape
{
	public:	
		// virtual draw() �������̵� ����
		void draw() override
		{
			cout << "��" << endl;
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
	cout << endl;

	//�߻�Ŭ���� ������� �ּ� ó�� �� ���� 
	//Shape shape(side_num, base);
	//shape.printinfo();
	cout << endl;

	if (side_num == 3)
	{
		cout << "�ﰢ���� ���̸� �Է����ּ��� : ";
		cin >> height;
		Triangle triangle(base, height, side_num);
		cout << "�ﰢ���� ���̴� : " << triangle.T_area() << endl;
		
		//�������̵� case
		triangle.printinfo();
		
		// �����ε� case
		triangle.printinfo(base, height);
		cout << endl;
		cout << "������ �̸� : ";
		triangle.draw();
	}
	
	else if (side_num == 4)
	{
		cout << "�簢���� ���� ���̸� �Է����ּ��� : ";
		cin >> col;
		Rectangle rectangle(base, col, side_num);
		cout << "�簢���� ���̴� : " << rectangle.R_area() << endl;
		
		// �������̵� case
		rectangle.printinfo();
		
		// �����ε� case
 		rectangle.printinfo(base, col);
		cout << endl;
		cout << "������ �̸� : ";
		rectangle.draw();
	}
	
	else
	{
		cout << "�ش�Ǵ� ������ ���� " << endl;	
	}

	return 0;
}