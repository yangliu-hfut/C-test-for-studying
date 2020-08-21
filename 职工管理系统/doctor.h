#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"
class Teacher :public Worker
{
public:
	Teacher(int id,string name,int did);

	virtual void showInfo() ;

	virtual string getDeptName() ;
};