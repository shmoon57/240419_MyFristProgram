#include "Prac_review.h"
#include <iostream>
#include<string>
#include <vector>

#define NAME 0
#define AGE 1
#define BIRTHDAY 2

using namespace std;

namespace sh_func
{
	// ÀÔ·ÂÇÑ ÀÌ¸§ÀÌ ÇÑ±ÛÀÌ³ª ¾ËÆÄºªÀÎÁö È®ÀÎÇÏ´Â ÇÔ¼ö
	bool isName(string& str)
	{
		for (char c : str)
		{
			// ÇÑ±Û ¹®ÀÚ ¿µ¿ªÀÇ À¯´ÏÄÚµå ¹üÀ§´Â 0xAC00(°¡)¿¡¼­ 0xD7A3(ÆR) - ¿À·ù¹ß»ı 
			if (!isalpha(c) && (c < 0xAC00 || c > 0xD7A3))
			{
				return false;
			}
		}
	}
	
	// ÀÔ·ÂÇÑ ³ªÀÌ°¡ ¼ıÀÚÀÎÁö È®ÀÎ ÇÏ´Â ÇÔ¼ö
	bool isNumber(string& str)
	{
		for (char c : str)
		{
			// ¹®ÀÚ°¡ ¼ıÀÚ°¡ ¾Æ´Ñ°æ¿ì
			if (!isdigit(c)) 
			{
				return false;
			}
		}
	}

	// ÀÔ·ÂÇÑ »ıÀÏÀÌ YYMM Çü½ÄÀÌ ¸Â´ÂÁö È®ÀÎÇÏ´Â ÇÔ¼ö
	bool isYYMM(string& str)
	{
		if (str.length() != 4)
		{
			// ÇÔ¼ö¸¦ È£ÃâÇÏ¿© »ı³â¿ùÀÏÀÌ ¼ıÀÚ·Î¸¸ ±¸¼ºµÇ¾î ÀÖ´ÂÁö È®ÀÎÇÏ±â À§ÇÔ
			return isNumber(str);
		}
	}


	// ÇĞ»ı Á¤º¸ Ãâ·Â ÇÔ¼ö , 2Â÷¿ø µ¿Àû¹è¿­ °ª È®ÀÎ
	void printStudentInfo(string** info, int student_count)
	{
		cout << "<ÇĞ»ı Á¤º¸¸¦ Ãâ·ÂÇÕ´Ï´Ù>" << endl << endl;
		cout << "ÀÌ¸§ ³ªÀÌ »ıÀÏ" << endl;

		for (int i = 0; i < student_count; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << info[i][j] << ' ';
			}
			cout << endl;
		}
	}

	// Æò±Õ ³ªÀÌ Ãâ·Â ÇÔ¼ö
	void PrintSumAge(string** info, int student_count)
	{
		int sum = 0;
		// ³ªÀÌ ÇÕ ±¸ÇÏ±â
		for (int i = 0; i < student_count; i++)
		{
			sum = sum + stoi(info[i][AGE]);
		}

		cout << endl << "³ªÀÌÀÇ ÇÕ : " << sum << endl;
		cout << "Æò±Õ ³ªÀÌ : " << float(sum / student_count) << endl; // ½Ç¼öÇüÀ¸·Î º¯È¯
	}

	// °¡Àå ºü¸¥ »ıÀÏ Ãâ·Â ÇÔ¼ö
	void PrintEarliestBirth(string** info, int student_count)
	{
		// 3-1) »ıÀÏ ¿ø¼Ò¸¦ ´ãÀ» ºó º¤ÅÍ birthday _ info »ı¼º
		vector<int>birthinfo(student_count);

		// 3-2) »ıÀÏ ¿ø¼Ò¸¦ ´ã°í stoi·Î ½Ç¼öÇüÀ» Á¤¼öÇüÀ¸·Î º¯È¯	
		for (int i = 0; i < student_count; i++)
		{
			birthinfo[i] = stoi(info[i][BIRTHDAY]);
		}

		// 3-3) ¹İº¹¹®À¸·Î ÃÖ¼Ú°ªÀ» ±¸ÇØ »ıÀÏÀÌ °¡Àå ºü¸¥ ¿ø¼Ò°ª Ãâ·Â
		int fastest_birth = INT16_MAX;

		for (int i = 0; i < student_count; i++)
		{
			if (fastest_birth > birthinfo.at(i))
			{
				fastest_birth = birthinfo.at(i);
			}

		}
		cout << endl << "°¡Àå ºü¸¥ »ıÀÏ : " << fastest_birth << endl;

	}

	// ÇĞ»ı Á¤º¸ ¼öÁ¤ ÇÔ¼ö (ÀÌ¸§À¸·Î °Ë»öÇÏ¿© ³ªÀÌ È¤Àº »ıÀÏ º¯°æ)
	void EditStudentInfo(string** info, int student_count)
	{
		string name;
		bool exit_edit = false;

		while (!exit_edit)
		{
			cout << endl << "ÆíÁıÇÒ ÇĞ»ıÀÇ ÀÌ¸§À» ÀÔ·ÂÇØÁÖ¼¼¿ä (exit : Á¾·á) : ";
			cin >> name;

			// exit ÀÔ·ÂÀ¸·Î ÆíÁı Á¾·á
			if (name == "exit")
			{
				cout << "ÆíÁıÀ» Á¾·áÇÕ´Ï´Ù ! " << endl;
				break;
			}

			bool correct_name = false;

			for (int i = 0; i < student_count; i++)
			{

				if (info[i][NAME] == name)
				{
					correct_name = true;

					while (!exit_edit)
					{
						cout << endl << "¾î¶² Á¤º¸¸¦ ÆíÁıÇÏ½Ã°Ú½À´Ï±î ? (1 : ³ªÀÌ 2 : »ıÀÏ 3 : ÆíÁı Á¾·á) : ";
						int edit_num;
						cin >> edit_num;

						// ³ªÀÌ ÆíÁı
						if (edit_num == 1)
						{
							string new_age;
							cout << endl << "»õ·Î¿î ³ªÀÌ¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä : ";
							cin >> new_age;
							info[i][AGE] = new_age;
							cout << "³ªÀÌ°¡ º¯°æ µÇ¾ú½À´Ï´Ù !" << endl;
						}

						// »ıÀÏ ÆíÁı
						else if (edit_num == 2)
						{
							string new_birthday;
							cout << endl << "»õ·Î¿î »ıÀÏÀ» ÀÔ·ÂÇØÁÖ¼¼¿ä : ";
							cin >> new_birthday;
							info[i][BIRTHDAY] = new_birthday;
							cout << "³ªÀÌ°¡ º¯°æ µÇ¾ú½À´Ï´Ù !" << endl;
						}

						// ÆíÁı Á¾·á
						else if (edit_num == 3)
						{
							cout << "ÆíÁıÀ» Á¾·áÇÕ´Ï´Ù ! " << endl;
							break;
						}

						else
						{
							cout << "Àß¸ø ÀÔ·ÂÇß½À´Ï´Ù ! " << endl;
						}
					}
				}

			}

			// exit ÀÔ·Â, ÇØ´çµÇ´Â ÀÌ¸§ ÀÔ·Â ÀÌ¿ÜÀÇ °æ¿ì
			if (name != "exit" && !correct_name)
			{
				cout << endl << "ÇØ´çµÇ´Â ÀÌ¸§ÀÌ ¾ø½À´Ï´Ù" << endl;
			}

		}
		cout << endl;
	}
}