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

	//�˵�����
	void show_Menu();

	//�˳�ϵͳ
	void exitsystem();

	//��ȡ��¼
	void loadRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsempty;

	//��������¼����
	map<int, vector<string>>m_Record;

	~speechManager();

	//��ʼ������
	void initSpeech();

	//�����ݽ���
	void creatSpeaker();

	void startSpeech();//��ʼ����

	void speechDraw();//��ǩ

	void speechContest();//��������

	void showScore();//��ʾ������������

	void saveRecord();//�����������

	void showRecord();//��ʾ���������¼

	void clearRecord();//��ռ�¼


	//��Ա����
	vector<int>v1;

	vector<int>v2;

	vector<int>vVictory;

	map<int, Speaker>m_Speaker;

	int m_Idex;
};