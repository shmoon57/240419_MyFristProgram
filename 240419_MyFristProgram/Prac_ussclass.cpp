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
		return m_width * m_heigh;
	}

	Rectangle(float width , float heigh) : m_width(width),m_heigh(heigh) {}

private:
	// �ʵ� width , height ����
	float m_width;
	float m_heigh;
};


void main()
{
	float width;
	float height;

	cout << "�簢���� ���ο� ���� ���̸� �Է����ּ���. (����� ����) ";
	cin >> width >> height;
		
	Rectangle rectangle = {width, height}; // �ν��Ͻ� ���� + ������ ���� ,�ʵ� �ʱ�ȭ
	
	cout << "���̴� : " << rectangle.area();

}