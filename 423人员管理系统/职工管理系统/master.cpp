#include"master.h"

Master::Master(int id, string name, int did)
{
	//��ʼ��
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;

}
//��ʾ������Ϣ
void Master::showInfo()
{
	cout << "��Աѧ��: " << this->m_ID
		<< "\t��Ա����: " << this->m_Name
		<< "\tְ��: " << this->getDeptName()
     	<< "\tѧϰ���������ʦ����Ŀ�������" << endl;
}
//��ȡ��λ��Ϣ
string Master::getDeptName()
{
	return ("˶ʿ");
}