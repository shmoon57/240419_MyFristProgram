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

	cout << "가로, 세로 길이를 입력하세요. : ";
	cin >> area.width >> area.height;
	cout << "넓이 : " << area.width * area.height;

	return 0;
}