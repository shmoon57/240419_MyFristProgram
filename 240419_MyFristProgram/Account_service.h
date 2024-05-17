#pragma once
#include<iostream>
#include<string>

using namespace std;

class Account_service
{
public:
	void transfer();
	void confirmation();
	void create();

private:
	string number;
	int activation_num;
};