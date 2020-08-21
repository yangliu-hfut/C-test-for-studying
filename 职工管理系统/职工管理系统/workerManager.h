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
	//菜单函数
	void Show_Meun();
	void ExitSystem();


	
	//记录人员人数
	int m_EmpNum;

	Worker ** m_EmpArray;

	//添加人员的函数
	void Add_Emp();

	//保存数据函数
	void save();


	~WorkerManager();
	//人员数组指针


};