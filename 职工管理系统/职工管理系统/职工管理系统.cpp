#include<iostream>
#include"workerManager.h"
using namespace std;

int main()
{
	//Worker *w1 = NULL;
	//w1 = new Employee(1, "����", 5);
	//w1->showInfo();
	WorkerManager ca;
	int choose = 0;
	while (true)
	{
		ca.Show_Meun();
		cout << "���������ѡ�� " << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
		ca.Add_Emp();
			break;
		case 2:
			ca.showEmp();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 0:
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