// 실습 0 클래스 구조 만들기
#include <iostream>
#include "Account_service.h"
#include "User_info.h"
using namespace std;


int main()
{
	User_info user;
	Account_service Acc;

	Acc.confirmation();
	Acc.create();
	Acc.transfer();
	user.show_user_info();

	return 0;
}