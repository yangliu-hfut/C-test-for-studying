#include"workerManager.h"
WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ�������Ϊ��
	char c;
	ifs >> c;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.�ļ������Ҳ�Ϊ��
	int num = this->getEmpNum();
	cout << "��ǰ��Ա����Ϊ��  " << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker*[this->m_EmpNum];
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "��Ա��ţ� " << this->m_EmpArray[i]->m_ID
	//		<< "\t������ " << this->m_EmpArray[i]->m_Name
	//		<< "\tְ�ƣ� " << this->m_EmpArray[i]->m_DeptID << endl;


	//}
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
		//����ְ����Ϊ��
		this->m_FileIsEmpty = false;

		//�����ݺ���
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

	for (int i = 0;i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
			
	}
	ofs.close();
}
//ͳ����������ʵ��
int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

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
//��ʼ��Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	//������
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker * worker = NULL;
		if (dId == 1) //˶ʿ
		{
			worker = new Employee(id, name, dId);
		}
		else if(dId == 2)//��ʿ
		{
			worker = new Teacher(id, name, dId);
		}
		else //��ʦ
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
//��ʾ��Ա����
void WorkerManager::showEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ�գ�" << endl;
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

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}