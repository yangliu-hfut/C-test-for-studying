#include"dean.h"
Dean::Dean(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Dean::showInfo()
{
	cout << "人员编号:" << this->m_ID
		<< "\t人员姓名:" << this->m_Name
		<< "\t位置:" << this->getDeptName()
		<< "\t任务：管理整个学院。" << endl;
}

string Dean::getDeptName()
{
	return string("院长");
}