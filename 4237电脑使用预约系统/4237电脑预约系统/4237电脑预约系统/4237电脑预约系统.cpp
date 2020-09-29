#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"master.h"
#include"teacher.h"
#include"mrbao.h"

void MrBaoMenu(Identity * &baoyu)
{
	while (true)
	{
		baoyu->operMenu();//调用管理员子菜单

		MrBao * man = (MrBao*)baoyu;//父类指针转为子类指针，调用子类接口
		
		int choose = 0;
		cin >> choose;
		if (choose == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (choose == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (choose == 3)//查看实验室号电脑
		{
			cout << "查看实验室电脑余量" << endl;
			man->showComputer();
		}
		else if (choose == 4)//清空预约
		{
			cout << "清空预约记录" << endl;
			man->clearFile();
		}
		else
		{
			delete baoyu;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}


void LoginIn(string fileName , int type)//登录的全局函数
{
	Identity *person = NULL;//父类指针，指向子类对象

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string password;

	if (type == 1)
	{
		cout << "请输入学号：" << endl;
		cin >> id;
	}
	else if(type == 2)
	{
		cout << "请输入教师编号：" << endl;
		cin >> id;
	}
	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> password;

	if (type == 1)
	{
		//硕士身份认证
		int fId;
		string fName;
		string fPassword;//文件读取的信息

		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if ( fId == id && fName == name && fPassword == password)
			{
				cout << "硕士身份信息验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Master(id, name, password);

				//进入硕士的子菜单

				return;
			}
		
		}


	}
	else if(type == 2)
	{
		//老师身份认证
		//硕士身份认证
		int fId;
		string fName;
		string fPassword;//文件读取的信息

		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if (fId == id && fName == name && fPassword == password)
			{
				cout << "老师身份信息验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);

				//进入教师的子菜单

				return;
			}

		}
	}
	else if(type == 3)
	{
		//鲍老师身份认证
		string fName;
		string fPassword;
		while (ifs >> fName && ifs >> fPassword)
		{
			if (fName == name && fPassword == password)
			{
				cout << "鲍管理员身份信息验证成功！" << endl;
				system("pause");
				system("cls");
				person = new MrBao(name, password);

				//进入鲍宇管理员的子菜单
				MrBaoMenu(person);
				return;
			}
		}

	}
	cout << "验证失败！" << endl;
	system("pause");
	system("cls");

	return;

}

int main()
{

	int choose = 0;

	while (true)
	{
		cout << "=============欢迎来到4237电脑预约系统（YL出品，必属精品）=============" << endl;
		cout << "请输入身份：" << endl;
		cout << "*****1.研究生*****" << endl;
		cout << "*****2.老  师*****" << endl;
		cout << "*****3.管理员*****" << endl;
		cout << "*****0.退  出*****" << endl;

		cout << "输入你的选择： " << endl;
	
		cin >> choose;
		switch (choose)
		{
		case 1://研究生
			LoginIn(MASTER_FILE,1);
			break;
		case 2://老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LoginIn(MRBAO_FILE, 3);
			break;
		case 0://退出
			cout << "欢迎下次使用！谢谢！" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		default:
			cout << "输入有误，重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}

	}


	system("pause");
	return 0;
}