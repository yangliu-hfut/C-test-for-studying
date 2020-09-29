#pragma once
#include<iostream>
#include<string>

class Identity
{
public:
	virtual void operMenu() = 0;//纯虚函数，此类智能做继承，且在继承类中必须对虚函数进行实现
	string m_Name;
	string m_Password;
};
