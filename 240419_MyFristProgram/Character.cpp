#include <iostream>
#include "Character.h"

using namespace std;

void Character::change_name(string name)
{
		m_name = name;
}
	
bool Character::check_name(string what_is_name)
{
	return m_name == what_is_name; // True or False 출력
}

void Character::level_one_up()
{
	m_exp = 0;
	m_hp += 50 * m_level;
	m_atk += 2 * m_level;
	m_level++;
	cout << "레벨 업 !" << endl;
}
// 공격 받기 메소드 
void Character::attaked(int another_atk)
{
	m_hp -= 50 * another_atk; 
	cout << m_name << "이 데미지를 입었습니다 ! " << endl;
}

// 경험치 획득 메소드 : 일정 경험치 획득시 레벨업
void Character::raise_exp()
{
	cout << "몬스터를 잡았습니다" << endl;
	Character::raise_item_num();
	m_exp += 50;

	if (m_exp >= m_level * 100)
	{
		Character::level_one_up();
	}
}

void Character::raise_item_num()
{
	m_item_num++;
	cout << "아이템을 획득했습니다" << endl;
}

void Character::use_item()
{
	m_item_num--;
	cout << "아이템을 사용합니다" << endl;
	m_atk += 2;
	cout << "공격력이 증가합니다" << endl;
}

void Character::print_state( )
{
	cout << "---- " << m_name << "스텟 ---- " << endl;
	cout << "현재 레벨 : " << m_level << endl;
	cout << "현재 체력 : " << m_hp << endl;
	cout << "현재 공격력 : " << m_atk << endl;
	cout << "현재 item 개수 : " << m_item_num << endl << endl;
}

int Character::get_atk()
{
	return m_atk;
}

int Character::get_item_num()
{
	return m_item_num;
}

int Character::get_hp()
{
	return m_hp;
}

string Character::get_name()
{
	return m_name;
}

void Character::set_item_num(int item_num)
{
	this->m_item_num = item_num;
}

// main문 사용 함수
// 캐릭터 넘버 출력 함수
/*int choose_character_num(string what_is_name)
{
	if (what_is_name == name )
	{
		return 1;
	}
	return 2;
}*/
