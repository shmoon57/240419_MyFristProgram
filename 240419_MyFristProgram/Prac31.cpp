#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string input_name;
	string input_pw;
	vector<string> info_name;
	vector<string> info_pw;

	cout << "3���� ȸ���� ���� �̸� ��� ��ȣ�� ���������� �Է��ϼ��� Ex) ȫ�浿 134" <<  endl;

	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << "��° ȸ�� : ";
		cin >> input_name >> input_pw;
		info_name.push_back(input_name);
		info_pw.push_back(input_pw);
		cout << endl;
	}
	// ����ڷκ��� �Էµ� ������  member.txt�� ���
	ofstream write_file;
	write_file.open("member.txt");

	for (int i = 0; i < 3; i++)
	{
		write_file << info_name[i] << " "<< info_pw[i] << endl;
	}

	write_file.close();

	cout << "----------ȸ�� ��� ���� �б�----------" << endl;
	
	// member.txt�� ����� ȸ�� ��� ���

	ifstream read_file;
	read_file.open("member.txt");
	string line;
	
	while (getline(read_file, line))
	{
		cout << line << endl;
	}
	



}