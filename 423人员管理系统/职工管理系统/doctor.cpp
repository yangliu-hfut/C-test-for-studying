#include"doctor.h"
Doctor::Doctor(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Doctor::showInfo()
{
	cout << "人员学号: " << this->m_ID
		<< "\t人员姓名: " << this->m_Name
		<< "\t职称: " << this->getDeptName()
		<< "\t任务：完成老师分配的科研任务，并指导硕士学习。" << endl;
}

string Doctor::getDeptName()
{
	return string("博士");
}