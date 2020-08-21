#include"workerManager.h"
WorkerManager::WorkerManager()
{
	//初始化
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
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
		Worker ** newSpace = new Worker*[newSize];

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
				worker = new Employee(id, name, 1);
					break;
			case 2:
				worker = new Teacher(id, name, 2);
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
	cout << "可以运行到这里" << endl;

	for (int i = 0;i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
			
	}
	ofs.close();
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}