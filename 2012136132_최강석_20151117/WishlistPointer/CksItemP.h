#pragma once;
#include <string.h>
#include<stdio.h>
class CksItem{
protected:
	char m_name[40]; //품목이름
	int m_price; //가격
	int priority; // 우선순위
	char msg[40]; // 메세지
public:
	CksItem(char* name="", int price =0, int priority=0, char*msg="..."){//생성자.
		m_price= price;
		strcpy(m_name, name);
		this->priority=priority;
		strcpy(this->msg, msg);
	}
	~CksItem(void){}
	int GetPriority(){return priority;}
	void Print(){//클래스 멤버변수들 출력
		printf("[물건] : %8s [가격] : %10d [우선순위] : %3d [메세지] : %20s \n", m_name, m_price, priority, msg);
	}
};