#include<iostream>
using namespace std;
#include"string"
#include<vector>
#include<algorithm>
/****************************************************************************************************************/
void myPrint(int val)
{
	cout << val << endl;
}
void test()
{
	vector<int> v;//����һ��vector����

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//vector<int>::iterator itBegin = v.begin();//��ʼ������ ָ�������е�һ��Ԫ��
	//vector<int>::iterator itEnd = v.end();//������������ָ������������һ��Ԫ�ص���һ��

	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}


	//for_each(v.begin(), v.end(), myPrint);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}
/****************************************************************************************************************/
//vector ����Զ�����������

	class Person1
	{
	public:
		Person1(string name,int age)
		{
			this->m_age = age;
			this->m_name = name;
		}
		int m_age;
		string m_name;
	};

	void test1()
	{
		
		vector<Person1> v1;

		Person1 p1("����", 23);
		Person1 p2("����", 22);
		Person1 p3("���", 21);
		Person1 p4("����", 20);
		Person1 p5("����", 19);

		v1.push_back(p1);
		v1.push_back(p2);
		v1.push_back(p3);
		v1.push_back(p4);
		v1.push_back(p5);

		for (vector<Person1>::iterator it1 = v1.begin();it1 !=v1.end();it1++)
		{
			cout << "������  " << (*it1).m_name<< "���䣺 " << (*it1).m_age << endl;
		}
	}

	void test2()
	{
		vector<Person1*> v1;

		Person1 p1("����", 23);
		Person1 p2("����", 22);
		Person1 p3("���", 21);
		Person1 p4("����", 20);
		Person1 p5("����", 19);

		v1.push_back(&p1);
		v1.push_back(&p2);
		v1.push_back(&p3);
		v1.push_back(&p4);
		v1.push_back(&p5);

		for (vector<Person1*>::iterator it =v1.begin();it != v1.end();it++)
		{
			cout << "������  " << (*it)->m_name << "���䣺 " << (*it)->m_age << endl;
		}

	}

	/****************************************************************************************************************/
	//����Ƕ������
	void test3()
	{
		vector<vector<int>>v;

		//����С����

		vector<int>v1;
		vector<int>v2;
		vector<int>v3;
		vector<int>v4;

		for (int i = 0; i < 4;i ++) 
		{
			v1.push_back(i + 1);
			v2.push_back(i + 2);
			v3.push_back(i + 3);
			v4.push_back(i + 4);
		}
		//С�������������

		v.push_back(v1);
		v.push_back(v2);
		v.push_back(v3);
		v.push_back(v4);

		for (vector< vector<int>>::iterator it = v.begin(); it != v.end(); it ++)
		{
			for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
			{
				cout << *vit << "  ";
			}
			cout << endl;
		}


	}
	 


