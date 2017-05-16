#pragma once
#include "CksItem.h"
class CksDNode : public CksItem
{
private:
	CksDNode* m_prev;//������ ����ų ���������
	CksDNode* m_next;//�Ĵ��� ����ų ���������
public:

	CksDNode(char* name="", int price=0, int priority=0, char*msg="...") : 
	  CksItem(name,price, priority, msg), m_prev(NULL), m_next(NULL) {//��� ������ 
	}
	~CksDNode(void){}
	/*
	{
	//�̹� �θ�����ڴ� ȣ���̵Ǿ��⶧���� �ȵ�->	CksItem(name, price);
		m_prev = NULL;
		m_next = NULL;
	}
	*/
	CksDNode* GetPrev()		{ return m_prev;}
	CksDNode* GetNext()		{ return m_next;}
	void SetPrev(CksDNode * n)	{m_prev = n;}
	void SetNext(CksDNode * n)	{m_next = n;}
	
	
	void AddNext(CksDNode *p ,CksDNode *n){
		//����� ������ ���ο� ��带 �߰��ϰ� �ȴ�.
		if(n != NULL){
			n->m_prev = p; //�׸����� (1) n->SetPrev(this);
			n->m_next = p->m_next; //		 (2) n->SetNext(m_next);
			if(p->m_next!=NULL)
				p->m_next->m_prev=n; //	 (3) m_next->setPrev(n);	
			p->m_next=n	;				//	 (4) SetNext(n);
			
		}
	}
	void Remove(){//�ش��ϴ� ��带 �����ϴ� �Լ�.
		if(m_prev != NULL){
			m_prev->m_next=m_next;// m_prev->SetNext(m_next);
		}
		if(m_next != NULL){
			m_next->m_prev=m_prev;// m_next->SetNext(m_prev);
		}
	}
	void RevRecur(CksDNode* n, CksDNode* t){
		//n�� ��忡�� ���� �����ؼ� GetNext�� ����
		//������ ��尡 �ƴϸ� ��������� ȣ�������ش�/
		if(n!=t)
			RevRecur(n->GetNext(), t);
		n->Print();//���� ���	
	}

};