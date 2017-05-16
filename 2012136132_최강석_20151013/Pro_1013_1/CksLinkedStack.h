#pragma once
#include "CksNode.h"
class CksLinkedStack
{
	CksNode m_org; // 헤드 포인터
public:
	CksLinkedStack() { m_org = NULL; } // 생성자
	~CksLinkedStack() { while(!IsEmpty()) delete Pop();} // 소멸자

	CksNode* GetHead(){ return m_org.Next(); }
	//노드의 방향을 가리키는 함수
	bool IsEmpty( ) { return GetHead() == NULL; }
	//노드가 없을경우 노드가 가리키는 방향을 빈값으로 해준다.
	void AddHead(CksNode *n){
		m_org.AddNext(n);
		//노드를 추가해준다.
	}
	
	CksNode* RemoveHead(){//노드의 헤드포인터를 제거.
		return m_org.RemoveNext();
	}

	void clear(){
		//노드가 빈 값일 때까지
		//헤드 포인터를 소멸한다.
		while(!IsEmpty())
			delete RemoveHead();
	}

	void Push(char ch) {
		AddHead(new CksNode(ch));
		//ch를  갖는 노드를 동적할당하여 추가해준다.
	}
	void Reset(){ 
		clear();
		m_org.SetLink(NULL);
		//초기화를 해줌.
	}

	CksNode* Pop() {
		//비어있을 경우 예외처리를 해준다.
		if(IsEmpty()){
			return 0;
		}
		return RemoveHead();
		//헤드포인터를 제거해준다.
	}
	CksNode* Peek(){
		//비어있을 경우 예외처리를 해준다.
		if(IsEmpty()){
			return 0;
		}
		return GetHead();
		//헤드가 가리키는 값을 반환한다.
	}

	int GetLength()
	{// 포인터가 다음 노드를 가리킬때 빈값이 나올때까지 count를 해준다.
		
		int count = 0;
		for(CksNode* p = GetHead(); p!=NULL; p=p->Next())
			count++;
		return count;
	}

	void Display()
	{	//문자를 출력해준다.
		//헤드 포인터가 Null일때까지 문자를 출력을해준다.
		printf("[%d문자]", GetLength());
		for(CksNode* p = GetHead(); p != NULL; p = p->Next())
			p->Display();
		printf("\n");
	}
};