// 실습 0 클래스 구조 만들기
/*
은행에서 다루는 정보가 아래와 같다
클래스로 적절하게 묶어서 어떤 부분을 함수로 어떤 부분을 변수로, 클래스 이름은 무엇으로 만들기 정해보기(파일 분할)
1) 고객 정보
고객 ID, 이름, 계좌번호, 전화번호, 관리지점 ID
2) 은행 정보
지점 ID, 주소, 고객ID, 고객 수 , 활성 계좌 수
3) 기능
신규계좌 개설, 계좌확인, 계좌 이체, 고객 등록/삭제, 지점 추가/삭제, 고객 정보 확인, 지점 정보 확인
*/

#include <iostream>
#include "Account_service.h"
#include "User_info.h"
using namespace std;

int main()
{
	User_info user;
	Account_service Acc;

	Acc.confirmation();
	Acc.create();
	Acc.transfer();
	user.show_user_info();

	return 0;
}