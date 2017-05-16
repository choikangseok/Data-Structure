#pragma once
#include "CksItemNode.h"

class CksLinkedList : public  CksItemNode{
protected:
	CksItemNode m_org;//노드 객체.
public:
	CksLinkedList(): m_org(""){ //생성자.
	}
	~CksLinkedList(void) { Clear();}//소멸자 동적할당된 노드들을 지워줌.


	CksItemNode* GetHead()		{ return m_org.Next();}
							//m_org객체가 가리키는 포인터(헤드포인터)를 반환해준다.
	bool IsEmpty()			{ return GetHead()==NULL ;}
							//헤드포인터가 가리키는 값이 빈 값인지 아닌지를 반환해준다.
	

	CksItemNode* GetTail(){//마지막에 위치하는 노드 포인터를 반환해준다.
		CksItemNode* tail = &m_org;
		for(; tail->Next() !=NULL ; tail = tail->Next());
		return tail;
	}
	void Display(char* list){//전체항목수를 출력한다
		printf("[%s 전체 항목 수 = %2d]\n", list, GetLength());
		for(CksItemNode *p = GetHead() ; p != NULL; p= p->Next())
			//헤드포인터부터 시작해서 NULL값이 나올때까지 출력.
			p->Print();
		printf("\n");
	}
	
	
	void AddHead(CksItemNode *n){
		//맨앞쪽에 노드를 추가해준다.
		n->SetNext(GetHead());
		m_org.SetNext(n);
	}
	void AddTail(CksItemNode *n){
		//맨뒤쪽에 노드를 추가해준다.
		n->SetNext(NULL);
		AddNext(GetTail(), n);
	}

	void RemoveHead(){//맨앞쪽의 노드를 지워준다.
		Remove(GetHead());
	}
	void Remove(CksItemNode *n){// 노드 n을 지워준다.
		if(n==NULL)
			return;
		CksItemNode* prev = FindPrev(n);
		if(prev!=NULL)
		{		
			prev->RemoveNext();
			delete n;
		}
	}
	void Clear(){//마지막 노드가 빈값이 나올때까지 지워준다.
		while(!IsEmpty())
			Remove(GetTail());
	}

	CksItemNode *FindPrev(CksItemNode *n){
		//매개변수로 들어온 노드의 전 노드를 반환해줍니다.
		for(CksItemNode* p=&m_org; p!=NULL; p = p->Next()){
			if(p->Next() == n)

				return p;
		}
		return NULL;
	}
	CksItemNode *FindNodePriority(int val){
		//우선순위가 val인 노드포인터를 반환해줍니다.
		for(CksItemNode* p = &m_org; p!=NULL; p = p->Next()){
			if(val==p->GetPriority()){
				return p;
			}
		}
		return NULL;

	}

	void Merge(CksLinkedList &list2){
		CksItemNode* p;   
		p = GetHead();
		while( p->m_next != NULL )
			p = p->m_next;
		p->m_next = list2.GetHead();
		CksLinkedList listT;
		list2=listT;
	}
	void Reverse(){
		CksItemNode* head = GetHead();
		CksItemNode* next;
		m_org.SetNext(NULL);
		for(; head != NULL; head = next){
			next = head->Next();
			AddHead(head);
		}
	}
	int GetLength(){ // 리스트 항목 개수 반환
      int count = 0;
      for(CksItemNode* p = GetHead(); p != NULL; p = p->Next()) //마지막 데이터까지 반복
         count++; //count변수를 증가시켜준다.
      return count; //count변수를 반환해준다.
   }
};