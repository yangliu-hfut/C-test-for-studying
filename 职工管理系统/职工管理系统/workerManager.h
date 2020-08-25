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

   //文件是否为空标志位
	bool m_FileIsEmpty;

	//统计文件人数
	int getEmpNum();

	//初始化人员
	void init_Emp();

	//显示成员函数
	void showEmp();
	~WorkerManager();
	//人员数组指针


};