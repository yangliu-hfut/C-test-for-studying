#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"
class Dean :public Worker
{
public:
	Dean(int id, string name, int did);

	virtual void showInfo();

	virtual string getDeptName();
};
