#include"doctor.h"
Teacher::Teacher(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Teacher::showInfo()
{
	cout << "��Ա���:" << this->m_ID
		<< "\t��Ա����:" << this->m_Name
		<< "\tλ��:" << this->getDeptName()
		<< "\t���������ʦ����Ŀ������񣬲�ָ��˶ʿѧϰ��" << endl;
}

string Teacher::getDeptName()
{
	return string("��ʿ");
}