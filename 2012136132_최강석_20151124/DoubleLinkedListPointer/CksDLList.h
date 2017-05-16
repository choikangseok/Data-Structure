#pragma once
#include "CksDNode.h"

class CksDLList : public CksDNode{
	CksDNode *m_org; //헤더 포인터
public:
	CksDLList(void){m_org=NULL;};
	~CksDLList(void){};

	CksDNode* GetHead()		{ return m_org;}
							//m_org객체가 가리키는 포인터(헤드포인터)를 반환해준다.
	bool IsEmpty()			{ return m_org==NULL ;}
							//헤드포인터가 가리키는 값이 빈 값인지 아닌지를 반환해준다.
	

	CksDNode* GetTail(){//마지막에 위치하는 노드 포인터를 반환해준다.
		CksDNode* tail = m_org;
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
		for(CksDNode *p = GetTail() ; p != NULL; p= p->GetPrev())
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
	void Remove(CksDNode* n){//n을 매개변수로 받아서 n과 앞뒤와의 연결을
							//끊어주고  앞뒤를 연결시켜준다.
		for(CksDNode * p = GetHead(); p!=NULL; p = p->GetNext() )
			if(n==GetHead()){
				if(n->m_next==NULL)//m_org가 하나가 남을경우 조건을 걸어주어 지워준다.
					m_org=NULL;
				else{
					m_org = m_org->m_next; 
					m_org ->m_prev=NULL;
				}
			}
			else if(p->m_next == n){//우선순위에 해당되 는 노드가 나올 경우
				p->m_next=n->m_next;//p의 m_next링크가 가리키는 연결을 n 노드가 가리는 연결로 복사한다.
				if(n->m_next!=NULL)//조건문을 걸어 만약 n의 다음 노드가 NULL이 아닐 경우   
					n->m_next->m_prev=p;//n의 다음 노드의 m_prev링크가 p를 가리키게 한다.
			}
		delete n;

      }
	void AddHead(CksDNode *n){
		//맨앞쪽에 노드를 추가해준다.
 	  if(IsEmpty()){
		  //m_org에 아무값도 없을경우.
         m_org = n;
      }
      else{
		  //n을 앞쪽에 넣어주고 기존에 있던 노드와 연결을시켜준다.
         n->SetNext(m_org); 
		 m_org->SetPrev(n);
		 m_org = n; 
      }
	}
	void AddTail(CksDNode *n){
		//맨뒤쪽에 노드를 추가해준다.
		if (IsEmpty()){
        n->SetNext(NULL);
		n->SetPrev(NULL);
         m_org = n;
      }
      else
		 n->SetPrev(GetTail());
         GetTail()->SetNext(n);
		 n->SetNext(NULL);
		 
		
	}

	void RemoveHead(){//맨앞쪽의 노드를 지워준다.
		Remove(GetHead());
	}
	void RemoveTail(){   
		Remove(GetTail());
	}

	void Clear(){//마지막 노드가 빈값이 나올때까지 지워준다.
		while(!IsEmpty())
			RemoveHead();	
	}

	CksDNode *FindPrev(CksDNode *n){
		//매개변수로 들어온 노드의 전 노드를 반환해줍니다.
		for(CksDNode* p=m_org; p!=NULL; p = p->GetNext()){
			if(p->GetNext() == n)
				return p;
		}
		return NULL;
	}
	CksDNode *FindNodePriority(int val){
		//우선순위가 val인 노드포인터를 반환해줍니다.
		for(CksDNode* p = m_org; p!=NULL; p = p->GetNext()){
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
		CksDNode* head = m_org->m_next;
		CksDNode* next;
		m_org->m_next=NULL;
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