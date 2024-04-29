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

	// pushback 1억회 수행 , 소요시간을 ms 단위로 출력
	start = clock();

	for (int i = 0; i < 100000000; i++)
	{
		test_vec1.push_back(i);
	}
	
	end = clock();

	result = double(end - start);

	cout << "test_vec1 수행시간 : " << result << "(ms)" << endl;

	// 크기 1 정수형 벡터 생성
	vector<int> test_vec2(1); 

	// reserve() 1억개 공간 예약
	test_vec2.reserve(100000000); 

	// pushback 1억회 수행 , 소요시간을 ms 단위로 출력
	start = clock();

	for (int i = 0; i < 100000000; i++)
	{
		test_vec2.push_back(i);
	}

	end = clock();

	result = double(end - start);

	cout << "test_vec2 수행시간 : " << result << "(ms)" << endl;


}