#include <iostream>
#include "User_info.h"
#include "Bank_info.h"

using namespace std;


void User_info::show_user_info()
{
	cout << "이름 : " << name << "고객 ID : " << ID << "전화번호 : " << number << endl;
}