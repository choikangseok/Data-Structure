#pragma once
#include "CksItemP.h"
class CksItemNode : public CksItem
{
public:
	CksItemNode * m_next; //���� ��带 ����Ű�� ������.
	CksItemNode(char* name="", int price=0, int priority=0, char*msg="...") : 
	  CksItem(name,price, priority, msg) {//��� ������ 
		m_next=NULL;
	}
	~CksItemNode(void){}
	CksItemNode* Next(){return m_next;}//���� ��带 ����Ű�� �����͸� ��ȯ�� �ݴϴ�.
	void SetNext(CksItemNode *n){ //���� ��带 ����Ű�� �����͸� �����մϴ�.
		m_next=n;
	}
};