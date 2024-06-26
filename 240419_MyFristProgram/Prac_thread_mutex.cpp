// �ǽ� 2 mutex

#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <mutex>

using std::cout;
using std::endl;
using std::thread;
using std::string;
using std::vector;
using std::mutex;
using std::ref;


class BankAccount
{
public:
  BankAccount() 
  {
    this->balance = 1000;
  }
  //lock_guard ��ü ���� �� Lock�� �ɸ���, �ҽ��ڵ� �����ֱⰡ ������ (�߰�ȣ�� ����ų�, delete �ǰų� ��) ��ü�� �Ҹ��ϸ� �ڵ����� unlock�� ��
  void deposit(int amount){
    std::lock_guard<mutex> lock(mtx);
    this->balance += amount;
    cout << "���� �ݾ� : " << balance << endl;
  };
  
  void withdraw(int amount) {
    std::lock_guard<mutex> lock(mtx);
    this->balance -= amount;
    cout << "���� �ݾ� : " << balance << endl;;
  }



private:
  int balance;
  // mutable�� ��������� ����(��: ĳ��, ��� ����)ó�� ��ü�� ���� ������� ���� �ʴ� ��쿡 �ַ� ���
  mutable mutex mtx;
};


// ���ؽ� �۷ι� ���� ���� for �ٸ� ������鵵 �����ڿ� Ȱ��
mutex mtx;

// count Ƚ����ŭ amount�� �Ա�
void deposit_iter(BankAccount& Ba, int amount, int count) {
  
  for (int i = 0; i < count; i++)
  {
    Ba.deposit(amount); 
  }
  
};

// count Ƚ����ŭ amount�� ���
void withdraw_iter(BankAccount& Ba, int amount, int count) {
  
  for (int i = 0; i < count; i++)
  {
    Ba.withdraw(amount);
    
  }
};

int main() {

  BankAccount bankaccount;

  thread d(deposit_iter, ref(bankaccount), 100, 100);
  thread w(withdraw_iter, ref(bankaccount),100,100);

  d.join();
  w.join();


  return 0;
}