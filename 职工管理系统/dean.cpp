#include"dean.h"
Dean::Dean(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Dean::showInfo()
{
	cout << "��Ա���:" << this->m_ID
		<< "\t��Ա����:" << this->m_Name
		<< "\tλ��:" << this->getDeptName()
		<< "\t���񣺹�������ѧԺ��" << endl;
}

string Dean::getDeptName()
{
	return string("Ժ��");
}