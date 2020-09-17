#include<iostream>
using namespace std;
#include<string>
#include<deque>
#include<vector>
#include<list>
#include<algorithm>

void printDeque(deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "  ";
	}

	cout << endl;
}
void test7()
{
	deque<int>d1;
	for (int i = 0;i < 10 ; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	
	deque<int>d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int>d3(10,100);
	printDeque(d3);

	deque<int>d4(d3);
	printDeque(d4);



}
/********************************************************************************************************************/
void test8()
{
	deque<int>d1;

	d1.push_back(100);
	d1.push_back(500);
	printDeque(d1);

	d1.push_front(200);
	printDeque(d1);

	d1.pop_back();
	printDeque(d1);

	d1.pop_front();
	printDeque(d1);

	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	printDeque(d1);

	d1.insert(d1.begin(), 700);
	printDeque(d1);


}
/********************************************************************************************************************/
class Person2
{  
public:
	Person2(string name,int score)
	{
		this->m_Score = score;
		this->m_Name = name;
	}
	string m_Name;
	int m_Score;
};
void creatPerson(vector<Person2>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0;i < 5;i ++)
	{
		string name = "选手";
		name += nameSeed[i];
		int score = 0;

		Person2 p(name, score);

		v.push_back(p);
		
	}
}

void setScore(vector<Person2>&v)
{
	for (vector<Person2>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		cout << "选手：  " << it->m_Name << "打分是： " << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;

		sort(d.begin(), d.end());

		d.pop_back();
		d.pop_front();//去除最低最高分

		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();
		it->m_Score = avg;

	}
}

void showScore(vector<Person2>&v)
{
	for (vector<Person2>::iterator it = v.begin();it !=v.end(); it++)
	{
		cout << "姓名：  " << it->m_Name << "所得平均分是： " << it->m_Score << endl;
	}
}
/********************************************************************************************************************/
//排序案例
//排序规则

class Student
{
public:
	Student(string name, int age, int hight)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = hight;
	}
public:
	string m_Name;
	int m_Age;
	int m_Height;
};
bool compareStudent(Student &s1, Student &s2)
{
	if (s1.m_Age == s1.m_Age)
	{
		return s1.m_Height < s2.m_Height;
	
	}
	else
	{
		return s1.m_Age > s2.m_Age;
	}
}
void test9()
{
	list<Student>S;

	Student s1("鲍宇", 22, 178);
	Student s2("东明", 23, 175);
	Student s3("杨柳", 23, 170);
	Student s4("昊天", 21, 173);
	Student s5("旺林", 25, 172);

	S.push_back(s1);
	S.push_back(s2);
	S.push_back(s3);
	S.push_back(s4);
	S.push_back(s5);
	
	for (list<Student>::iterator it = S.begin(); it != S.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << "   年龄：" << it->m_Age << "    身高：" << it->m_Height << endl;
	}
	cout << "排序后" << endl;

	S.sort(compareStudent);

	for (list<Student>::iterator it = S.begin(); it != S.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << "   年龄：" << it->m_Age << "    身高：" << it->m_Height << endl;
	}
}
int main()
{
	//vector<Person2>v;
	//creatPerson(v);

	//setScore(v);

	//showScore(v);
	test9();
	system("pause");
	return 0;

}