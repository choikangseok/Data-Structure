#pragma once
#include "CksItemNode.h"

class CksLinkedList : public  CksItemNode{
protected:
	CksItemNode m_org;//��� ��ü.
public:
	CksLinkedList(): m_org(""){ //������.
	}
	~CksLinkedList(void) { Clear();}//�Ҹ��� �����Ҵ�� ������ ������.


	CksItemNode* GetHead()		{ return m_org.Next();}
							//m_org��ü�� ����Ű�� ������(���������)�� ��ȯ���ش�.
	bool IsEmpty()			{ return GetHead()==NULL ;}
							//��������Ͱ� ����Ű�� ���� �� ������ �ƴ����� ��ȯ���ش�.
	

	CksItemNode* GetTail(){//�������� ��ġ�ϴ� ��� �����͸� ��ȯ���ش�.
		CksItemNode* tail = &m_org;
		for(; tail->Next() !=NULL ; tail = tail->Next());
		return tail;
	}
	void Display(char* list){//��ü�׸���� ����Ѵ�
		printf("[%s ��ü �׸� �� = %2d]\n", list, GetLength());
		for(CksItemNode *p = GetHead() ; p != NULL; p= p->Next())
			//��������ͺ��� �����ؼ� NULL���� ���ö����� ���.
			p->Print();
		printf("\n");
	}
	
	
	void AddHead(CksItemNode *n){
		//�Ǿ��ʿ� ��带 �߰����ش�.
		n->SetNext(GetHead());
		m_org.SetNext(n);
	}
	void AddTail(CksItemNode *n){
		//�ǵ��ʿ� ��带 �߰����ش�.
		n->SetNext(NULL);
		AddNext(GetTail(), n);
	}

	void RemoveHead(){//�Ǿ����� ��带 �����ش�.
		Remove(GetHead());
	}
	void Remove(CksItemNode *n){// ��� n�� �����ش�.
		if(n==NULL)
			return;
		CksItemNode* prev = FindPrev(n);
		if(prev!=NULL)
		{		
			prev->RemoveNext();
			delete n;
		}
	}
	void Clear(){//������ ��尡 ���� ���ö����� �����ش�.
		while(!IsEmpty())
			Remove(GetTail());
	}

	CksItemNode *FindPrev(CksItemNode *n){
		//�Ű������� ���� ����� �� ��带 ��ȯ���ݴϴ�.
		for(CksItemNode* p=&m_org; p!=NULL; p = p->Next()){
			if(p->Next() == n)

				return p;
		}
		return NULL;
	}
	CksItemNode *FindNodePriority(int val){
		//�켱������ val�� ��������͸� ��ȯ���ݴϴ�.
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
	int GetLength(){ // ����Ʈ �׸� ���� ��ȯ
      int count = 0;
      for(CksItemNode* p = GetHead(); p != NULL; p = p->Next()) //������ �����ͱ��� �ݺ�
         count++; //count������ ���������ش�.
      return count; //count������ ��ȯ���ش�.
   }
};