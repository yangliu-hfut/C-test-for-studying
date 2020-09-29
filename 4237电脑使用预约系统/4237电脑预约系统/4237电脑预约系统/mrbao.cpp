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

	//初始化实验室信息
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
	cout << "欢迎鲍老师登录！鲍老师牛逼！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//添加账号
void MrBao::addPerson()
{
	cout << "请输入添加的账号类型：" << endl;
	cout << "1.硕士" << endl;
	cout << "2.老师" << endl;

	string fileName;
	string tip;
	string errorTip;

	ofstream ofs;

	int choose = 0;
	cin >> choose;

	if ( choose == 1 )
	{
		tip = "请录入硕士的学号";
		fileName = MASTER_FILE;
		errorTip = "硕士学号有重复，请重新输入！";
	}
	else
	{
		tip = "请录入老师的账号";
		fileName = TEACHER_FILE;
		errorTip = "老师账号有重复，请重新输入！";
	}

	ofs.open(fileName,ios::out | ios::app);

	int id;
	string name;
	string password;

	cout << tip << endl;

	//检测是否有重复
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

	cout << "请录入姓名：" << endl;
	cin >> name;

	cout << "请录入密码：" << endl;
	cin >> password;

	ofs << id << " " << name << " " << password << " " << endl;
	cout << "录入成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->initVector();
}

void printMaster(Master &m)
{
	cout << "学号：" << m.m_ID << "  姓名：" << m.m_Name << endl;
}

void printTeacher(Teacher &t)
{
	cout << "校园账号：" << t.m_Id << "  姓名：" <<t.m_Name << endl;
}

//查看账号
void MrBao::showPerson()
{
	cout << "选择要查看的内容：" << endl;
	cout << "1.查看硕士名单" << endl;
	cout << "2.查看老师名单" << endl;

	int choose = 0;
	cin >> choose;

	if (choose == 1)
	{
		cout << "所有硕士信息如下：" << endl;
		for_each(vMa.begin(), vMa.end(), printMaster);
	}
	else
	{
		cout << "所有老师信息如下：" << endl;
		for_each(vTe.begin(), vTe.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//查看机房信息
void MrBao::showComputer()
{
	cout << "实验室信息如下：" << endl;
	for (vector<Lab>::iterator it = vLa.begin(); it != vLa.end(); it++)
	{
		cout << "实验室号为：" << it->m_cId << "  实验室的电脑容量为：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清除信息
void MrBao::clearFile()
{

}

//初始化容器
void MrBao::initVector()
{
	vMa.clear();
	vTe.clear();

	//读取硕士信息
	ifstream ifs;
	ifs.open(MASTER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		return;
	}

	Master m;
	while (ifs >> m.m_ID && ifs >> m.m_Name && ifs >> m.m_Password)
	{
		vMa.push_back(m);
	}
	cout << "当前学生数量：" << vMa.size() << endl;
	ifs.close();

	//读取老师信息
	ifstream ifs1;
	ifs1.open(TEACHER_FILE, ios::in);

	if (!ifs1.is_open())
	{
		cout << "文件不存在！" << endl;
		return;
	}

	Teacher t;
	while (ifs1 >> t.m_Id && ifs1 >> t.m_Name && ifs1 >> t.m_Password)
	{
		vTe.push_back(t);
	}
	cout << "当前老师数量：" << vTe.size() << endl;
	ifs1.close();
}

//检测编号重复函数
bool MrBao::checkRepet(int id,int type)
{
	if (type == 1)
	{
		for (vector<Master>::iterator it = vMa.begin();it != vMa.end();it++)//这里的it是遍历的容器中Master创建的类
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