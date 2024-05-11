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
	cout << "���� item ���� : " << m_item_num << endl;
	cout << "���� ���� : " << m_level << endl;
	cout << "���� �г��� : " << m_name << endl;
}