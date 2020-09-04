#pragma once
#include<iostream>
using namespace std;
#include"string"

template<class T>
class MyArray
{
public:
	//有参构造
	MyArray(int capacity)
	{
		cout << "有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& array)
	{
		cout << "拷贝构造调用" << endl;
		this->m_Capacity = array.m_Capacity;
		this->m_size = array.m_size;

		this->pAddress = new T[array.m_Capacity];

		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = array.pAddress[i];
		}
	}

	//operator=
	MyArray& operator=(const MyArray& array)
	{
		cout << "operator=调用" << endl;
		//判断堆区是否有数据，有的话，先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_size = 0;
		}

		//深拷贝
		this->m_Capacity = array.m_Capacity;
		this->m_size = this->m_size;
		this->pAddress = new T[array.m_Capacity];

		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = array.pAddress[i];
		}
		return *this;
	}

	void push_back(const T & val)
	{
		if (this->m_Capacity == this->m_size)
		{
			return;
		}
		this->pAddress[this->m_size] = val;
		this->m_size++;
	}

	void delet_back()
	{
		if (this->m_size = 0)
		{
			return;
		}
		this->m_size--;
	}

	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	int getCapacity()
	{
		return this->m_Capacity;
	}

	int getSize()
	{
		return this->m_size;
	}
	//析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			cout << "析构调用" << endl;
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T * pAddress;
	int m_Capacity;
	int m_size;
};