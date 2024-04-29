// �ǽ� 7 vector ���� üũ


#include <iostream>
#include <vector> 
#include <time.h>

using namespace std;

void main()
{
	time_t start, end;
	double result;


	vector<int> test_vec1(1); // ũ�� 1 ������ ���� ����

	// pushback 1��ȸ ���� , �ҿ�ð��� ms ������ ���
	start = clock();

	for (int i = 0; i < 100000000; i++)
	{
		test_vec1.push_back(i);
	}
	
	end = clock();

	result = double(end - start);

	cout << "test_vec1 ����ð� : " << result << "(ms)" << endl;

	// ũ�� 1 ������ ���� ����
	vector<int> test_vec2(1); 

	// reserve() 1�ﰳ ���� ����
	test_vec2.reserve(100000000); 

	// pushback 1��ȸ ���� , �ҿ�ð��� ms ������ ���
	start = clock();

	for (int i = 0; i < 100000000; i++)
	{
		test_vec2.push_back(i);
	}

	end = clock();

	result = double(end - start);

	cout << "test_vec2 ����ð� : " << result << "(ms)" << endl;


}