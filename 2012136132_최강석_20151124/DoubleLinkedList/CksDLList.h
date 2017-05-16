#pragma once
#include "CksDNode.h"

class CksDLList : public CksDNode{
	CksDNode m_org; //��� ���
public:
	CksDLList(void){};
	~CksDLList(void){Clear();};

	CksDNode* GetHead()		{ return m_org.GetNext();}
							//m_org��ü�� ����Ű�� ������(���������)�� ��ȯ���ش�.
	bool IsEmpty()			{ return GetHead()==NULL ;}
							//��������Ͱ� ����Ű�� ���� �� ������ �ƴ����� ��ȯ���ش�.
	

	CksDNode* GetTail(){//�������� ��ġ�ϴ� ��� �����͸� ��ȯ���ش�.
		CksDNode* tail = &m_org;
		for(; tail->GetNext() !=NULL ; tail = tail->GetNext());
		return tail;
	}
	void Display(char* list){//��ü�׸���� ����Ѵ�
		printf("[%s ��ü �׸� �� = %2d]\n", list, GetLength());
		for(CksDNode *p = GetHead() ; p != NULL; p= p->GetNext())
			//��������ͺ��� �����ؼ� NULL���� ���ö����� ���.
			p->Print();
		printf("\n");
	}
	void DisplayRev(char* list){ //��ü�׸���� �������� ����Ѵ�.
		printf("[%s ��ü �׸� �� = %2d]\n", list, GetLength());
		for(CksDNode *p = GetTail() ; p != &m_org; p= p->GetPrev())
			//��������ͺ��� �����ؼ� NULL���� ���ö����� ���.
			p->Print();
		printf("\n");
	}
	void DisplayRevRecur(char* list){
		printf("[%s ��ü �׸� �� = %2d]\n", list, GetLength());
		CksDNode *p = GetHead(); //���κ��� ���������ش�.
		CksDNode *t = GetTail(); //����������� ���������ش�.
		RevRecur(p,t); //�Ű������� ���, ������ �־��־� ����Լ� RevRecur�� ȣ�����ش�.
	}
	void Remove(CksDNode* n){
		n->Remove();
		delete n;
	}
	
	
	void AddHead(CksDNode *n){
		//�Ǿ��ʿ� ��带 �߰����ش�.
		AddNext(&m_org, n);
	}
	void AddTail(CksDNode *n){
		//�ǵ��ʿ� ��带 �߰����ش�.
		AddNext(GetTail(), n);
	}
	
	
	void RemoveHead(){//�Ǿ����� ��带 �����ش�.
		CksDNode *p = GetHead();
		GetHead()->Remove();
		delete p;
	}
	void RemoveTail(){
		CksDNode *p = GetTail();
		GetTail()->Remove();
		delete p;
	}

	void Clear(){//������ ��尡 ���� ���ö����� �����ش�.
		while(!IsEmpty())
			RemoveHead();

	}

	CksDNode *FindPrev(CksDNode *n){
		//�Ű������� ���� ����� �� ��带 ��ȯ���ݴϴ�.
		for(CksDNode* p=&m_org; p!=NULL; p = p->GetNext()){
			if(p->GetNext() == n)

				return p;
		}
		return NULL;
	}
	CksDNode *FindNodePriority(int val){
		//�켱������ val�� ��������͸� ��ȯ���ݴϴ�.
		for(CksDNode* p = &m_org; p!=NULL; p = p->GetNext()){
			if(val==p->GetPriority()){
				return p;
			}
		}
		return NULL;

	}

	
	int GetLength(){ // ����Ʈ �׸� ���� ��ȯ
      int count = 0;
      for(CksDNode* p = GetHead(); p != NULL; p = p->GetNext()) //������ �����ͱ��� �ݺ�
         count++; //count������ ���������ش�.
      return count; //count������ ��ȯ���ش�.
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