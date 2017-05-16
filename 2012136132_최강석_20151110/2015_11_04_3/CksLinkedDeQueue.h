#pragma once
#include "CksNode.h"

class CksLinkedDeQueue : public CksNode{
	CksNode* m_front;//전단을 가리키는 노드
	CksNode* m_rear;//후단을 가리키는 노드.
	int m_nNodes;
public:
	CksLinkedDeQueue() : m_nNodes(0){
		m_front=m_rear= NULL;//생성자.
	}
	
	~CksLinkedDeQueue(){
		if(m_front != NULL) 
			delete m_front; //소멸자
	}
	CksNode* GetHead(){ return m_front;}
	//헤드포인터 반환.

	bool IsEmpty( ) { return GetHead() == NULL; }
	//헤드포인터가 빈 값일 때

	void AddRear (CksNode * e){//후단 삽입.
		if(IsEmpty())
			m_front = m_rear = e;
		else{
			m_rear->AddNext(e);
			m_rear = e;
		}
		m_nNodes++;
	}
	void AddFront (CksNode * e){//전단 삽입
		if(IsEmpty())
			m_rear = m_front = e;
		else{
			m_front->AddPrev(e);
			m_front = e;
		}
		m_nNodes++;
	}
	void Display()
	{	//문자를 출력해준다.
		//헤드 포인터가 m_rear일때까지 문자를 출력을해준다.
		printf("[전체 항목의 수 %d개] : ",  m_nNodes);
		for(CksNode* p = GetHead(); p != NULL; p = p->Next())
			p->Display();
		printf("\n");
	}
	CksNode* DeleteFront(){//전단을 삭제합니다.
		if(IsEmpty()) return NULL;
		CksNode* n = m_front;
		if( m_front->Next()== NULL ) 
			m_front = m_rear = NULL;
		else 
			m_front = m_front->Next();
		m_nNodes--;
		return n;
	}
	CksNode* DeleteRear(){//후단을 삭제합니다.
		if(IsEmpty())return NULL;
		CksNode* n = m_rear;
		m_rear = m_rear->Prev();
		m_nNodes--;
		m_rear->m_link=NULL;//다음노드를 NULL값으로 설정해준다.
		return n;
	}
	
		
};