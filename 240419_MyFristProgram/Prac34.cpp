#include <iostream>

using namespace std;

struct position
{
	float width;
	float height;
};

int main()
{
	position Rectangle;

	cout << "����, ���� ���̸� �Է��ϼ���. : ";
	cin >> Rectangle.width >> Rectangle.height;
	cout << "���� : " << Rectangle.width * Rectangle.height;

	return 0;
}