#pragma once;
#include <string.h>
#include<stdio.h>
class CksItem{
protected:
	char m_name[40]; //ǰ���̸�
	int m_price; //����
	int priority; // �켱����
	char msg[40]; // �޼���
public:
	CksItem(char* name="", int price =0, int priority=0, char*msg="..."){//������.
		m_price= price;
		strcpy(m_name, name);
		this->priority=priority;
		strcpy(this->msg, msg);
	}
	~CksItem(void){}
	int GetPriority(){return priority;}
	void Print(){//Ŭ���� ��������� ���
		printf("[����] : %8s [����] : %10d [�켱����] : %3d [�޼���] : %20s \n", m_name, m_price, priority, msg);
	}
};