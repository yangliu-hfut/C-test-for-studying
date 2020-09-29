#pragma once
#include<iostream>
using namespace std;
#include"identity.h"

class Master :  public Identity
{
public:

	Master();//默认构造

	Master(int id, string name, string password);//有参构造

	virtual void operMenu();

	void applyOrder();//申请预约

	void showMyOrder();//查看自身预约

	void showAllOrder();//查看所有预约

	void cancelOrder();//取消预约

	int m_ID;//学号

};
