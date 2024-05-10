// getter & setter ���
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
	Rectangle(float width, float height)
	{
		m_width = width;
		m_height = height;
	}

	// getter �Լ� ����
	float get_m_width() {
		return	m_width;
	}

	float get_m_height() {
		return m_height;
	}

	// setter �Լ� ����
	void set_m_width(float m_width) {
		this->m_width = m_width;
	}

	void set_m_height(float m_height) {
		this->m_height = m_height;
	}

private:
	// �ʵ�(��� ����) m_width , m_height ����
	float m_width;
	float m_height;
};

void main()
{
	float width;
	float height;

	Rectangle rect(1, 2);
	cout << "Rectangle rect(1, 2)�� ������ ���̴� : "<< rect.area() << endl;

	cout << "�簢���� ���ο� ���� ���̸� �Է����ּ���. (����� ����) ";
	cin >> width >> height;

	// setter �޼ҵ带 �̿��� user���� �Է¹��� width, height�� class �ʵ忡 ����
	rect.set_m_height(height);
	rect.set_m_width(width);

	cout << "���̴� : " << rect.area() << endl;
	cout << "���� : " << rect.get_m_width() << endl;
	cout << "���� : " << rect.get_m_height() << endl;

}




