#pragma once
#include<iostream>
using namespace std;
#include"identity.h"

class Master :  public Identity
{
public:

	Master();//Ĭ�Ϲ���

	Master(int id, string name, string password);//�вι���

	virtual void operMenu();

	void applyOrder();//����ԤԼ

	void showMyOrder();//�鿴����ԤԼ

	void showAllOrder();//�鿴����ԤԼ

	void cancelOrder();//ȡ��ԤԼ

	int m_ID;//ѧ��

};
