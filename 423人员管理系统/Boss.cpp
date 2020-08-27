#include"boss.h"
Boss::Boss(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Boss::showInfo()
{
	cout << "人员编号:" << this->m_ID
		<< "\t人员姓名:" << this->m_Name
		<< "\t位置:" << this->getDeptName()
		<< "\t任务：科研同时，管理学生学习。" << endl;
}

string Boss::getDeptName()
{
	return string("老师");
}