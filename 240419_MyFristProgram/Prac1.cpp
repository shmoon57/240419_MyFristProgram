#include <iostream>

int main()
{
	std::cout << "이름을 입력하세요.\n";
	std::string your_name;
	std::cin >> your_name;

	std::cout << "나이를 입력하세요.\n";
	int your_age;
	std::cin >> your_age;

	std::cout << "안녕하세요! " << your_name << "님(" << your_age << "세)";


}



