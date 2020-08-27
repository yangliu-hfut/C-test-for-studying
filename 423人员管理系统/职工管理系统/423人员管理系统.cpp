#include<iostream>
#include"workerManager.h"
using namespace std;

int main()
{

	WorkerManager ca;
	int choose = 0;
	while (true)
	{
		ca.Show_Meun();
		cout << "请输入你的选择： " << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
		ca.Add_Emp();
			break;
		case 2:
			ca.showEmp();
			break;
		case 3:   //删除已毕业人员
			ca.del_Emp();
			break;
		case 4:   //修改人员信息
			ca.mod_Emp();
			break;
		case 5: //查找人员信息
			ca.se_Emp();
			break;
		case 6: //按照学号排序
			ca.paixu_Emp();
			break;
		case 7: //清空数据库
			ca.clean_File();
			break;
		case 0: //
			ca.ExitSystem();
			break;
		default:
			system("cls");
			break;

		}
	}
	system("pause");
		return 0;
}