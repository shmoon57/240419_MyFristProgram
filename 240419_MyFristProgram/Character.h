#pragma once

#include <string>
#include <cstdlib> // ���� ���� ���� ���
#include <ctime>

using namespace std;

#ifndef Class_Character
#define Class_Character

class Character
{
public:
	// ������ : ĳ���� �̸� : user���� �Է� ���� ������ ����
	Character(string name)
	{
		// this -> m_name : �ʵ� ���� ��Ÿ���� ����
		this->m_name = name;
		srand(time(NULL));
		int ran_num= rand();
		this->m_atk = ran_num % 6 + 1;
	}
	
	// �޼ҵ� ����
	void change_name(string name);
	bool check_name(string what_is_name);
	void level_one_up();
	void raise_item_num();
	void use_item();
	void print_state();
	void raise_exp();
	void attaked(int atk);
	
	//getter �Լ� ����
	int get_item_num();
	int get_atk();
	int get_hp();
	string get_name();
	
	//setter �Լ� ����
	void set_item_num(int item_num);

private:
	// �ʵ� ����
	string m_name;
	int m_atk;
	int m_level = 1;
	int m_item_num = 0;
	int m_hp = 500;
	int m_exp = 0; 
};

#endif