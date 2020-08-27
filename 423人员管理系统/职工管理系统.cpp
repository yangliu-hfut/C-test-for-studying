#include<iostream>
#include"workerManager.h"
#include<string>
#include"worker.h"
#include"employee.h"
#define MAX 1000
using namespace std;

int main()
{
	//Worker *w1 = NULL;
	//w1 = new Employee(1, "±«Óî", 5);
	//w1->showInfo();
	WorkerManager ca;
	int choose = 0;
	while (true)
	{
		ca.Show_Meun();
		cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ£º " << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
		ca.Add_Emp();
			break;
		case 2:
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