#include <iostream>
#include "Character.h"

using namespace std;

int main()
{
	string name; // ����ڰ� �Է��� �г��� ����
	string name_change; // ����ڰ� �Է��� ������ �г��� ����
	int type; // ���û��� �Է�
	bool loop = true; // while�� �ݺ� ���� ���� ���� ����

	cout << " -------- �̴� ���� --------" << endl;
	cout << "����� �г����� �Է����ּ��� : ";

	cin >> name;
	Character character(name); // character �ν��Ͻ� ����

	cout << " ---- ���� �Է� ----" << endl;
	cout << " 1 : �г��� ���� " << endl;
	cout << " 2 : Level up " << endl;
	cout << " 3 : item �ݱ� " << endl;
	cout << " 4 : item ��� " << endl;
	cout << " 5 : ���� ���� ��� " << endl;
	cout << " 0 : ���� ���� " << endl << endl;

	while (loop == true)
	{
	cout << "���ڸ� �Է����ּ��� : " ;
	cin >> type;
	
		switch (type)
		{
		case 0:
			cout << "������ �����մϴ�";
			loop = false;
			break;

		case 1:
			cout << "������ �г����� �ۼ����ּ��� : ";
			cin >> name_change;
			character.change_name(name_change);
			break;

		case 2:
			character.level_one_up();
			break;

		case 3:
			character.item_num_one_up();
			break;

		case 4:
			character.item_num_one_down();
			break;

		case 5:
			character.print_state();
			break;
		}
	}
}