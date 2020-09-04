#include<iostream>
using namespace std;
#include"string"

//1.数组排序部分
/*******************************************************************************/
//打印数组模板
template<class T>
void dayin(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
void jiaohuan(T&a,T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

//
template<class T>
void paixu(T arr[] , int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			jiaohuan(arr[max],arr[i]);
		}
	}
}

//
void test()
{
	char x = {};
	cout << "请输入进行排序的字母： " << endl;
	cin >> x;
	char charArr[] = "adcsd";
	int num = sizeof(charArr) / sizeof(char) - 1;
	paixu(charArr,num);
	dayin(charArr,num);
}
/*******************************************************************************/

//2.普通函数和函数模板区别
/*******************************************************************************/
//普通函数
int add1(int a,int b)
{
	return a + b;
}

//函数模板
template<class T>
T add2(T a,T b)
{
	return a + b;
}
void test1()
{
	int a = 100;
	int b = 200;
	char c = 'c';
	cout << add1(a, b) << endl;
	//显示指定类型
	cout << add2< int > (a, c) << endl;
}
/*******************************************************************************/

//3.普通函数与函数模板调用规则
/*******************************************************************************/
void dy(int a,int b)
{
	cout << "普通函数" << endl;
}

template<class T>
void dy(T a, T b)
{
	cout << "模板函数1" << endl;
}

template<class T>
void dy(T a, T b,T c)
{
	cout << "模板函数2" << endl;
}

void test2()
{
	//dy(3, 4);
	dy<>(3, 4,5);
}
/*******************************************************************************/

//4.模板局限性
/*******************************************************************************/
class Person
{
public:
	Person(string name,int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}

	int m_Age;
	string m_Name;

};
template<class T>
bool db(T &a, T &b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template<> bool db(Person &p1, Person &p2)//具体化模板
{
	if (p1.m_Age == p2.m_Age&&p1.m_Name == p2.m_Name)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void test3()
{
	Person p1("杨柳",18);
	Person p2("杨柳", 19);

	bool ret = db(p1, p2);
	if (ret)
	{
		cout << "p1和p2一样。" << endl;

	}
	else
	{
		cout << "p1和p2不一样。" << endl;
	}
}
/*******************************************************************************/

//5.类模板
/*******************************************************************************/
template<class NameType , class AgeType>
class Person1
{
public:
	Person1(NameType name , AgeType age)
	{
		this->age = age;
		this->name = name;
	}

	void showPerson()
	{
		cout << "姓名：" << this->name << "年龄：" << this->age << endl;
	}

	NameType name;
	AgeType age;

};
void test4()
{
	Person1 <string, int> p1("鲍宇", 20);
	p1.showPerson();
}
/*******************************************************************************/


//6.类模板和函数模板区别
/*******************************************************************************/
template<class NameType, class AgeType = int>
class Person2
{
public:
	Person2(NameType name, AgeType age)
	{
		this->age = age;
		this->name = name;
	}

	void showPerson1()
	{
		cout << "姓名：" << this->name << "年龄：" << this->age << endl;
	}

	NameType name;
	AgeType age;

};
void test5()
{
	Person2<string>p("鲍宇", 25);
	p.showPerson1();
}
/*******************************************************************************/
//7.类模板中成员函数创建时机
/*******************************************************************************/

/*******************************************************************************/
//8.类模板对象做函数参数
/*******************************************************************************/
template<class NameType, class AgeType = int>
class Person3
{
public:
	Person3(NameType name, AgeType age)
	{
		this->age = age;
		this->name = name;
	}

	void showPerson2()
	{
		cout << "姓名：" << this->name << "    年龄：" << this->age << endl;
	}

	NameType name;
	AgeType age;

};


void printPerson(Person3<string, int>&p3)
{
	p3.showPerson2();
}

//1
void test6()
{
	Person3<string,int>p3("昊天",19);
	printPerson(p3);

}
//2
template<class T1,class T2>
void printPerson1(Person3<T1,T2>&p)
{
	p.showPerson2();
}
void test7()
{
	Person3<string, int>p3("东明", 19);
	printPerson(p3);

}
//3
template<class T>
void printPerson1(T &p)
{
	p.showPerson2();
}
void test8()
{
	Person3<string, int>p3("杨柳", 19);
	printPerson(p3);

}

/*******************************************************************************/




//9.类模板与继承
/*******************************************************************************/
template<class T>
class Father
{
	T f;
};

class Son :public Father<int>
{

};
template<class T>
class Son2 :public Father<T>
{

};

/*******************************************************************************/

//10.类模板成员函数类外实现
/*******************************************************************************/
template<class NameType, class AgeType>
class Person4
{
public:
	Person4(NameType name, AgeType age);
	//{
	//	this->age = age;
	//	this->name = name;
	//}

	void showPerson3();
	//{
	//	cout << "姓名：" << this->name << "    年龄：" << this->age << endl;
	//}

	NameType name;
	AgeType age;

};

template<class NameType, class AgeType>
Person4<NameType, AgeType>::Person4(NameType name, AgeType age)//格式，加模板参数列表
{
	this->age = age;
	this->name = name;
}

//
template<class NameType, class AgeType>

void Person4<NameType, AgeType>::showPerson3()
{
	cout << "姓名：" << this->name << "    年龄：" << this->age << endl;
}

void test9()
{
	Person4<string,int> p("鲍宇",18);
	p.showPerson3();

}
/*******************************************************************************/

//11.类模板分文件编写问题
/*******************************************************************************/
template<class NameType, class AgeType>
class Person5
{
public:
	Person5(NameType name, AgeType age);


	void showPerson4();

	NameType name;
	AgeType age;

};
template<class NameType, class AgeType>
Person5<NameType, AgeType>::Person5(NameType name, AgeType age)
{
	this->name = name;
	this->age = age;
}

template<class NameType, class AgeType>
void Person5<NameType, AgeType>::showPerson4()
{
	cout << "姓名：" << this->name << "    年龄：" << this->age << endl;
}




/*******************************************************************************/

//12.类模板与友元
/*******************************************************************************/
template<class NameType, class AgeType>
class Person6;

template<class NameType, class AgeType>
 void printPerson2(Person6<NameType, AgeType>p)
{
	cout << "姓名：" << p.name << "    年龄：" << p.age << endl;
}



template<class NameType, class AgeType>
class Person6
{
	friend void printPerson(Person6<NameType,AgeType>p)
	{
		cout << "姓名：" <<p.name << "    年龄：" << p.age << endl;
	}

	friend void printPerson2<>(Person6<NameType, AgeType>p);
public:

	Person6(NameType name, AgeType age);

private:
	NameType name;
	AgeType age;

};
template<class NameType, class AgeType>
Person6<NameType, AgeType>::Person6(NameType name, AgeType age)
{
	this->name = name;
	this->age = age;
}

void test10()
{
	Person6<string, int>p("昊天", 18);
	printPerson(p);
}

void test11()
{
	Person6<string, int>p("东明", 18);
	printPerson2(p);
}

/*******************************************************************************/
int main()
{
	//test();
	//test1();
	/*test2();*/
	/*test3();*/
	//test4();
	//test5();
	//test9();
	test11();

	system("pause");
	return 0;
}