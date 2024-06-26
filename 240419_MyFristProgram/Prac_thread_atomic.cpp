// �ǽ� 3 atomic

#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <atomic>

using std::cout;
using std::endl;
using std::thread;
using std::string;
using std::vector;
using std::atomic;
using std::ref;


class BankAccount
{
public:
  BankAccount()
  {
    // �� ����
    this->balance.store(1000);
  }

  void deposit(int amount) {

    this->balance += amount;
    cout << "���� �ݾ� : " << this->balance << endl;
  };

  void withdraw(int amount) {

    this->balance -= amount;
    cout << "���� �ݾ� : " << this->balance << endl;;
  }



private:
  atomic<int> balance;

};


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
  thread w(withdraw_iter, ref(bankaccount), 100, 100);

  d.join();
  w.join();


  return 0;
}