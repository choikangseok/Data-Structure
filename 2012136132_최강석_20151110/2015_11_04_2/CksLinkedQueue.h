#pragma once
#include "CksNode.h"

class CksLinkedQueue: public CksNode{
private:
	CksNode* m_front;//������ ����Ű�� ��庯��.
	CksNode* m_rear;//�Ĵ��� ����Ű�� ��庯��
	int m_nNodes;
public:
	CksLinkedQueue() : m_nNodes(0){
		m_front=m_rear= NULL;
		//�����ڿ� ������ �ʱ�ȭ.
	}
	
	~CksLinkedQueue(){//�Ҹ���.
		if(m_front != NULL) 
			delete m_front; ;
	}
	CksNode* GetHead(){ return m_front;}
	//��������͸� ��ȯ����.
	bool IsEmpty( ) { return GetHead() == NULL; }
	//��������Ͱ� NULL�� �ϰ��� ����ִ°����.
	

	void EnQueue (CksNode * e){
		// �Ĵܿ� ��带 �߰����ش�.
		if(IsEmpty())
			m_front = m_rear = e;
		else{
			m_rear->AddNext(e);
			m_rear = e;
		}
		m_nNodes++;
	}
	void Display()
	{	//���ڸ� ������ش�.
		//��� �����Ͱ� Null�϶����� ���ڸ� ��������ش�.
		printf("[��ü �׸��� �� %d��] : ",  m_nNodes);
		for(CksNode* p = GetHead(); p != NULL; p = p->Next())
			p->Display();
		printf("\n");
	}
	CksNode* DeQueue(){
		//���ܿ� ��带 �������ش�.
		if(IsEmpty()) return NULL;
		CksNode* n = m_front;
		if( m_front->GetLink()== NULL ) m_front = m_rear = NULL;
		else m_front = m_front->GetLink();
		m_nNodes--;
		return n;
	}
	CksNode* Peek(){
		//���� �տ��ִ� ��带 ��ȯ���ش�.
		CksNode *n = m_front;
		if(IsEmpty())
			return NULL;
		return n;

	}
		
};