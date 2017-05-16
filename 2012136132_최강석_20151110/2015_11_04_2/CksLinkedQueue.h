#pragma once
#include "CksNode.h"

class CksLinkedQueue: public CksNode{
private:
	CksNode* m_front;//전단을 가리키는 노드변수.
	CksNode* m_rear;//후단을 가리키는 노드변수
	int m_nNodes;
public:
	CksLinkedQueue() : m_nNodes(0){
		m_front=m_rear= NULL;
		//생성자에 변수들 초기화.
	}
	
	~CksLinkedQueue(){//소멸자.
		if(m_front != NULL) 
			delete m_front; ;
	}
	CksNode* GetHead(){ return m_front;}
	//헤드포인터를 반환해줌.
	bool IsEmpty( ) { return GetHead() == NULL; }
	//헤드포인터가 NULL값 일경우는 비어있는경우임.
	

	void EnQueue (CksNode * e){
		// 후단에 노드를 추가해준다.
		if(IsEmpty())
			m_front = m_rear = e;
		else{
			m_rear->AddNext(e);
			m_rear = e;
		}
		m_nNodes++;
	}
	void Display()
	{	//문자를 출력해준다.
		//헤드 포인터가 Null일때까지 문자를 출력을해준다.
		printf("[전체 항목의 수 %d개] : ",  m_nNodes);
		for(CksNode* p = GetHead(); p != NULL; p = p->Next())
			p->Display();
		printf("\n");
	}
	CksNode* DeQueue(){
		//전단에 노드를 제거해준다.
		if(IsEmpty()) return NULL;
		CksNode* n = m_front;
		if( m_front->GetLink()== NULL ) m_front = m_rear = NULL;
		else m_front = m_front->GetLink();
		m_nNodes--;
		return n;
	}
	CksNode* Peek(){
		//제일 앞에있는 노드를 반환해준다.
		CksNode *n = m_front;
		if(IsEmpty())
			return NULL;
		return n;

	}
		
};