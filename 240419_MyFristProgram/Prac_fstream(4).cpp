// �ǽ� 3 �α��� ������ ��ȭ��ȣ �����ϱ�


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
	cout << "��й�ȣ�� �Է��ϼ���. ";
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
		cout << "��ȭ��ȣ�� �Է����ּ��� ex) 010-0000-0000 : ";
		cin >> input_phone_num;

		ifstream phone_num_file("member_tel.txt");
		vector<string> tel_info;	
		string member_tel_line;

		// 0. input_name -> tel_info�� �ִ��� üũ
		// ȫ�浿 010-1234-56578
		
		// 2. �ִ� -> member_tel.txt ����� ����
		// 2-1. �⺻ ���Ϳ��� �̸��� ã�Ƽ� �� ���� ����� ��ȭ��ȣ�� ���� string �Լ�
		// 2-2. ���� ��ü�� ���Ͽ� ����
		if (tel_info.size() > 0)
		{
			for (int i = 0; i < tel_info.size(); i++)
			{
				// 1. tel.inpo ���͸� ���� input_name�� member_tel.txt�� ���� ��� 
				if (tel_info[i].find(input_name) == 0) 
				{
					// string �Լ�, ���ڿ� ����, ���ڿ� �߰�
					// 1. ��ȭ��ȣ ����
					// 2. �� ��ȭ��ȣ �߰�
					int phone_idx = tel_info[i].find(' ') + 1; // ��ȭ��ȣ�� �����ϴ� �ε���
					tel_info[i].erase(phone_idx, 13);
					tel_info[i].insert(phone_idx, " ");
					tel_info[i].insert(phone_idx + 1, input_phone_num);
				}

			}
			// ���� ��ü�� ���Ͽ� ����
			ofstream new_phone_num_file("member_tel.txt");

			for (int i = 0; i < tel_info.size(); i++)
			{
				new_phone_num_file << tel_info.at(i) << endl;
			}

			new_phone_num_file.close();
		}			
		else // 2. tel.inpo ���͸� ���� input_name�� member_tel.txt�� ���� ���
		{
			// 2-1-1) ���� ����(tel_info) ���ο� �̸� + ��ȭ��ȣ �߰� 
			while (getline(phone_num_file, member_tel_line)) // member_tel.txt �� �� : member_tel_line�� �����ϱ�
			{
				tel_info.push_back(member_tel_line);
			}
			phone_num_file.close();
		
			// 2-1-2) tel_info ���Ϳ� ���Ӱ� �Է¹��� ����� �̸� + " " + ��ȭ��ȣ �߰�
			tel_info.push_back(input_name + " " + input_phone_num);
				
			// 2-2) ���� ��ü�� ���Ͽ� ����
			ofstream new_phone_num_file("member_tel.txt");

			for (int i = 0; i < tel_info.size(); i++)
			{
				new_phone_num_file << tel_info.at(i) << endl;
			}
				
			new_phone_num_file.close();
		}
	
	}

	else
	{
		cout << "�α��� ����" << endl;
	}


}



