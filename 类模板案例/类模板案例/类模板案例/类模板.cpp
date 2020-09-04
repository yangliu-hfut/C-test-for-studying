#include<iostream>
using namespace std;
#include"string"
#include"myArray.hpp"
void printIntArray(MyArray <int> & arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}
void test()
{
	//MyArray <int>array1(5);
	//MyArray<int>array2(array1);
	//MyArray<int>array3(100);
	//array3 = array1;
	MyArray <int>array1(5);

	for (int i = 0; i < 5; i++)
	{
		array1.push_back(i);
	}
	cout << "array1的打印输出为：  " << endl;
	printIntArray(array1);
	cout << "array1的容量为：  " <<array1.getCapacity()<< endl;
	cout << "array1的大小为：  " << array1.getSize() << endl;

	array1.delet_back();
	cout << "array1尾删除后：  " << endl;
	cout << "array1的容量为：  " << array1.getCapacity() << endl;
	cout << "array1的大小为：  " << array1.getSize() << endl;

}
int main()
{

	test();
	system("pause");
	return 0;
}