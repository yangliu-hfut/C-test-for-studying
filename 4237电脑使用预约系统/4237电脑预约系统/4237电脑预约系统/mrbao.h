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

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//�����Ϣ
	void clearFile();

	//��ʼ������
	void initVector();

	//������ظ�����
	bool checkRepet(int id,int type);

	//˶ʿ����
	vector<Master>vMa;

	//��ʦ����
	vector<Teacher>vTe;

	//������Ϣ������
	vector<Lab>vLa;

};