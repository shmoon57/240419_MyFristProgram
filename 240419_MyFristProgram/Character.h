#pragma once

#include <string>
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
	}
	
	// �޼ҵ� ����
	void change_name(string name);
	int level_one_up();
	int item_num_one_up();
	int item_num_one_down();
	void print_state();

	// �ʵ� ����
private:
	string m_name;
	// ����, ������ �� 0���� �ʱ�ȭ
	int m_level = 0;
	int m_item_num = 0;

};

#endif