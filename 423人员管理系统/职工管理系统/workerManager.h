#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"boss.h"
#include"doctor.h"
#include"master.h"
#include<fstream>
#define FILENAME "4237.txt"
class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//�˵�����
	void Show_Meun();
	
	//�˳�ϵͳ
	void ExitSystem();


	
	//��¼��Ա����
	int m_EmpNum;

	Worker ** m_EmpArray;

	//�����Ա�ĺ���
	void Add_Emp();

	//�������ݺ���
	void save();

   //�ļ��Ƿ�Ϊ�ձ�־λ
	bool m_FileIsEmpty;

	//ͳ���ļ�����
	int getEmpNum();

	//��ʼ����Ա
	void init_Emp();

	//��ʾ��Ա����
	void showEmp();

	//ɾ����Ա
	void del_Emp();

	//�ж���Ա�Ƿ���ڣ����ڷ����������е�λ�ã������ڷ���-1��
	int Is_Exist(int id);

	//�޸���Ա��Ϣ
	void mod_Emp();

	//���ҳ�Ա
	void se_Emp();

	//����
	void paixu_Emp();

	//ɾ������
	void clean_File();

	~WorkerManager();
	//��Ա����ָ��


};