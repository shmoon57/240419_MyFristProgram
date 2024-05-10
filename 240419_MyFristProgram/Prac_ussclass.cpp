// �ǽ� Class ����غ���

#include <iostream>

using namespace std;

// Rectangle Ŭ���� �����
class Rectangle
{
public:
	// �簢�� ���̸� ��ȯ�ϴ� area �޼ҵ� ����
	float area()
	{
		return m_width * m_height;
	}
	// �����ڿ��� ��� ���� �ʱ�ȭ 
	 Rectangle(float width , float height)
	{
		m_width = width;
		m_height = height;
	}
	 //��� 2)  Rectangle(float width , float height) : m_width(width),m_height(height) {}

private:
	// �ʵ� m_width , m_height ����
	float m_width;
	float m_height;
};

void main()
{
	float width;
	float height;

	cout << "�簢���� ���ο� ���� ���̸� �Է����ּ���. (����� ����) ";
	cin >> width >> height;
	
	// �ν��Ͻ� ���� + ������ ���� ,�ʵ� �ʱ�ȭ
	Rectangle rectangle(width, height); 
	// ��� 2) Rectangle rectangle = {width, height}; 
	
	cout << "���̴� : " << rectangle.area() << endl;

	// Ŭ������ �ٸ� Ŭ���� ������ ����(���� ������ �̿�)
	Rectangle copy1(rectangle);
	
	// ������ ���� ���� ���ϱ�
	cout << "�ٸ� Ŭ������ ������ ������ ���̴� : " << copy1.area() << endl;

	// �⺻ �����ڷ� ������ �ٸ� Ŭ���� ������ ����(�Ҵ� �̿�)
	Rectangle R2(12, 5);
	Rectangle copy2 = R2;
	
	// �Ҵ� �̿� ���� ���ϱ�
	cout << "���� 12 , ���� 5�� �Ҵ�� ���̴� : " << copy2.area();
}