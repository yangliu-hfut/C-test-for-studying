#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"boss.h"
#include"doctor.h"
#include"employee.h"
#include<fstream>
#define FILENAME "4237.txt"
class WorkerManager
{
public:
	WorkerManager();
	//�˵�����
	void Show_Meun();
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
	~WorkerManager();
	//��Ա����ָ��


};