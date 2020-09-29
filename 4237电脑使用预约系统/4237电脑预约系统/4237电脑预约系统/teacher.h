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

	//查看预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//学校账号
	int m_Id;

};