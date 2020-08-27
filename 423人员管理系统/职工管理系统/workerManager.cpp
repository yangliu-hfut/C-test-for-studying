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
		Worker ** newSpace = new Worker *[newSize];

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
			worker = new Master(id, name, dId);
		}
		else if(dId == 2)//��ʿ
		{
			worker = new Doctor(id, name, dId);
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

//�ж���Ա�Ƿ���ڣ����ڷ����������е�λ�ã������ڷ���-1��
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

//ɾ����Ա
void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫɾ����Ա��ѧ�ţ� " << endl;
		int id = 0;
		cin >> id;

		int idex = this->Is_Exist(id);

		if (idex != -1)
		{
			for (int i = idex;i <this-> m_EmpNum - 1;i++ )
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//������Ա��
			this->m_EmpNum--;

			//�����µ�����
			this->save();

			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ��ó�Ա��" << endl;
		}
	}

	system("pause");
	system("cls");

}

//�޸���Ա��Ϣ
void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸���Ա��ѧ��" << endl;
		int id;
		cin >> id;

		int ret = this->Is_Exist(id);

		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dId = 0;


			cout << "�鵽�ˣ� " << id << "����Ա���������µ�ѧ�ţ� " << endl;
			cin >> newId;
			cout << "�������µ������� " << endl;
			cin >> newName;

			cout << "�������µ�ְ�ƣ� " << endl;
			cout << "1.˶ʿ " << endl;
			cout << "2.��ʿ " << endl;
			cout << "3.��ʦ" << endl;
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
			cout << "�޸ĳɹ���" << endl;

			this->save();
		}
		else
		{
			cout << "���޴��ˣ�" << endl;

		}

	}
	system("pause");
	system("cls");
}

//���ҳ�Ա
void WorkerManager::se_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��ѡ�������Ա�ķ�ʽ��" << endl;
		cout<< "1.����ѧ�Ų��ң�" << endl;
		cout<< "2.�����������ҡ�" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//����ѧ�Ų���
			cout << "�����������Ա��ѧ�ţ� " << endl;
			int id = 0;
			cin >> id;

			int ret = this->Is_Exist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ѯ����Ա��Ϣ���£� " << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "��Ա�����ڻ���ѧ�Ŵ���" << endl;
			}

		}
		else if (select == 2)
		{

			//����������
			string name;
			cout << "��������Ҫ������Ա�������� " << endl;
			cin >> name;

			bool flage = false;

			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�����Աѧ��Ϊ"
						<< this->m_EmpArray[i]->m_ID
						<< "����Ϣ���£�" << endl;

					flage = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flage == false)
			{
				cout << "���޴��ˣ�" << endl;
			}
				
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}
	system("pause");
	system("cls");

}

//����
void WorkerManager::paixu_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrmax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				//�����㷨
				if (select == 1)
				{
					if (this->m_EmpArray[minOrmax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minOrmax = j;
					}
				}
				//�����㷨
				else if (select == 2)
				{
					if (this->m_EmpArray[minOrmax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minOrmax = j;
					}
				}
				else
				{
					cout << "��������" << endl;
				}
			}
			if (i != minOrmax)//����λ�ý���
			{
				Worker * temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = temp;
			}
		}
	}
	cout << "����ɹ���������£� " << endl;
	this->save();
	this->showEmp();
}

//ɾ������
void WorkerManager::clean_File()
{
	cout << "���棺�Ƿ�ȷ������ļ���" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//ִ������ļ�
		ofstream ofs(FILENAME, ios::trunc);//���ָ��
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//ɾ������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "�����ɹ���" << endl;


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