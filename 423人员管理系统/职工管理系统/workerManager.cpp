#include"workerManager.h"
WorkerManager::WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.文件存在且为空
	char c;
	ifs >> c;
	if (ifs.eof())
	{
		cout << "文件为空！" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在且不为空
	int num = this->getEmpNum();
	cout << "当前成员人数为：  " << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker*[this->m_EmpNum];
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "人员编号： " << this->m_EmpArray[i]->m_ID
	//		<< "\t姓名： " << this->m_EmpArray[i]->m_Name
	//		<< "\t职称： " << this->m_EmpArray[i]->m_DeptID << endl;


	//}
}
void WorkerManager::Show_Meun()
{
	cout << "***************************************************************" << endl;
	cout << "**********欢迎使用合肥工业大学西教423人员管理系统**************" << endl;
	cout << "*************************0.退出管理程序************************" << endl;
	cout << "*************************1.增加人员信息************************" << endl;
	cout << "*************************2.显示人员信息************************" << endl;
	cout << "*************************3.删除毕业人员************************" << endl;
	cout << "*************************4.修改人员信息************************" << endl;
	cout << "*************************5.查找人员信息************************" << endl;
	cout << "*************************6.按照编号排序************************" << endl;
	cout << "*************************7.清空所有文档************************" << endl;
	cout << endl;

}
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用本系统！" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Add_Emp()
{
	cout << "请输入添加人员数量：" << endl;
	int addNum = 0;
	cin >> addNum;


	if (addNum > 0)
	{
		//计算新空间的大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker ** newSpace = new Worker *[newSize];

		//拷贝原来空间的数据
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个新成员学号" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新成员姓名" << endl;
			cin >> name;

			cout << "请选择人员的级别：" << endl;
			cout << "1.硕士" << endl;
			cout << "2.博士" << endl;
			cout << "3.老师" << endl;

			cin >> dSelect;

			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Master(id, name, 1);
				break;
			case 2:
				worker = new Doctor(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			
			}
			//将创建人员职责，存放在数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
	
		//释放原有空间
		delete[] this->m_EmpArray;

		//更新新空间指向
		this->m_EmpArray = newSpace;

		//更新新的人员数量
		this->m_EmpNum = newSize;
		//更新职工不为空
		this->m_FileIsEmpty = false;

		//存数据函数
		this->save();
	
		cout << "成功添加了 " << addNum << "个新成员!" << endl;
		
	}
	else
	{
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}
//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out );

	for (int i = 0;i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
			
	}
	ofs.close();
}
//统计人数函数实现
int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}
//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	//读数据
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker * worker = NULL;
		if (dId == 1) //硕士
		{
			worker = new Master(id, name, dId);
		}
		else if(dId == 2)//博士
		{
			worker = new Doctor(id, name, dId);
		}
		else //老师
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
//显示成员函数
void WorkerManager::showEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//判断人员是否存在，存在返回在数组中的位置，不存在返回-1；
int WorkerManager::Is_Exist(int id)
{
	int idex = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			idex = id;
			break;
		}
	}
	return idex;
}

//删除人员
void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		cout << "输入想要删除成员的学号： " << endl;
		int id = 0;
		cin >> id;

		int idex = this->Is_Exist(id);

		if (idex != -1)
		{
			for (int i = idex;i <this-> m_EmpNum - 1;i++ )
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新人员数
			this->m_EmpNum--;

			//保存新的数据
			this->save();

			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该成员！" << endl;
		}
	}

	system("pause");
	system("cls");

}

//修改人员信息
void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{
		cout << "请输入要修改人员的学号" << endl;
		int id;
		cin >> id;

		int ret = this->Is_Exist(id);

		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dId = 0;


			cout << "查到了： " << id << "号人员，请输入新的学号： " << endl;
			cin >> newId;
			cout << "请输入新的姓名： " << endl;
			cin >> newName;

			cout << "请输入新的职称： " << endl;
			cout << "1.硕士 " << endl;
			cout << "2.博士 " << endl;
			cout << "3.老师" << endl;
			cin >> dId;

			Worker * worker = NULL;
			switch (dId)
			{
			case 1:
				worker = new Master(newId, newName, dId);
				break;
			case 2:
				worker = new Doctor(newId, newName, dId);
				break;
			case 3:
				worker = new Boss(newId, newName, dId);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "修改成功！" << endl;

			this->save();
		}
		else
		{
			cout << "查无此人！" << endl;

		}

	}
	system("pause");
	system("cls");
}

//查找成员
void WorkerManager::se_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{
		cout << "请选择查找人员的方式：" << endl;
		cout<< "1.按照学号查找；" << endl;
		cout<< "2.按照姓名查找。" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//按照学号查找
			cout << "请输入查找人员的学号： " << endl;
			int id = 0;
			cin >> id;

			int ret = this->Is_Exist(id);
			if (ret != -1)
			{
				cout << "查找成功！查询改人员信息如下： " << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "人员不存在或者学号错误！" << endl;
			}

		}
		else if (select == 2)
		{

			//按姓名查找
			string name;
			cout << "请输入需要查找人员的姓名： " << endl;
			cin >> name;

			bool flage = false;

			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，人员学号为"
						<< this->m_EmpArray[i]->m_ID
						<< "的信息如下：" << endl;

					flage = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flage == false)
			{
				cout << "查无此人！" << endl;
			}
				
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}
	system("pause");
	system("cls");

}

//排序
void WorkerManager::paixu_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.升序；" << endl;
		cout << "2.降序。" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrmax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				//升序算法
				if (select == 1)
				{
					if (this->m_EmpArray[minOrmax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minOrmax = j;
					}
				}
				//降序算法
				else if (select == 2)
				{
					if (this->m_EmpArray[minOrmax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minOrmax = j;
					}
				}
				else
				{
					cout << "输入有误！" << endl;
				}
			}
			if (i != minOrmax)//数据位置交换
			{
				Worker * temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = temp;
			}
		}
	}
	cout << "排序成功，结果如下： " << endl;
	this->save();
	this->showEmp();
}

//删除数组
void WorkerManager::clean_File()
{
	cout << "警告：是否确定清空文件？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//执行清空文件
		ofstream ofs(FILENAME, ios::trunc);//清空指令
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//删除数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "操作成功！" << endl;


	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}