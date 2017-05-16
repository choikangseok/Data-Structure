#pragma once
#include "CksItemP.h"
class CksItemNode : public CksItem
{
public:
	CksItemNode * m_next; //다음 노드를 가리키는 포인터.
	CksItemNode(char* name="", int price=0, int priority=0, char*msg="...") : 
	  CksItem(name,price, priority, msg) {//노드 생성자 
		m_next=NULL;
	}
	~CksItemNode(void){}
	CksItemNode* Next(){return m_next;}//다음 노드를 가리키는 포인터를 반환해 줍니다.
	void SetNext(CksItemNode *n){ //다음 노드를 가리키는 포인터를 설정합니다.
		m_next=n;
	}
};