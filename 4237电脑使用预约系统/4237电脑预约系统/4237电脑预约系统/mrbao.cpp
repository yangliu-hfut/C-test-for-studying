#include<iostream>
#include"mrbao.h"


MrBao::MrBao()
{

}

MrBao::MrBao(string name, string password)
{
	this->m_Name = name;
	this->m_Password = password;

	this->initVector();

	//��ʼ��ʵ������Ϣ
	ifstream ifs;
	ifs.open(LAB_FILE, ios::in);

	Lab l;
	while (ifs >> l.m_cId && ifs >> l.m_MaxNum)
	{
		vLa.push_back(l);
	}
	ifs.close(); 
}

void MrBao::operMenu()
{
	cout << "��ӭ����ʦ��¼������ʦţ�ƣ�" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�
void MrBao::addPerson()
{
	cout << "��������ӵ��˺����ͣ�" << endl;
	cout << "1.˶ʿ" << endl;
	cout << "2.��ʦ" << endl;

	string fileName;
	string tip;
	string errorTip;

	ofstream ofs;

	int choose = 0;
	cin >> choose;

	if ( choose == 1 )
	{
		tip = "��¼��˶ʿ��ѧ��";
		fileName = MASTER_FILE;
		errorTip = "˶ʿѧ�����ظ������������룡";
	}
	else
	{
		tip = "��¼����ʦ���˺�";
		fileName = TEACHER_FILE;
		errorTip = "��ʦ�˺����ظ������������룡";
	}

	ofs.open(fileName,ios::out | ios::app);

	int id;
	string name;
	string password;

	cout << tip << endl;

	//����Ƿ����ظ�
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepet(id, choose);

		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "��¼��������" << endl;
	cin >> name;

	cout << "��¼�����룺" << endl;
	cin >> password;

	ofs << id << " " << name << " " << password << " " << endl;
	cout << "¼��ɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->initVector();
}

void printMaster(Master &m)
{
	cout << "ѧ�ţ�" << m.m_ID << "  ������" << m.m_Name << endl;
}

void printTeacher(Teacher &t)
{
	cout << "У԰�˺ţ�" << t.m_Id << "  ������" <<t.m_Name << endl;
}

//�鿴�˺�
void MrBao::showPerson()
{
	cout << "ѡ��Ҫ�鿴�����ݣ�" << endl;
	cout << "1.�鿴˶ʿ����" << endl;
	cout << "2.�鿴��ʦ����" << endl;

	int choose = 0;
	cin >> choose;

	if (choose == 1)
	{
		cout << "����˶ʿ��Ϣ���£�" << endl;
		for_each(vMa.begin(), vMa.end(), printMaster);
	}
	else
	{
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTe.begin(), vTe.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void MrBao::showComputer()
{
	cout << "ʵ������Ϣ���£�" << endl;
	for (vector<Lab>::iterator it = vLa.begin(); it != vLa.end(); it++)
	{
		cout << "ʵ���Һ�Ϊ��" << it->m_cId << "  ʵ���ҵĵ�������Ϊ��" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//�����Ϣ
void MrBao::clearFile()
{

}

//��ʼ������
void MrBao::initVector()
{
	vMa.clear();
	vTe.clear();

	//��ȡ˶ʿ��Ϣ
	ifstream ifs;
	ifs.open(MASTER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		return;
	}

	Master m;
	while (ifs >> m.m_ID && ifs >> m.m_Name && ifs >> m.m_Password)
	{
		vMa.push_back(m);
	}
	cout << "��ǰѧ��������" << vMa.size() << endl;
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifstream ifs1;
	ifs1.open(TEACHER_FILE, ios::in);

	if (!ifs1.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		return;
	}

	Teacher t;
	while (ifs1 >> t.m_Id && ifs1 >> t.m_Name && ifs1 >> t.m_Password)
	{
		vTe.push_back(t);
	}
	cout << "��ǰ��ʦ������" << vTe.size() << endl;
	ifs1.close();
}

//������ظ�����
bool MrBao::checkRepet(int id,int type)
{
	if (type == 1)
	{
		for (vector<Master>::iterator it = vMa.begin();it != vMa.end();it++)//�����it�Ǳ�����������Master��������
		{
			if (id == it->m_ID)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it1 = vTe.begin(); it1 != vTe.end(); it1 ++)
		{
			if (id == it1->m_Id)
			{
				return true;
			}
		}
	}
	return false;
}