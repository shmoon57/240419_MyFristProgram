#include <iostream>
#include <fstream> // ���� �а� ���� ���� ��� ���� ���
#include <vector>
#include <string> // getline ��� ���� ���̺귯��

using namespace std;

int main()
{
	ifstream in_file1; // ������ ���� file1 ���� ����
	in_file1.open("test1.txt"); // test1.txt ���� ����
	
	string line;

	vector<string> Test1Content;
	
	// ���ͱ��� �о ���� line�� ���� 
	while (getline(in_file1, line))
	{
		Test1Content.push_back(line);
	} 

	/* pushback Ȯ�� ����
	for (int i = 0; i < Test1Content.size(); i++)
	{
		cout << Test1Content.at(i) << endl;
	}
	*/

	in_file1.close();

	ofstream out_file1("output.txt"); // output.txt ���� ����
	
	for (int i = Test1Content.size()-1; i >= 0 ; i--)
	{
		out_file1 <<  Test1Content[i] << endl;
	}
 
	out_file1.close();

	return 0;

}