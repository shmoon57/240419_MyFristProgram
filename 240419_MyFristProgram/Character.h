#pragma once

#include <string>
#include <cstdlib> // 난수 생성 위한 헤더
#include <ctime>

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
		srand(time(NULL));
		int ran_num= rand();
		this->m_atk = ran_num % 6 + 1;
	}
	
	// 메소드 선언
	void change_name(string name);
	bool check_name(string what_is_name);
	void level_one_up();
	void raise_item_num();
	void use_item();
	void print_state();
	void raise_exp();
	void attaked(int atk);
	
	//getter 함수 선언
	int get_item_num();
	int get_atk();
	int get_hp();
	string get_name();
	
	//setter 함수 선언
	void set_item_num(int item_num);

private:
	// 필드 선언
	string m_name;
	int m_atk;
	int m_level = 1;
	int m_item_num = 0;
	int m_hp = 500;
	int m_exp = 0; 
};

#endif