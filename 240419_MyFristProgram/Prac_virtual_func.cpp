// 가상함수 실습 240520
// Point : overiding 시 virtual 사용하지 않으면 부모 메소드가 작동된다.

#include <iostream>

using namespace std;

class Person {

public:
	virtual void intro()
	{
		cout << "사람입니다~" << endl;
	}
};

class Student : public Person {
	string name;

public:
	Student(string name)
	{
		this->name = name;
	}

	void intro() override
	{
		cout << name << " 학생입니다." << endl;
	}

	void learn()
	{
		cout << "배웁니다." << endl;
	}
};

class Teacher : public Person
{
	string name;
public:
	Teacher(string name)
	{
		this->name = name;
	}
	void intro() override
	{
		cout << name << " 선생입니다." << endl;
	}
	void teach()
	{
		cout << "가르칩니다." << endl;
	}
};

int main()
{
	// 
	Person* pList[3];
	string names[3];

	cout << "3명의 이름을 입력해주세요. (선생님, 학생, 학생)" << endl;
	cin >> names[0] >> names[1] >> names[2];

	Teacher teacher(names[0]);
	Student student1(names[1]);
	Student student2(names[2]);

	// 업캐스팅, 동적바인딩 -> 자식메소드 실행되는 결과
	Person* t = &teacher;
	Person* s1 = &student1;
	Person* s2 = &student2;

	pList[0] = t;
	pList[1] = s1;
	pList[2] = s2;

	// 동적바인딩: 런 타임에서 실제 주소값에 해당하는 인스턴스를 확인하게됨
	cout << endl << "<동적 바인딩 결과>" << endl;
	for (auto p : pList)
	{
		p->intro();
	}

	// 다운캐스팅
	cout << endl << "<다운캐스팅 한 결과>" << endl;
	Teacher* d_t = (Teacher*)pList[0];
	d_t->teach();
	((Student*)pList[1])->learn();
	((Student*)pList[2])->learn();

	/*
	동적 할당 사용시 코드 
	
	Person* teacher = new Teacher(names[0]);
	Person* student1 = new Student(names[1]);
	Person* student2 = new Student(names[2]);
	*/

	/* pList 할당하는 코드 추가
	pList[0] = teacher; 										
	pList[1] = student1;
	pList[2] = student2;


	for (auto p : pList)
	{
		p->intro(); // 주소값을 찾아가서 teacher 인스턴스의 내용 확인
	}

	((Teacher*)pList[0])->teach();
	((Student*)pList[1])->learn();
	((Student*)pList[2])->learn();

	delete teacher;
	delete student1;
	delete student2;
	*/

	return 0;
}
