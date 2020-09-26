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
	cout << "***************��ӭ�μ��ݽ�����****************" << endl;
	cout << "*************** 1.��ʼ�ݽ����� ****************" << endl;
	cout << "*************** 2.�鿴�����¼ ****************" << endl;
	cout << "*************** 3.��ձ�����¼ ****************" << endl;
	cout << "*************** 0.�˳��������� ****************" << endl;
	cout << "***********************************************" << endl;

}
void speechManager::exitsystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
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

		//����ѡ��
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
	//��һ��

	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ��������
	this->showScore();
	//�ڶ��ֿ�ʼ����
	this->m_Idex++;
    //1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ���
	this->showScore();
	//4.������
	this->saveRecord();
	this->creatSpeaker();
	this->loadRecord();

	cout << "���α���������" << endl;
	system("pause");
	system("cls");
}

//��ǩ����
void speechManager::speechDraw()
{
	cout << "��<<" << this->m_Idex << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "---------------------------------------" << endl;
	cout << "��ǩ�������£� " << endl;
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
	cout << "---------------��" << this->m_Idex << "�ֱ�����ʽ��ʼ---------------" << endl;

	//С��ɼ�����
	multimap<double, int, greater<double>>groupScore;
	int num = 0;

	vector<int>v_Scr;//���ڱ���ѡ������

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
		sort(d.begin(), d.end(), greater<double>());//����
		//ȥ�������ͷ�
		d.pop_front();
		d.pop_back();

		double sum = accumulate(d.begin(), d.end(), 0.0f);//�ܷ�
		double avg = sum / (double)d.size();//ƽ����
		
		//cout << "��ţ� " << *it << "����: " << this->m_Speaker[*it].m_Name << "�ƽ���֣�" << avg << endl;

		this->m_Speaker[*it].m_Score[this->m_Idex - 1] = avg;//ƽ���ַŵ�Map����

		groupScore.insert(make_pair(avg, *it));//key��ţ�value����ѡ�ֱ��

		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "���: " << it->second << "������ " << this->m_Speaker[it->second].m_Name << "�ɼ���" << this->m_Speaker[it->second].m_Score[this->m_Idex - 1] << endl;
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
	cout << "��" << this->m_Idex << "�ֱ������" << endl;
	system("pause");
}

void speechManager::showScore()
{
	cout << "��" << this->m_Idex << "�ֽ���ѡ����Ϣ���£�" << endl;
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
		cout << "ѡ�ֱ�ţ�" << *it << "  ������" << this->m_Speaker[*it].m_Name << " �÷֣�" << this->m_Speaker[*it].m_Score[this->m_Idex - 1] << endl;

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

	cout << "�������ɹ���" << endl;

	this->fileIsempty = false;
}

void speechManager::loadRecord()
{
	//cout << "�������������£�" << endl;
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->fileIsempty = true;
		//cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//û���ļ���β
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
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
		//��ʼѰ�Ҷ��ţ�
		vector<string>v;//����ҵ�������������
		int pos = -1;//��¼�ҵ���λ�á�
		int start = 0;//��¼��ʼѰ�ҵ�λ�á�

		

		//��ʼ��
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
				//û�ҵ�����
			}
			string temp = data.substr(start, pos - start);//�ҵ��Ļ���ȡ�ַ�����substr�ǽ�ȡ��������ʼλ�ã����ȣ�
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));

		index++;
		
	}

	ifs.close();
	/*for (map<int,vector<string>>::iterator it = m_Record.begin();it != m_Record.end(); it ++ )
	{
		cout << "��" << it->first << "������ĵĹھ���" << it->second[0] << "�������ǣ�" << it->second[1] << endl;
	}*/
}

void speechManager::showRecord()
{
	if (this->fileIsempty)
	{
		cout << "�ļ������ڣ����¼Ϊ��" << endl;
	}
	else
	{
	for (int i = 0;i<this->m_Record.size();i++)
	{
		
			//if (i >= this->m_Record.size() || i < 0) { cout << "vector�±�Խ��" << endl; break; }
			cout << "��" << i + 1 << "�� "
				<< "�ھ���ţ�" << this->m_Record[i][0] << " �÷֣� " << this->m_Record[i][1] << " "
				<< "�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣� " << this->m_Record[i][3] << " "
				<< "������ţ�" << this->m_Record[i][4] << " �÷֣� " << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

void speechManager::clearRecord()
{
	cout << "ȷ�Ͻ�����ղ���ô����պ󽫲��ɻָ���" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int choose = 0;
	cin >> choose;

	if (choose)
	{
		ofstream ofs("speech.csv", ios::trunc);//trunc ����ļ�����������

		ofs.clear();

		this->initSpeech();

		this->creatSpeaker();

		this->loadRecord();

		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

speechManager::~speechManager()
{

}
