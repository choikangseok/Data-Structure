#pragma once
#include "CksDNode.h"

class CksDLList : public CksDNode{
	CksDNode m_org; //헤더 노드
public:
	CksDLList(void){};
	~CksDLList(void){Clear();};

	CksDNode* GetHead()		{ return m_org.GetNext();}
							//m_org객체가 가리키는 포인터(헤드포인터)를 반환해준다.
	bool IsEmpty()			{ return GetHead()==NULL ;}
							//헤드포인터가 가리키는 값이 빈 값인지 아닌지를 반환해준다.
	

	CksDNode* GetTail(){//마지막에 위치하는 노드 포인터를 반환해준다.
		CksDNode* tail = &m_org;
		for(; tail->GetNext() !=NULL ; tail = tail->GetNext());
		return tail;
	}
	void Display(char* list){//전체항목수를 출력한다
		printf("[%s 전체 항목 수 = %2d]\n", list, GetLength());
		for(CksDNode *p = GetHead() ; p != NULL; p= p->GetNext())
			//헤드포인터부터 시작해서 NULL값이 나올때까지 출력.
			p->Print();
		printf("\n");
	}
	void DisplayRev(char* list){ //전체항목수를 역순으로 출력한다.
		printf("[%s 전체 항목 수 = %2d]\n", list, GetLength());
		for(CksDNode *p = GetTail() ; p != &m_org; p= p->GetPrev())
			//헤드포인터부터 시작해서 NULL값이 나올때까지 출력.
			p->Print();
		printf("\n");
	}
	void DisplayRevRecur(char* list){
		printf("[%s 전체 항목 수 = %2d]\n", list, GetLength());
		CksDNode *p = GetHead(); //헤드부분을 대입을해준다.
		CksDNode *t = GetTail(); //마지막노드을 대입을해준다.
		RevRecur(p,t); //매개변수로 헤드, 테일을 넣어주어 재귀함수 RevRecur을 호출해준다.
	}
	void Remove(CksDNode* n){
		n->Remove();
		delete n;
	}
	
	
	void AddHead(CksDNode *n){
		//맨앞쪽에 노드를 추가해준다.
		AddNext(&m_org, n);
	}
	void AddTail(CksDNode *n){
		//맨뒤쪽에 노드를 추가해준다.
		AddNext(GetTail(), n);
	}
	
	
	void RemoveHead(){//맨앞쪽의 노드를 지워준다.
		CksDNode *p = GetHead();
		GetHead()->Remove();
		delete p;
	}
	void RemoveTail(){
		CksDNode *p = GetTail();
		GetTail()->Remove();
		delete p;
	}

	void Clear(){//마지막 노드가 빈값이 나올때까지 지워준다.
		while(!IsEmpty())
			RemoveHead();

	}

	CksDNode *FindPrev(CksDNode *n){
		//매개변수로 들어온 노드의 전 노드를 반환해줍니다.
		for(CksDNode* p=&m_org; p!=NULL; p = p->GetNext()){
			if(p->GetNext() == n)

				return p;
		}
		return NULL;
	}
	CksDNode *FindNodePriority(int val){
		//우선순위가 val인 노드포인터를 반환해줍니다.
		for(CksDNode* p = &m_org; p!=NULL; p = p->GetNext()){
			if(val==p->GetPriority()){
				return p;
			}
		}
		return NULL;

	}

	
	int GetLength(){ // 리스트 항목 개수 반환
      int count = 0;
      for(CksDNode* p = GetHead(); p != NULL; p = p->GetNext()) //마지막 데이터까지 반복
         count++; //count변수를 증가시켜준다.
      return count; //count변수를 반환해준다.
   }
	void Reverse(){
		CksDNode* head = GetHead();
		CksDNode* next;
		m_org.SetNext(NULL);
		for(; head != NULL; head = next){
			next = head->GetNext();
			AddHead(head);
		}
	}
	void Merge(CksDLList &list2){
		CksDNode* p=GetTail();   
		CksDNode* n=list2.GetHead();

		p->SetNext(n);
		n->SetPrev(p);
		CksDLList listT;
		list2=listT;
	}
};