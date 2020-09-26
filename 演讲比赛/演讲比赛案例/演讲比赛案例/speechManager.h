#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"speaker.h"
#include"algorithm"
#include<deque>
#include<functional>
#include<numeric>
#include<string>
#include<fstream>

class speechManager
{
public:
	speechManager();

	//菜单函数
	void show_Menu();

	//退出系统
	void exitsystem();

	//读取记录
	void loadRecord();

	//判断文件是否为空
	bool fileIsempty;

	//存放往届记录容器
	map<int, vector<string>>m_Record;

	~speechManager();

	//初始化属性
	void initSpeech();

	//创建演讲者
	void creatSpeaker();

	void startSpeech();//开始比赛

	void speechDraw();//抽签

	void speechContest();//比赛函数

	void showScore();//显示晋级名单函数

	void saveRecord();//保存晋级名单

	void showRecord();//显示往届比赛记录

	void clearRecord();//清空记录


	//成员属性
	vector<int>v1;

	vector<int>v2;

	vector<int>vVictory;

	map<int, Speaker>m_Speaker;

	int m_Idex;
};