#pragma once
#include<iostream>
using namespace std;
#include"string"

template<class T>
class MyArray
{
public:
	//�вι���
	MyArray(int capacity)
	{
		cout << "�вι������" << endl;
		this->m_Capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//��������
	MyArray(const MyArray& array)
	{
		cout << "�����������" << endl;
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
		cout << "operator=����" << endl;
		//�ж϶����Ƿ������ݣ��еĻ������ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_size = 0;
		}

		//���
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
	//��������
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			cout << "��������" << endl;
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T * pAddress;
	int m_Capacity;
	int m_size;
};