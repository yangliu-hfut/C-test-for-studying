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
		case 3:   //ɾ���ѱ�ҵ��Ա
			ca.del_Emp();
			break;
		case 4:   //�޸���Ա��Ϣ
			ca.mod_Emp();
			break;
		case 5: //������Ա��Ϣ
			ca.se_Emp();
			break;
		case 6: //����ѧ������
			ca.paixu_Emp();
			break;
		case 7: //������ݿ�
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