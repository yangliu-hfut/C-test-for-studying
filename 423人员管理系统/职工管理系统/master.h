#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"
class Master:public Worker
{
public:

	Master(int id,string name,int did);

	virtual void showInfo() ;

	virtual string getDeptName();
};