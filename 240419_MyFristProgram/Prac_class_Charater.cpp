#include <iostream>
#include "Character.h"

using namespace std;

int main()
{
	string name; // 사용자가 입력할 닉네임 선언
	string name_change; // 사용자가 입력해 변경할 닉네임 선언
	int type; // 선택사항 입력
	bool loop = true; // while문 반복 위한 불형 변수 선언

	cout << " -------- 미니 게임 --------" << endl;
	cout << "사용할 닉네임을 입력해주세요 : ";

	cin >> name;
	Character character(name); // character 인스턴스 생성

	cout << " ---- 숫자 입력 ----" << endl;
	cout << " 1 : 닉네임 변경 " << endl;
	cout << " 2 : Level up " << endl;
	cout << " 3 : item 줍기 " << endl;
	cout << " 4 : item 사용 " << endl;
	cout << " 5 : 현재 상태 출력 " << endl;
	cout << " 0 : 게임 종료 " << endl << endl;

	while (loop == true)
	{
	cout << "숫자를 입력해주세요 : " ;
	cin >> type;
	
		switch (type)
		{
		case 0:
			cout << "게임을 종료합니다";
			loop = false;
			break;

		case 1:
			cout << "변경할 닉네임을 작성해주세요 : ";
			cin >> name_change;
			character.change_name(name_change);
			break;

		case 2:
			character.level_one_up();
			break;

		case 3:
			character.item_num_one_up();
			break;

		case 4:
			character.item_num_one_down();
			break;

		case 5:
			character.print_state();
			break;
		}
	}
}