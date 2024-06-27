// �ǽ� 4 �˶��� �︮�� ������
// timer ������ , wait_for_alarm ������

#include <iostream>;
#include <condition_variable> 
#include <chrono> // for seconds()

using std::thread;


std::mutex mtx;
std::condition_variable cv;
bool alarm_set = false;

void timer(int clock) {
	std::this_thread::sleep_for(std::chrono::seconds(clock));; // �۾� ���� �ð�

	std::unique_lock<std::mutex> lock(mtx);
	alarm_set = true;
	cv.notify_one(); // �غ��
}

void wait_for_alarm() {
	std::unique_lock<std::mutex> lock(mtx);

	// notify_one() �ٸ� �����忡�� ȣ��Ǹ� �۵�, ���ǽ��� Ȯ�� �� ������ ������ �ؿ� �ڵ带 ���� ����
	cv.wait(lock, [] { return alarm_set; }); // �ð� ������ ���� ���
	std::cout << "�˶��� �︳�ϴ�!!!" << std::endl;
}



int main() {
	std::cout << "�˶��� ��ٸ��� ��!!" << std::endl;

	thread timer_thread(timer, 3);
	thread wait_for_alarm_thread(wait_for_alarm);

	timer_thread.join();
	wait_for_alarm_thread.join();
}

