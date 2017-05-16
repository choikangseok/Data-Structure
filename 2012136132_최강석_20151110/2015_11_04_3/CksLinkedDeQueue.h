#pragma once
#include "CksNode.h"

class CksLinkedDeQueue : public CksNode{
	CksNode* m_front;//������ ����Ű�� ���
	CksNode* m_rear;//�Ĵ��� ����Ű�� ���.
	int m_nNodes;
public:
	CksLinkedDeQueue() : m_nNodes(0){
		m_front=m_rear= NULL;//������.
	}
	
	~CksLinkedDeQueue(){
		if(m_front != NULL) 
			delete m_front; //�Ҹ���
	}
	CksNode* GetHead(){ return m_front;}
	//��������� ��ȯ.

	bool IsEmpty( ) { return GetHead() == NULL; }
	//��������Ͱ� �� ���� ��

	void AddRear (CksNode * e){//�Ĵ� ����.
		if(IsEmpty())
			m_front = m_rear = e;
		else{
			m_rear->AddNext(e);
			m_rear = e;
		}
		m_nNodes++;
	}
	void AddFront (CksNode * e){//���� ����
		if(IsEmpty())
			m_rear = m_front = e;
		else{
			m_front->AddPrev(e);
			m_front = e;
		}
		m_nNodes++;
	}
	void Display()
	{	//���ڸ� ������ش�.
		//��� �����Ͱ� m_rear�϶����� ���ڸ� ��������ش�.
		printf("[��ü �׸��� �� %d��] : ",  m_nNodes);
		for(CksNode* p = GetHead(); p != NULL; p = p->Next())
			p->Display();
		printf("\n");
	}
	CksNode* DeleteFront(){//������ �����մϴ�.
		if(IsEmpty()) return NULL;
		CksNode* n = m_front;
		if( m_front->Next()== NULL ) 
			m_front = m_rear = NULL;
		else 
			m_front = m_front->Next();
		m_nNodes--;
		return n;
	}
	CksNode* DeleteRear(){//�Ĵ��� �����մϴ�.
		if(IsEmpty())return NULL;
		CksNode* n = m_rear;
		m_rear = m_rear->Prev();
		m_nNodes--;
		m_rear->m_link=NULL;//������带 NULL������ �������ش�.
		return n;
	}
	
		
};