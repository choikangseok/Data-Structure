#pragma once
#include "CksElement.h"

class CksNode : public CksElement // 연결된 스택을 위한 노드 클래스
{
	CksNode* m_link; // 다음 노드를 가리키는 포인터 변수
public:
	CksNode(int num = 0) : CksElement(num) { 
		//생성자
		m_link = NULL; 
	}
	~CksNode(void) { }
	//소멸자
	CksNode* GetLink(){
		return m_link;	
	}
	CksNode* Next() {
		//다음 노드를 가리키는 노드 포인터를 반환해준다.
		return m_link;
	}

	void SetLink(CksNode *p) {
		m_link = p; 
		//다음 노드를 가리키는 노드 포인터를 설정해준다.
	}
	void AddNext(CksNode *p) {
		// 새로운 노드를 가리키는 노드 포인터를 추가해준다.
		if( p != NULL ) {
			p->m_link = m_link;
			m_link = p;
		}
	}
	
	CksNode* RemoveNext( ) {
		CksNode* p = m_link;
		//노드를 제거를해준다.
		if( p != NULL ) 
			m_link = p->m_link;
		return p;
	}

};