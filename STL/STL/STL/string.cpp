#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

void test4()
{
	string s1; //¿ÕµÄ×Ö·û´®
	const char * s2 = "ÑîÁø";

	cout << "s2=" << s2 << endl;

	string s3(s2);
	cout << "s3=" << s3 << endl;

	string s4(20, 'a');
	cout << "s4=" << s4 << endl;


}
/***********************************************************************************************************/

void test5()
{
	string str = "hello";
	//[]·ÃÎÊµ¥¸ö×Ö·û
	for(int i = 0;i < str.size();i++)
	{
		cout << str[i] << "  ";
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << "  ";
	}
	cout << endl;

	str[0] = 'x';
	cout << str << endl;
}
