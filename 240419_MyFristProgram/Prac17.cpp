// vector ����

#include <iostream>
#include <vector>

using namespace std;

void main()
{
	int number;
	int max_number = INT32_MIN;
	int clear_number_index;
	int add_number_index;
	int add_number;

	// ������ �����ϴ� �� ���� v ����
	vector<int>v; 
	vector<int>v_2(5);

	cout << "5���� ������ �Է��� �����Դϴ� \n";

	// ����ڷ� ���� 5���� ������ �Է� �޾� ���Ϳ� �߰�
	for (int i = 0; i < 5; i++)
	{
		cout << "������ �Է����ּ��� : ";
		cin >> number;
		v.push_back(number);
		
	}
	
	// ������ ũ�� ���
	cout << "������ ũ��� : " << v.size() << endl;

	// ������ ��� ���� ���
	for (int i = 0; i < 5; i++)
	{
		cout << "������ " << i + 1 << "��° �� : " << v.at(i) << endl; // v[i] ����
	}
	
	// ������ ���� ū �� ã�� 
	for (int i = 0; i < 5; i++)
	{
		if (max_number < v.at(i) )
		{
			max_number = v.at(i);
		}
	}
	
	// ������ ���� ū �� ���
	cout << "������ �ִ��� : " << max_number << endl;

	// ������ ��� ���Ҹ� 2��� �����
	for (int i = 0; i < 5; i++)
	{
		// v_2.push_back(i) = v.at(i) * 2; - > ������ 
		v_2.at(i) = v.at(i) * 2;
	}

	// 2��� ���� ���Ҹ�  ���
	for (int i = 0; i < 5; i++)
	{
		cout << "������ " << i + 1 << "��° �� �� �� ���? : " << v_2.at(i) << endl; // v[i] ����
	}

	// �ε����� �Է� �޾� �ش� �ε����� �ִ� ���� ����
	cout << "�� ��° ���Ҹ� �����Ͻðڽ��ϱ�? ( 1 ~ 5 �����Է�) : ";
	cin >> clear_number_index;
	v.erase(v.begin() + clear_number_index - 1, v.begin() + clear_number_index);
	
	// ������ ���� ���
	for (int i = 0; i < 4; i++)
	{
		cout << v.at(i) << ' ';
	}

	//�ε����� �����Ͽ� �ش� �ε����� ���ο� ���� �߰�
	cout << endl << "�� ��°�� ���Ҹ� �߰��Ͻðڽ��ϱ�? ( 1 ~ 5 �����Է�) : ";
	cin >> add_number_index;
	cout << "�߰��� ������ �Է����ּ��� : ";
	cin >> add_number;
	v.insert(v.begin() + add_number_index - 1, add_number);


	for (int i = 0; i < v.size(); i++)
	{
			cout << v.at(i) << ' ';
	}

}
