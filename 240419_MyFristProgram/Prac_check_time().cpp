#include <iostream>
#include <time.h>

using namespace std;

/*int main()
{
	time_t start, end;
	double result;

	start = time(NULL); // ���� �ð� ��ȯ

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

	cout << "����ð� : " << result << "second" << "\n";

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

	cout << "����ð� : " << result << "milisecond" << "\n";

	return 0;
}
