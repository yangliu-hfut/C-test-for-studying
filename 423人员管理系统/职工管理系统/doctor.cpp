#include"doctor.h"
Doctor::Doctor(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Doctor::showInfo()
{
	cout << "��Աѧ��: " << this->m_ID
		<< "\t��Ա����: " << this->m_Name
		<< "\tְ��: " << this->getDeptName()
		<< "\t���������ʦ����Ŀ������񣬲�ָ��˶ʿѧϰ��" << endl;
}

string Doctor::getDeptName()
{
	return string("��ʿ");
}