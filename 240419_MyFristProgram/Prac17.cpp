// vector 조작

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

	// 정수를 저장하는 빈 벡터 v 선언
	vector<int>v; 
	vector<int>v_2(5);

	cout << "5개의 정수를 입력할 예정입니다 \n";

	// 사용자로 부터 5개의 정수를 입력 받아 벡터에 추가
	for (int i = 0; i < 5; i++)
	{
		cout << "정수를 입력해주세요 : ";
		cin >> number;
		v.push_back(number);
		
	}
	
	// 벡터의 크기 출력
	cout << "벡터의 크기는 : " << v.size() << endl;

	// 벡터의 모든 원소 출력
	for (int i = 0; i < 5; i++)
	{
		cout << "벡터의 " << i + 1 << "번째 값 : " << v.at(i) << endl; // v[i] 동일
	}
	
	// 벡터의 가장 큰 값 찾기 
	for (int i = 0; i < 5; i++)
	{
		if (max_number < v.at(i) )
		{
			max_number = v.at(i);
		}
	}
	
	// 벡터의 가장 큰 값 출력
	cout << "벡터의 최댓값은 : " << max_number << endl;

	// 벡터의 모든 원소를 2배로 만들기
	for (int i = 0; i < 5; i++)
	{
		// v_2.push_back(i) = v.at(i) * 2; - > 오류남 
		v_2.at(i) = v.at(i) * 2;
	}

	// 2배로 만든 원소를  출력
	for (int i = 0; i < 5; i++)
	{
		cout << "벡터의 " << i + 1 << "번째 값 의 두 배는? : " << v_2.at(i) << endl; // v[i] 동일
	}

	// 인덱스를 입력 받아 해당 인덱스에 있는 원소 제거
	cout << "몇 번째 원소를 제거하시겠습니까? ( 1 ~ 5 숫자입력) : ";
	cin >> clear_number_index;
	v.erase(v.begin() + clear_number_index - 1, v.begin() + clear_number_index);
	
	// 제거한 원소 출력
	for (int i = 0; i < 4; i++)
	{
		cout << v.at(i) << ' ';
	}

	//인덱스를 선택하여 해당 인덱스에 새로운 원소 추가
	cout << endl << "몇 번째에 원소를 추가하시겠습니까? ( 1 ~ 5 숫자입력) : ";
	cin >> add_number_index;
	cout << "추가할 정수를 입력해주세요 : ";
	cin >> add_number;
	v.insert(v.begin() + add_number_index - 1, add_number);


	for (int i = 0; i < v.size(); i++)
	{
			cout << v.at(i) << ' ';
	}

}
