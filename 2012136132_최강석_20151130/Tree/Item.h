#pragma once;
#include <string.h>
#include<stdio.h>
class Item{
protected:
	char m_name[40]; //품목이름
	int m_price; //가격
	int priority; // 우선순위
	char msg[40]; // 메세지
public:
	Item(int priority=0, char* name="", int price=0, char*msg="..."){//생성자.
		m_price= price;
		strcpy(m_name, name);
		this->priority=priority;
		strcpy(this->msg, msg);
	}
	~Item(void){}
	void Print(){//클래스 멤버변수들 출력
		printf("[우선순위] : %3d [물건] : %8s [가격] : %10d [메세지] : %20s \n", priority, m_name, m_price, msg);
	}
};