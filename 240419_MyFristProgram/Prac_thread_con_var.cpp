// 실습 4 알람을 울리는 스레드
// timer 스레드 , wait_for_alarm 스레드

#include <iostream>;
#include <condition_variable> 
#include <chrono> // for seconds()

using std::thread;


std::mutex mtx;
std::condition_variable cv;
bool alarm_set = false;

void timer(int clock) {
	std::this_thread::sleep_for(std::chrono::seconds(clock));; // 작업 지연 시간

	std::unique_lock<std::mutex> lock(mtx);
	alarm_set = true;
	cv.notify_one(); // 준비됨
}

void wait_for_alarm() {
	std::unique_lock<std::mutex> lock(mtx);

	// notify_one() 다른 스레드에서 호출되면 작동, 조건식을 확인 후 조건이 맞으면 밑에 코드를 마저 실행
	cv.wait(lock, [] { return alarm_set; }); // 시간 지날때 까지 대기
	std::cout << "알람이 울립니다!!!" << std::endl;
}



int main() {
	std::cout << "알람을 기다리는 중!!" << std::endl;

	thread timer_thread(timer, 3);
	thread wait_for_alarm_thread(wait_for_alarm);

	timer_thread.join();
	wait_for_alarm_thread.join();
}

