#pragma once
#include "CksItem.h"
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
	void AddNext(CksItemNode *p, CksItemNode *n){//�ش��ϴ� ��ġ�� ��带 �߰����ݴϴ�.
		n->SetNext(p->m_next);
		p->SetNext(n);
		//p=�����ִ� ���(�̰Ŵ����� �־���) n=�߰��ϴ� ���
	}
	CksItemNode* RemoveNext( ) {
		CksItemNode* p = m_next;
		//��带 ���Ÿ����ش�.
		if( p != NULL ) 
			m_next = p->m_next;
		return p;
	}
};