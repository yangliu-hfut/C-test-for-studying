#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"boss.h"
#include"doctor.h"
#include"employee.h"
#include<fstream>
#define FILENAME "423.txt"
class WorkerManager
{
public:
	WorkerManager();
	//�˵�����
	void Show_Meun();
	void ExitSystem();
	//�����Ա�ĺ���
	void Add_Emp();
	//�������ݺ���
	
	//��¼��Ա����
	int m_EmpNum;

	~WorkerManager();
	//��Ա����ָ��
	Worker **m_EmpArray;
	void save();
};