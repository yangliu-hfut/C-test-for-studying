#include"boss.h"
Boss::Boss(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Boss::showInfo()
{
	cout << "��Ա���:" << this->m_ID
		<< "\t��Ա����:" << this->m_Name
		<< "\tλ��:" << this->getDeptName()
		<< "\t���񣺿���ͬʱ������ѧ��ѧϰ��" << endl;
}

string Boss::getDeptName()
{
	return string("��ʦ");
}