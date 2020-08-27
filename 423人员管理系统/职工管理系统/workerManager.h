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
	//构造函数
	WorkerManager();

	//菜单函数
	void Show_Meun();
	
	//退出系统
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

	//删除人员
	void del_Emp();

	//判断人员是否存在，存在返回在数组中的位置，不存在返回-1；
	int Is_Exist(int id);

	//修改人员信息
	void mod_Emp();

	//查找成员
	void se_Emp();

	//排序
	void paixu_Emp();

	//删除数组
	void clean_File();

	~WorkerManager();
	//人员数组指针


};