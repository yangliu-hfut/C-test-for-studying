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
	//菜单函数
	void Show_Meun();
	void ExitSystem();
	//添加人员的函数
	void Add_Emp();
	//保存数据函数
	
	//记录人员人数
	int m_EmpNum;

	~WorkerManager();
	//人员数组指针
	Worker **m_EmpArray;
	void save();
};