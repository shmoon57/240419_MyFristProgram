#include <iostream>
#include <time.h>

using namespace std;

/*int main()
{
	time_t start, end;
	double result;

	start = time(NULL); // 현재 시간 반환

	int a = -9999999999;
	while (true)
	{
		a++;

		if (a == 999999999)
		{
			break;
		}

	}

	end = time(NULL);

	result = (double)(end - start);

	cout << "수행시간 : " << result << "second" << "\n";

	return 0;	
} 
*/

int main()
{
	clock_t start, end;
	double result;

	start = clock();

	int a = -9999999999;
	while (true)
	{
		a++;

		if (a == 999999999)
		{
			break;
		}
	}

	end = clock();
	result = double(end - start);

	cout << "수행시간 : " << result << "milisecond" << "\n";

	return 0;
}
