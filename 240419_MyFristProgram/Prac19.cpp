// 실습 7 vector 성능 체크

#include <iostream>
#include <vector> 
#include <time.h>

using namespace std;

void main()
{
	time_t start, end;
	double result;


	vector<int> test_vec1(1); // 크기 1 정수형 벡터 생성

	start = clock();

	for (int i = 0; i < 100000000; i++)
	{
		test_vec1.push_back(i);
	}
	
	end = clock();

	result = double(end - start);

	cout << "test_vec1 수행시간 : " << result << "(ms)" << endl;

	vector<int> test_vec2(1); // 크기 1 정수형 벡터 생성

	test_vec2.reserve(100000000); // reserve() 1억개 공간 예약

	start = clock();

	for (int i = 0; i < 100000000; i++)
	{
		test_vec2.push_back(i);
	}

	end = clock();

	result = double(end - start);

	cout << "test_vec2 수행시간 : " << result << "(ms)" << endl;


}