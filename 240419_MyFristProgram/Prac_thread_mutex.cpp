// 실습 2 mutex

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
  //lock_guard 객체 생성 시 Lock이 걸리고, 소스코드 생명주기가 끝나서 (중괄호를 벗어나거나, delete 되거나 등) 객체가 소멸하면 자동으로 unlock이 됨
  void deposit(int amount){
    std::lock_guard<mutex> lock(mtx);
    this->balance += amount;
    cout << "현재 금액 : " << balance << endl;
  };
  
  void withdraw(int amount) {
    std::lock_guard<mutex> lock(mtx);
    this->balance -= amount;
    cout << "현재 금액 : " << balance << endl;;
  }



private:
  int balance;
  // mutable은 비공식적인 변경(예: 캐싱, 통계 수집)처럼 객체의 논리적 상수성을 깨지 않는 경우에 주로 사용
  mutable mutex mtx;
};


// 뮤텍스 글로벌 영역 선언 for 다른 스레드들도 공유자원 활용
mutex mtx;

// count 횟수만큼 amount를 입금
void deposit_iter(BankAccount& Ba, int amount, int count) {
  
  for (int i = 0; i < count; i++)
  {
    Ba.deposit(amount); 
  }
  
};

// count 횟수만큼 amount를 출금
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