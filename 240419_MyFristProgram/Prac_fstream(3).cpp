// �ǽ� 2 ȸ�� ��θ� ������ �α��� ���
/*
ȸ�� ���� ��� �߰�
���̵� �ߺ� �Ұ���
��й�ȣ ������ �Ϲ����� Ȩ������ ���԰� ���� �빮��, �ҹ���, Ư������ ���� 8�ڸ� �̻� 20���� �̸����� ����
�ش� �������� �α��α���!
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string input_name;
	string input_pw;
	string input_phone_num;
	vector<string> info;
	bool Login = false;
	
	// ������ �ҷ����� ����
	ifstream info_file("member.txt"); // member.txt ������ ���� ���� ����� ���ÿ� ����
	string str;

	// ���� ������ �а� str�̶�� ������ ����
	while (info_file >> str)
	{
		info.push_back(str);
	}

	// ���� �ݱ�
	info_file.close();

	// �Էº�
	cout << "�̸��� �Է��ϼ���. ";
	cin >> input_name;
	cout << "����� �Է��ϼ���. ";
	cin >> input_pw;
	cout << endl;
	
	// �˻� Part : for���� ���� ���Ϳ� ����� �ε��� �� ��
	for (int i = 0; i < info.size(); i++)
	{
		if (input_name == info.at(i)) 
		{
			if (input_pw == info.at(i + 1))
			{
				Login = true;
				break;
			}
		}
	}
	
	if (Login == true)
	{
		cout << "�α��� ����" << endl;
	}

	else
	{
		cout << "�α��� ����" << endl;
	}

}
	
	

