#pragma once
#include "CksDNode.h"

class CksDLList : public CksDNode{
	CksDNode *m_org; //��� ������
public:
	CksDLList(void){m_org=NULL;};
	~CksDLList(void){};

	CksDNode* GetHead()		{ return m_org;}
							//m_org��ü�� ����Ű�� ������(���������)�� ��ȯ���ش�.
	bool IsEmpty()			{ return m_org==NULL ;}
							//��������Ͱ� ����Ű�� ���� �� ������ �ƴ����� ��ȯ���ش�.
	

	CksDNode* GetTail(){//�������� ��ġ�ϴ� ��� �����͸� ��ȯ���ش�.
		CksDNode* tail = m_org;
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
		for(CksDNode *p = GetTail() ; p != NULL; p= p->GetPrev())
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
	void Remove(CksDNode* n){//n�� �Ű������� �޾Ƽ� n�� �յڿ��� ������
							//�����ְ�  �յڸ� ��������ش�.
		for(CksDNode * p = GetHead(); p!=NULL; p = p->GetNext() )
			if(n==GetHead()){
				if(n->m_next==NULL)//m_org�� �ϳ��� ������� ������ �ɾ��־� �����ش�.
					m_org=NULL;
				else{
					m_org = m_org->m_next; 
					m_org ->m_prev=NULL;
				}
			}
			else if(p->m_next == n){//�켱������ �ش�� �� ��尡 ���� ���
				p->m_next=n->m_next;//p�� m_next��ũ�� ����Ű�� ������ n ��尡 ������ ����� �����Ѵ�.
				if(n->m_next!=NULL)//���ǹ��� �ɾ� ���� n�� ���� ��尡 NULL�� �ƴ� ���   
					n->m_next->m_prev=p;//n�� ���� ����� m_prev��ũ�� p�� ����Ű�� �Ѵ�.
			}
		delete n;

      }
	void AddHead(CksDNode *n){
		//�Ǿ��ʿ� ��带 �߰����ش�.
 	  if(IsEmpty()){
		  //m_org�� �ƹ����� �������.
         m_org = n;
      }
      else{
		  //n�� ���ʿ� �־��ְ� ������ �ִ� ���� �����������ش�.
         n->SetNext(m_org); 
		 m_org->SetPrev(n);
		 m_org = n; 
      }
	}
	void AddTail(CksDNode *n){
		//�ǵ��ʿ� ��带 �߰����ش�.
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

	void RemoveHead(){//�Ǿ����� ��带 �����ش�.
		Remove(GetHead());
	}
	void RemoveTail(){   
		Remove(GetTail());
	}

	void Clear(){//������ ��尡 ���� ���ö����� �����ش�.
		while(!IsEmpty())
			RemoveHead();	
	}

	CksDNode *FindPrev(CksDNode *n){
		//�Ű������� ���� ����� �� ��带 ��ȯ���ݴϴ�.
		for(CksDNode* p=m_org; p!=NULL; p = p->GetNext()){
			if(p->GetNext() == n)
				return p;
		}
		return NULL;
	}
	CksDNode *FindNodePriority(int val){
		//�켱������ val�� ��������͸� ��ȯ���ݴϴ�.
		for(CksDNode* p = m_org; p!=NULL; p = p->GetNext()){
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