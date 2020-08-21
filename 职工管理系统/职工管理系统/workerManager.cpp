#include"workerManager.h"
WorkerManager::WorkerManager()
{
	//��ʼ��
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
}
void WorkerManager::Show_Meun()
{
	cout << "***************************************************************" << endl;
	cout << "**********��ӭʹ�úϷʹ�ҵ��ѧ����423��Ա����ϵͳ**************" << endl;
	cout << "*************************0.�˳��������************************" << endl;
	cout << "*************************1.������Ա��Ϣ************************" << endl;
	cout << "*************************2.��ʾ��Ա��Ϣ************************" << endl;
	cout << "*************************3.ɾ����ҵ��Ա************************" << endl;
	cout << "*************************4.�޸���Ա��Ϣ************************" << endl;
	cout << "*************************5.������Ա��Ϣ************************" << endl;
	cout << "*************************6.���ձ������************************" << endl;
	cout << "*************************7.��������ĵ�************************" << endl;
	cout << endl;

}
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ñ�ϵͳ��" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Add_Emp()
{
	cout << "�����������Ա������" << endl;
	int addNum = 0;
	cin >> addNum;


	if (addNum > 0)
	{
		//�����¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker ** newSpace = new Worker*[newSize];

		//����ԭ���ռ������
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "���³�Աѧ��" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "���³�Ա����" << endl;
			cin >> name;

			cout << "��ѡ����Ա�ļ���" << endl;
			cout << "1.˶ʿ" << endl;
			cout << "2.��ʿ" << endl;
			cout << "3.��ʦ" << endl;

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
			//��������Աְ�𣬴����������
			newSpace[this->m_EmpNum + i] = worker;
		}
	
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		//�����µ���Ա����
		this->m_EmpNum = newSize;

		this->save();
	
		cout << "�ɹ������ " << addNum << "���³�Ա!" << endl;
		
	}
	else
	{
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}
//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out );
	cout << "�������е�����" << endl;

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