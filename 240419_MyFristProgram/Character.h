#pragma once

#include <string>
using namespace std;

#ifndef Class_Character
#define Class_Character
class Character
{
public:
	// 생성자 : 캐릭터 이름 : user에게 입력 받은 값으로 생성
	Character(string name)
	{
		// this -> m_name : 필드 값을 나타내는 증거
		this->m_name = name;
	}
	
	// 메소드 선언
	void change_name(string name);
	int level_one_up();
	int item_num_one_up();
	int item_num_one_down();
	void print_state();

	// 필드 선언
private:
	string m_name;
	// 레벨, 아이템 수 0으로 초기화
	int m_level = 0;
	int m_item_num = 0;

};

#endif