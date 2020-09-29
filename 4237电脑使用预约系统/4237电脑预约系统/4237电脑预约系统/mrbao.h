#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"identity.h"
#include<fstream>
#include "globalFile.h"
#include<vector>
#include"master.h"
#include"teacher.h"
#include<algorithm>
#include"lab.h"

class MrBao :public Identity
{
public:
	MrBao();

	MrBao(string name,string password);

	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清楚信息
	void clearFile();

	//初始化容器
	void initVector();

	//检测编号重复函数
	bool checkRepet(int id,int type);

	//硕士容器
	vector<Master>vMa;

	//教师容器
	vector<Teacher>vTe;

	//机房信息的容器
	vector<Lab>vLa;

};