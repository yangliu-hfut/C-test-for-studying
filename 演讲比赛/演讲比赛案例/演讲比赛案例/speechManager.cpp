#include"speechManager.h"

speechManager::speechManager()
{
	this->initSpeech();

	this->creatSpeaker();
	this->loadRecord();
}

void speechManager::show_Menu()
{
	cout << "***********************************************" << endl;
	cout << "***************欢迎参加演讲比赛****************" << endl;
	cout << "*************** 1.开始演讲比赛 ****************" << endl;
	cout << "*************** 2.查看往届记录 ****************" << endl;
	cout << "*************** 3.清空比赛记录 ****************" << endl;
	cout << "*************** 0.退出比赛程序 ****************" << endl;
	cout << "***********************************************" << endl;

}
void speechManager::exitsystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

void speechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();

	this->m_Speaker.clear();

	this->m_Idex = 1;

	this->m_Record.clear();
}

void speechManager::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name;
		name += nameSeed[i];

		//创建选手
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		this->v1.push_back(i + 10001);

		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}

}

void speechManager::startSpeech()
{
	//第一轮

	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示晋级比赛
	this->showScore();
	//第二轮开始比赛
	this->m_Idex++;
    //1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示结果
	this->showScore();
	//4.储存结果
	this->saveRecord();
	this->creatSpeaker();
	this->loadRecord();

	cout << "本次比赛结束！" << endl;
	system("pause");
	system("cls");
}

//抽签函数
void speechManager::speechDraw()
{
	cout << "第<<" << this->m_Idex << ">>轮比赛选手正在抽签" << endl;
	cout << "---------------------------------------" << endl;
	cout << "抽签后结果如下： " << endl;
	if (this->m_Idex == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------------------------" << endl;
	system("pause");
	cout << endl;

}

void speechManager::speechContest()
{
	cout << "---------------第" << this->m_Idex << "轮比赛正式开始---------------" << endl;

	//小组成绩容器
	multimap<double, int, greater<double>>groupScore;
	int num = 0;

	vector<int>v_Scr;//正在比赛选手容器

	if (this->m_Idex == 1)
	{
		v_Scr =	v1;
	}
	else
	{
		v_Scr = v2;									
	}

	for (vector<int>::iterator it = v_Scr.begin(); it != v_Scr.end(); it++)
	{
		num++;
		deque<double>d;

		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());//排序
		//去除最高最低分
		d.pop_front();
		d.pop_back();

		double sum = accumulate(d.begin(), d.end(), 0.0f);//总分
		double avg = sum / (double)d.size();//平均分
		
		//cout << "编号： " << *it << "姓名: " << this->m_Speaker[*it].m_Name << "活动平均分：" << avg << endl;

		this->m_Speaker[*it].m_Score[this->m_Idex - 1] = avg;//平均分放到Map容器

		groupScore.insert(make_pair(avg, *it));//key编号，value具体选手编号

		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号: " << it->second << "姓名： " << this->m_Speaker[it->second].m_Name << "成绩：" << this->m_Speaker[it->second].m_Score[this->m_Idex - 1] << endl;
			}

			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count ++)
			{
				if (this->m_Idex == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			groupScore.clear();
		}
	}
	cout << "第" << this->m_Idex << "轮比赛完毕" << endl;
	system("pause");
}

void speechManager::showScore()
{
	cout << "第" << this->m_Idex << "轮晋级选手信息如下：" << endl;
	vector<int>v;
	if (this->m_Idex == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "选手编号：" << *it << "  姓名：" << this->m_Speaker[*it].m_Name << " 得分：" << this->m_Speaker[*it].m_Score[this->m_Idex - 1] << endl;

	}
	cout << endl;

	system("pause");
    system("cls");
	this->show_Menu();
}

void speechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	for (vector<int>::iterator it = vVictory.begin();it != vVictory.end(); it ++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();

	cout << "结果储存成功！" << endl;

	this->fileIsempty = false;
}

void speechManager::loadRecord()
{
	//cout << "往届比赛结果如下：" << endl;
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->fileIsempty = true;
		//cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//没有文件结尾
	{
		//cout << "文件为空！" << endl;
		this->fileIsempty = true;
		ifs.close();
		return;
	}

	this->fileIsempty = false;

	ifs.putback(ch);

	string data;

	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;
		//开始寻找逗号；
		vector<string>v;//存放找到的三个人数据
		int pos = -1;//记录找到的位置。
		int start = 0;//记录开始寻找的位置。

		

		//开始找
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
				//没找到逗号
			}
			string temp = data.substr(start, pos - start);//找到的话截取字符串，substr是截取函数（开始位置，长度）
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));

		index++;
		
	}

	ifs.close();
	/*for (map<int,vector<string>>::iterator it = m_Record.begin();it != m_Record.end(); it ++ )
	{
		cout << "第" << it->first << "届比赛的的冠军是" << it->second[0] << "，分数是：" << it->second[1] << endl;
	}*/
}

void speechManager::showRecord()
{
	if (this->fileIsempty)
	{
		cout << "文件不存在，或记录为空" << endl;
	}
	else
	{
	for (int i = 0;i<this->m_Record.size();i++)
	{
		
			//if (i >= this->m_Record.size() || i < 0) { cout << "vector下标越界" << endl; break; }
			cout << "第" << i + 1 << "届 "
				<< "冠军编号：" << this->m_Record[i][0] << " 得分： " << this->m_Record[i][1] << " "
				<< "亚军编号：" << this->m_Record[i][2] << " 得分： " << this->m_Record[i][3] << " "
				<< "季军编号：" << this->m_Record[i][4] << " 得分： " << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

void speechManager::clearRecord()
{
	cout << "确认进行清空操作么？清空后将不可恢复。" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int choose = 0;
	cin >> choose;

	if (choose)
	{
		ofstream ofs("speech.csv", ios::trunc);//trunc 清空文件中所有数据

		ofs.clear();

		this->initSpeech();

		this->creatSpeaker();

		this->loadRecord();

		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

speechManager::~speechManager()
{

}
