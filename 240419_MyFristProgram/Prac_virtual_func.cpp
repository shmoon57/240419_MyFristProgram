// �����Լ� �ǽ� 240520
// Point : overiding �� virtual ������� ������ �θ� �޼ҵ尡 �۵��ȴ�.

#include <iostream>

using namespace std;

class Person {

public:
	virtual void intro()
	{
		cout << "����Դϴ�~" << endl;
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
		cout << name << " �л��Դϴ�." << endl;
	}

	void learn()
	{
		cout << "���ϴ�." << endl;
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
		cout << name << " �����Դϴ�." << endl;
	}
	void teach()
	{
		cout << "����Ĩ�ϴ�." << endl;
	}
};

int main()
{
	// 
	Person* pList[3];
	string names[3];

	cout << "3���� �̸��� �Է����ּ���. (������, �л�, �л�)" << endl;
	cin >> names[0] >> names[1] >> names[2];

	Teacher teacher(names[0]);
	Student student1(names[1]);
	Student student2(names[2]);

	// ��ĳ����, �������ε� -> �ڽĸ޼ҵ� ����Ǵ� ���
	Person* t = &teacher;
	Person* s1 = &student1;
	Person* s2 = &student2;

	pList[0] = t;
	pList[1] = s1;
	pList[2] = s2;

	// �������ε�: �� Ÿ�ӿ��� ���� �ּҰ��� �ش��ϴ� �ν��Ͻ��� Ȯ���ϰԵ�
	cout << endl << "<���� ���ε� ���>" << endl;
	for (auto p : pList)
	{
		p->intro();
	}

	// �ٿ�ĳ����
	cout << endl << "<�ٿ�ĳ���� �� ���>" << endl;
	Teacher* d_t = (Teacher*)pList[0];
	d_t->teach();
	((Student*)pList[1])->learn();
	((Student*)pList[2])->learn();

	/*
	���� �Ҵ� ���� �ڵ� 
	
	Person* teacher = new Teacher(names[0]);
	Person* student1 = new Student(names[1]);
	Person* student2 = new Student(names[2]);
	*/

	/* pList �Ҵ��ϴ� �ڵ� �߰�
	pList[0] = teacher; 										
	pList[1] = student1;
	pList[2] = student2;


	for (auto p : pList)
	{
		p->intro(); // �ּҰ��� ã�ư��� teacher �ν��Ͻ��� ���� Ȯ��
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
