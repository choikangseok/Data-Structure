#pragma once
#include "CksItem.h"
class CksDNode : public CksItem
{
private:
	CksDNode* m_prev;//전단을 가리킬 노드포인터
	CksDNode* m_next;//후단을 가리킬 노드포인터
public:

	CksDNode(char* name="", int price=0, int priority=0, char*msg="...") : 
	  CksItem(name,price, priority, msg), m_prev(NULL), m_next(NULL) {//노드 생성자 
	}
	~CksDNode(void){}
	/*
	{
	//이미 부모생성자는 호출이되었기때문에 안됨->	CksItem(name, price);
		m_prev = NULL;
		m_next = NULL;
	}
	*/
	CksDNode* GetPrev()		{ return m_prev;}
	CksDNode* GetNext()		{ return m_next;}
	void SetPrev(CksDNode * n)	{m_prev = n;}
	void SetNext(CksDNode * n)	{m_next = n;}
	
	
	void AddNext(CksDNode *p ,CksDNode *n){
		//노드의 다음에 새로운 노드를 추가하게 된다.
		if(n != NULL){
			n->m_prev = p; //그림에서 (1) n->SetPrev(this);
			n->m_next = p->m_next; //		 (2) n->SetNext(m_next);
			if(p->m_next!=NULL)
				p->m_next->m_prev=n; //	 (3) m_next->setPrev(n);	
			p->m_next=n	;				//	 (4) SetNext(n);
			
		}
	}
	void Remove(){//해당하는 노드를 제거하는 함수.
		if(m_prev != NULL){
			m_prev->m_next=m_next;// m_prev->SetNext(m_next);
		}
		if(m_next != NULL){
			m_next->m_prev=m_prev;// m_next->SetNext(m_prev);
		}
	}
	void RevRecur(CksDNode* n, CksDNode* t){
		//n을 헤드에서 부터 시작해서 GetNext를 통해
		//마지막 노드가 아니면 재귀적으로 호출을해준다/
		if(n!=t)
			RevRecur(n->GetNext(), t);
		n->Print();//내용 출력	
	}

};