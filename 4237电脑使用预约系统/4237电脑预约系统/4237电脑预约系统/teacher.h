#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"identity.h"

class Teacher : public Identity
{
public:
	Teacher();

	Teacher(int Id,string name,string password);

	virtual void operMenu();

	//�鿴ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//ѧУ�˺�
	int m_Id;

};