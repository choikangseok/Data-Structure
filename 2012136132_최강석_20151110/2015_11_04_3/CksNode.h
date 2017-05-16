#pragma once
#include "CksElement.h"

class CksNode : public CksElement // 연결된 스택을 위한 노드 클래스
{
public:
	CksNode* m_link; // 다음 노드를 가리키는 포인터 변수
	CksNode* f_link; // 전 노드를 가리키는 포인터 변수.
	CksNode(int num = 0) : CksElement(num) { 
		//생성자
		m_link = NULL; 
		f_link = NULL;
	}
	~CksNode(void) { }
	//소멸자
	CksNode* Next(){return m_link;}///앞을 가리키는 노드 반환.
	CksNode* Prev(){return f_link;}//이전을 가리키는 노드 반환.
	void AddNext(CksNode *p){//후단에 노드를 더해줌
		m_link = p;
		p->f_link = this;
		p->m_link = NULL;
	}
	void AddPrev(CksNode *p){//전단에 노드를 더해줌
		f_link = p;
		p->m_link = this;
		p->f_link = NULL;
	}
	
};