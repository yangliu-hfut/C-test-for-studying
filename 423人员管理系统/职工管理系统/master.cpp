#include"master.h"

Master::Master(int id, string name, int did)
{
	//初始化
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;

}
//显示个人信息
void Master::showInfo()
{
	cout << "人员学号: " << this->m_ID
		<< "\t人员姓名: " << this->m_Name
		<< "\t职称: " << this->getDeptName()
     	<< "\t学习任务：完成老师分配的科研任务" << endl;
}
//获取岗位信息
string Master::getDeptName()
{
	return ("硕士");
}