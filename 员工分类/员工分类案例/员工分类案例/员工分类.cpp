#include<iostream>
using namespace std;
#include<string>
#include<deque>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Student
{
public:
	string m_Name;
	int m_Salary;
};

void creatStudent(vector<Student>&v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Student student;
		student.m_Name = "员工";
		student.m_Name += nameSeed[i];

		student.m_Salary = rand() % 10000 + 10000;

		v.push_back(student); 
	}
}

void setGroup(vector<Student>&v, multimap<int, Student>&m)
{
	for (vector<Student>::iterator it = v.begin(); it != v.end();it++)
	{
		int deptID = rand() % 3;

		m.insert(make_pair(deptID, *it));
	}
}

void showStudentByGroup(multimap<int,Student>&s)
{
	cout << "策划部门： " << endl;
	multimap<int, Student>::iterator pos = s.find(CEHUA);

	int count = s.count(CEHUA);
	int index = 0;

	for (;pos != s.end() && index < count ;index++,pos++)
	{
		cout << "学生姓名： " << pos->second.m_Name << "科研补助： " << pos->second.m_Salary << endl;
	}
	cout << "------------------------------------------" << endl;
	cout << "美术部门： " << endl;
     pos = s.find(MEISHU);

	 count = s.count(MEISHU);
	 index = 0;

	for (; pos != s.end() && index < count; index++, pos++)
	{
		cout << "学生姓名： " << pos->second.m_Name << "科研补助： " << pos->second.m_Salary << endl;
	}
	cout << "------------------------------------------" << endl;
	cout << "研发部门： " << endl;
	pos = s.find(YANFA);

	count = s.count(YANFA);
	index = 0;

	for (; pos != s.end() && index < count; index++, pos++)
	{
		cout << "学生姓名： " << pos->second.m_Name << "科研补助： " << pos->second.m_Salary << endl;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	vector<Student>vstudent;
	creatStudent(vstudent);

	multimap<int, Student>mstudent;
	setGroup(vstudent, mstudent);

	showStudentByGroup(mstudent);

	system("pause");
	return 0;
}