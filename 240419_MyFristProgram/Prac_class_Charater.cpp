// 5.13(��) Ŀ���� �߰� �۾�

#include <iostream>
#include "Character.h"

using namespace std;

int main()
{
	string name, name2; // ����ڰ� �Է��� �г��� ����
	string changed_name; // ����ڰ� �Է��� ������ �г��� ����
	int type; // ���û��� �Է�
	int character_type;
	bool loop = true; // while�� �ݺ� ���� �ο��� ���� ����

	cout << " -------- �̴� ���� --------" << endl;
	cout << "����Ͻ� ù ��° ĳ������ �г����� �Է����ּ��� : ";
	cin >> name;
	Character character(name); // character �ν��Ͻ� ����

	cout << "����Ͻ� �� ��° ĳ������ �г����� �Է����ּ��� : ";
	cin >> name2;
	Character character2(name2); // character2 �ν��Ͻ� ����

	cout << " ---- ���� �Է� ----" << endl;
	cout << " 1 : �г��� ���� " << endl;
	cout << " 2 : Level up " << endl;
	cout << " 3 : item �ݱ� " << endl;
	cout << " 4 : item ��� " << endl;
	cout << " 5 : ���� ���� ��� " << endl;
	cout << " 6 : ���� ��� " << endl;
	cout << " 7 : �´��� " << endl;
	cout << " 0 : ���� ���� " << endl;

	while (loop == true)
	{
		cout << endl << "���ڸ� �Է����ּ��� : ";
		cin >> type;

		switch (type)
		{
			// ���� ����
		case 0:
			cout << "������ �����մϴ�";
			loop = false;
			break;

			// �г��� ����
		case 1:
			while (true)
			{
				cout << "� ĳ������ �г����� �����Ͻðڽ��ϱ�? : ";
				cin >> name;

				if (character.check_name(name))
				{
					cout << "� �г������� �����Ͻðڽ��ϱ�? : ";
					cin >> changed_name;
					character.change_name(changed_name);
					cout << " �г����� �ٲ�����ϴ� ! " << endl;
					break;
				}
				else if (character2.check_name(name))
				{
					cout << "� �г������� �����Ͻðڽ��ϱ�? : ";
					cin >> changed_name;
					character2.change_name(changed_name);
					cout << " �г����� �ٲ�����ϴ� ! " << endl;
					break;
				}
				else
				{
					cout << "�г����� �߸� �Է��߽��ϴ�!" << endl;
					cout << "�ٽ� �Է����ּ��� : " << endl;
				}
			}
			break;

			// ���� �� 
		case 2:
			while (true)
			{
				cout << "� ĳ���͸� �̿��Ͻðڽ��ϱ� ? 1 or 2 : ";
				cin >> character_type;
				if (character_type == 1)
				{
					character.level_one_up();
					break;
				}

				else if (character_type == 2)
				{
					character2.level_one_up();
					break;
				}

				else
				{
					cout << "�߸� �Է��ϼ̽��ϴ�! �ٽ� �Է����ּ��� " << endl;
				}
			}
			break;

			// ������ ȹ��
		case 3:
			character.raise_item_num();
			break;

			// ������ ���
		case 4:
			if (character.get_item_num() == 0)
			{
				cout << "����� �������� �����ϴ� !" << endl;
				break;
			}
			else
			{
				character.use_item();
				break;
			}

			// ���� Ȯ��
		case 5:
			character.print_state();
			character2.print_state();
			break;

			//���� ���
		case 6:
			while (true)
			{
				cout << "� ĳ���͸� �̿��Ͻðڽ��ϱ� ? 1 or 2 : ";
				cin >> character_type;
				if (character_type == 1)
				{
					character.raise_exp();
					break;
				}

				else if (character_type == 2)
				{
					character2.raise_exp();
					break;
				}

				else
				{
					cout << "�߸� �Է��ϼ̽��ϴ�! �ٽ� �Է����ּ��� " << endl;
				}
			}
			break;

			// �´���
		case 7:
			cout << " ---- �´��� ���� ! ----" << endl;
			while (true)
			{
				character.attaked(character2.get_atk());
				character2.attaked(character.get_atk());
				if (character.get_hp() <= 0)
				{
					cout << character.get_name() << " �й��Ͽ����ϴ� " << endl;
					break;
				}

				else if (character2.get_hp() <= 0)
				{
					cout << character2.get_name() << " �й��Ͽ����ϴ� " << endl;
					break;
				}
			}
			cout << "������ �����մϴ� !" << endl;
			loop = false;
			break;

		}
	}
}
// �������� , ũ��Ƽ�� ������ �߰��غ���
// ���� ����� ���� �����غ���
  