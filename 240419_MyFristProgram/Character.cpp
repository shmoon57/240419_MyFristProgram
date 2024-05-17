#include <iostream>
#include "Character.h"

using namespace std;

void Character::change_name(string name)
{
		m_name = name;
}
	
bool Character::check_name(string what_is_name)
{
	return m_name == what_is_name; // True or False ���
}

void Character::level_one_up()
{
	m_exp = 0;
	m_hp += 50 * m_level;
	m_atk += 2 * m_level;
	m_level++;
	cout << "���� �� !" << endl;
}
// ���� �ޱ� �޼ҵ� 
void Character::attaked(int another_atk)
{
	m_hp -= 50 * another_atk; 
	cout << m_name << "�� �������� �Ծ����ϴ� ! " << endl;
}

// ����ġ ȹ�� �޼ҵ� : ���� ����ġ ȹ��� ������
void Character::raise_exp()
{
	cout << "���͸� ��ҽ��ϴ�" << endl;
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
	cout << "�������� ȹ���߽��ϴ�" << endl;
}

void Character::use_item()
{
	m_item_num--;
	cout << "�������� ����մϴ�" << endl;
	m_atk += 2;
	cout << "���ݷ��� �����մϴ�" << endl;
}

void Character::print_state( )
{
	cout << "---- " << m_name << "���� ---- " << endl;
	cout << "���� ���� : " << m_level << endl;
	cout << "���� ü�� : " << m_hp << endl;
	cout << "���� ���ݷ� : " << m_atk << endl;
	cout << "���� item ���� : " << m_item_num << endl << endl;
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

// main�� ��� �Լ�
// ĳ���� �ѹ� ��� �Լ�
/*int choose_character_num(string what_is_name)
{
	if (what_is_name == name )
	{
		return 1;
	}
	return 2;
}*/
