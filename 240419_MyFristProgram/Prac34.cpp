#include <iostream>

using namespace std;

struct Rectangle
{
	float width;
	float height;
};

int main()
{
	Rectangle area;

	cout << "����, ���� ���̸� �Է��ϼ���. : ";
	cin >> area.width >> area.height;
	cout << "���� : " << area.width * area.height;

	return 0;
}