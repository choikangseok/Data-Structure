#pragma once
#include "CksItem.h"
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
	void AddNext(CksItemNode *p, CksItemNode *n){//해당하는 위치에 노드를 추가해줍니다.
		n->SetNext(p->m_next);
		p->SetNext(n);
		//p=원래있던 노드(이거다음에 넣어줌) n=추가하는 노드
	}
	CksItemNode* RemoveNext( ) {
		CksItemNode* p = m_next;
		//노드를 제거를해준다.
		if( p != NULL ) 
			m_next = p->m_next;
		return p;
	}
};