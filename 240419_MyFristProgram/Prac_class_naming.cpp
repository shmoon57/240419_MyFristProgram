// �ǽ� 0 Ŭ���� ���� �����
/*
���࿡�� �ٷ�� ������ �Ʒ��� ����
Ŭ������ �����ϰ� ��� � �κ��� �Լ��� � �κ��� ������, Ŭ���� �̸��� �������� ����� ���غ���(���� ����)
1) �� ����
�� ID, �̸�, ���¹�ȣ, ��ȭ��ȣ, �������� ID
2) ���� ����
���� ID, �ּ�, ��ID, �� �� , Ȱ�� ���� ��
3) ���
�ű԰��� ����, ����Ȯ��, ���� ��ü, �� ���/����, ���� �߰�/����, �� ���� Ȯ��, ���� ���� Ȯ��
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