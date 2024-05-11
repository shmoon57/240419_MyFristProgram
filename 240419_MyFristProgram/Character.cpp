#include <iostream>
#include "Character.h"

using namespace std;

void Character::change_name(string name)
{
	m_name = name;
}

int Character::level_one_up()
{
	m_level++;
	return m_level;
}

int Character::item_num_one_up()
{
	m_item_num++;
	return m_item_num;
}

int Character::item_num_one_down()
{
	m_item_num--;
	return m_item_num;
}

void Character::print_state()
{
	cout << "현재 item 개수 : " << m_item_num << endl;
	cout << "현재 레벨 : " << m_level << endl;
	cout << "현재 닉네임 : " << m_name << endl;
}