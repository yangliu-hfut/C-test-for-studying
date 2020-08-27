#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"
class Doctor :public Worker
{
public:
	Doctor(int id,string name,int did);

	virtual void showInfo() ;

	virtual string getDeptName() ;
};