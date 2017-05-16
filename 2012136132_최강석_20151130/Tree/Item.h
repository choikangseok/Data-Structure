#pragma once;
#include <string.h>
#include<stdio.h>
class Item{
protected:
	char m_name[40]; //ǰ���̸�
	int m_price; //����
	int priority; // �켱����
	char msg[40]; // �޼���
public:
	Item(int priority=0, char* name="", int price=0, char*msg="..."){//������.
		m_price= price;
		strcpy(m_name, name);
		this->priority=priority;
		strcpy(this->msg, msg);
	}
	~Item(void){}
	void Print(){//Ŭ���� ��������� ���
		printf("[�켱����] : %3d [����] : %8s [����] : %10d [�޼���] : %20s \n", priority, m_name, m_price, msg);
	}
};