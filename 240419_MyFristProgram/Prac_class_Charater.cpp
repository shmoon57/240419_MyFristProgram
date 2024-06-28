// 5.13(월) 커스텀 추가 작업

#include <iostream>
#include "Character.h"

using namespace std;

int main()
{
	string name, name2; // 사용자가 입력할 닉네임 선언
	string changed_name; // 사용자가 입력해 변경할 닉네임 선언
	int type; // 선택사항 입력
	int character_type;
	bool loop = true; // while문 반복 위한 부울형 변수 선언

	cout << " -------- 미니 게임 --------" << endl;
	cout << "사용하실 첫 번째 캐릭터의 닉네임을 입력해주세요 : ";
	cin >> name;
	Character character(name); // character 인스턴스 생성

	cout << "사용하실 두 번째 캐릭터의 닉네임을 입력해주세요 : ";
	cin >> name2;
	Character character2(name2); // character2 인스턴스 생성

	cout << " ---- 숫자 입력 ----" << endl;
	cout << " 1 : 닉네임 변경 " << endl;
	cout << " 2 : Level up " << endl;
	cout << " 3 : item 줍기 " << endl;
	cout << " 4 : item 사용 " << endl;
	cout << " 5 : 현재 상태 출력 " << endl;
	cout << " 6 : 몬스터 잡기 " << endl;
	cout << " 7 : 맞다이 " << endl;
	cout << " 0 : 게임 종료 " << endl;

	while (loop == true)
	{
		cout << endl << "숫자를 입력해주세요 : ";
		cin >> type;

		switch (type)
		{
			// 게임 종료
		case 0:
			cout << "게임을 종료합니다";
			loop = false;
			break;

			// 닉네임 변경
		case 1:
			while (true)
			{
				cout << "어떤 캐릭터의 닉네임을 변경하시겠습니까? : ";
				cin >> name;

				if (character.check_name(name))
				{
					cout << "어떤 닉네임으로 변경하시겠습니까? : ";
					cin >> changed_name;
					character.change_name(changed_name);
					cout << " 닉네임이 바뀌었습니다 ! " << endl;
					break;
				}
				else if (character2.check_name(name))
				{
					cout << "어떤 닉네임으로 변경하시겠습니까? : ";
					cin >> changed_name;
					character2.change_name(changed_name);
					cout << " 닉네임이 바뀌었습니다 ! " << endl;
					break;
				}
				else
				{
					cout << "닉네임을 잘못 입력했습니다!" << endl;
					cout << "다시 입력해주세요 : " << endl;
				}
			}
			break;

			// 레벨 업 
		case 2:
			while (true)
			{
				cout << "어떤 캐릭터를 이용하시겠습니까 ? 1 or 2 : ";
				cin >> character_type;
				if (character_type == 1)
				{
					character.level_one_up();
					break;
				}

				else if (character_type == 2)
				{
					character2.level_one_up();
					break;
				}

				else
				{
					cout << "잘못 입력하셨습니다! 다시 입력해주세요 " << endl;
				}
			}
			break;

			// 아이템 획득
		case 3:
			character.raise_item_num();
			break;

			// 아이템 사용
		case 4:
			if (character.get_item_num() == 0)
			{
				cout << "사용할 아이템이 없습니다 !" << endl;
				break;
			}
			else
			{
				character.use_item();
				break;
			}

			// 스텟 확인
		case 5:
			character.print_state();
			character2.print_state();
			break;

			//몬스터 잡기
		case 6:
			while (true)
			{
				cout << "어떤 캐릭터를 이용하시겠습니까 ? 1 or 2 : ";
				cin >> character_type;
				if (character_type == 1)
				{
					character.raise_exp();
					break;
				}

				else if (character_type == 2)
				{
					character2.raise_exp();
					break;
				}

				else
				{
					cout << "잘못 입력하셨습니다! 다시 입력해주세요 " << endl;
				}
			}
			break;

			// 맞다이
		case 7:
			cout << " ---- 맞다이 시작 ! ----" << endl;
			while (true)
			{
				character.attaked(character2.get_atk());
				character2.attaked(character.get_atk());
				if (character.get_hp() <= 0)
				{
					cout << character.get_name() << " 패배하였습니다 " << endl;
					break;
				}

				else if (character2.get_hp() <= 0)
				{
					cout << character2.get_name() << " 패배하였습니다 " << endl;
					break;
				}
			}
			cout << "게임을 종료합니다 !" << endl;
			loop = false;
			break;

		}
	}
}
// 빚나갈때 , 크리티컬 데미지 추가해보기
// 파일 입출력 과정 적용해보기
  