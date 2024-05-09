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

	cout << "가로, 세로 길이를 입력하세요. : ";
	cin >> Rectangle.width >> Rectangle.height;
	cout << "넓이 : " << Rectangle.width * Rectangle.height;

	return 0;
}