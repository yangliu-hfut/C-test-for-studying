#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>

class GreatFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 15; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreatFive());

	if (it == v.end())
	{
		cout << "没有找到！" << endl;
	}
	else
	{
		cout << "找到大于五的数字为： " << *it << endl;
	}
}
//二元谓词
class MyCompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);

	sort(v.begin(), v.end());

	for (vector<int>::iterator it =v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	//改变排序规则

	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	sort(v.begin(), v.end(), less<int>());//内建函数对象
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{

	test02();
	system("pause");
	return 0;
}