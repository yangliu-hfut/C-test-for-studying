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
		baoyu->operMenu();//���ù���Ա�Ӳ˵�

		MrBao * man = (MrBao*)baoyu;//����ָ��תΪ����ָ�룬��������ӿ�
		
		int choose = 0;
		cin >> choose;
		if (choose == 1)//����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (choose == 2)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (choose == 3)//�鿴ʵ���Һŵ���
		{
			cout << "�鿴ʵ���ҵ�������" << endl;
			man->showComputer();
		}
		else if (choose == 4)//���ԤԼ
		{
			cout << "���ԤԼ��¼" << endl;
			man->clearFile();
		}
		else
		{
			delete baoyu;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}


void LoginIn(string fileName , int type)//��¼��ȫ�ֺ���
{
	Identity *person = NULL;//����ָ�룬ָ���������

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string password;

	if (type == 1)
	{
		cout << "������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if(type == 2)
	{
		cout << "�������ʦ��ţ�" << endl;
		cin >> id;
	}
	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> password;

	if (type == 1)
	{
		//˶ʿ�����֤
		int fId;
		string fName;
		string fPassword;//�ļ���ȡ����Ϣ

		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if ( fId == id && fName == name && fPassword == password)
			{
				cout << "˶ʿ�����Ϣ��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Master(id, name, password);

				//����˶ʿ���Ӳ˵�

				return;
			}
		
		}


	}
	else if(type == 2)
	{
		//��ʦ�����֤
		//˶ʿ�����֤
		int fId;
		string fName;
		string fPassword;//�ļ���ȡ����Ϣ

		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if (fId == id && fName == name && fPassword == password)
			{
				cout << "��ʦ�����Ϣ��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);

				//�����ʦ���Ӳ˵�

				return;
			}

		}
	}
	else if(type == 3)
	{
		//����ʦ�����֤
		string fName;
		string fPassword;
		while (ifs >> fName && ifs >> fPassword)
		{
			if (fName == name && fPassword == password)
			{
				cout << "������Ա�����Ϣ��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new MrBao(name, password);

				//���뱫�����Ա���Ӳ˵�
				MrBaoMenu(person);
				return;
			}
		}

	}
	cout << "��֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");

	return;

}

int main()
{

	int choose = 0;

	while (true)
	{
		cout << "=============��ӭ����4237����ԤԼϵͳ��YL��Ʒ��������Ʒ��=============" << endl;
		cout << "��������ݣ�" << endl;
		cout << "*****1.�о���*****" << endl;
		cout << "*****2.��  ʦ*****" << endl;
		cout << "*****3.����Ա*****" << endl;
		cout << "*****0.��  ��*****" << endl;

		cout << "�������ѡ�� " << endl;
	
		cin >> choose;
		switch (choose)
		{
		case 1://�о���
			LoginIn(MASTER_FILE,1);
			break;
		case 2://��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			LoginIn(MRBAO_FILE, 3);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ�ã�лл��" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		default:
			cout << "���������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}

	}


	system("pause");
	return 0;
}