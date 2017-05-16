#pragma once
#include "CksItemNodeP.h"
class CksLinkedList
{
   CksItemNode *m_org;
   int m_nNodes;
public:
   CksLinkedList(void) : m_nNodes(0){ m_org = NULL; }
   ~CksLinkedList(void){ Clear(); }
   
   CksItemNode* GetHead(){
      return m_org;
   }
   bool IsEmpty(){
      return m_org == NULL;
   }
   CksItemNode* GetTail(){
      CksItemNode* tail = m_org;
      for (; tail->Next() != NULL; tail = tail->Next());
      return tail;
   }
   void Display(char* str){
      printf("[%s ��ü �׸� �� = %2d] : \n", str, m_nNodes);
      for (CksItemNode* p = GetHead(); p != NULL; p = p->Next())
         p->Print();
      printf("\n");
   }
   void AddHead(CksItemNode* n){
      if (IsEmpty()){
         n->m_next = NULL;
         m_org = n;
      }
      else{
         n->m_next = m_org; //m_rear�� ����Ű���� ��带 �߰��� �� ����Ű�� �ϰ�
         m_org = n; //m_rear�� e�� �ִ´�.
      }
      m_nNodes++; //����� ���� ����
   }
   void AddTail(CksItemNode* n){
      if (IsEmpty()){
         n->m_next = NULL;
         m_org = n;
      }
      else
         GetTail()->m_next = n;
      m_nNodes++;
   }
   void AddNext(CksItemNode* p, CksItemNode* n){
      n->m_next = p->Next();
      p->m_next = n;
      m_nNodes++;
   }
   void RemoveHead(){
      m_org = m_org->Next();
      m_nNodes--;
   }
   void Remove(CksItemNode* n){
      for(CksItemNode* p = GetHead(); p != NULL; p = p->m_next){
         if (p == n)
            m_org = m_org->Next();
         else if(p->m_next == n)
            p->m_next = n->m_next;
      }
      m_nNodes--;
   }
   void Clear(){
      while(!IsEmpty())//NULL�� ���ö� ���� �ݺ�
         RemoveHead();//����Ʈ�� ��带 �ݺ������� ����
   }
   CksItemNode* FindNodePriority(int n){
      CksItemNode* p = NULL; //��尪�� NULL�� �д�.
      for(p = GetHead(); p != NULL; p = p->Next())
         if(p->GetPriority() == n)
            break;
      return p;
   }
   void Merge(CksLinkedList &list2){
      CksItemNode* p;   
      p = GetHead();
	  m_nNodes+=list2.m_nNodes;
      while( p->m_next != NULL )
         p = p->m_next;
      p->m_next = list2.GetHead();
      list2.Clear();
   }
 
   
   void Reverse(){//������ �Լ�
		CksItemNode *p, *q, *r;
		p = GetHead();
		q = NULL; // q�� �������� ���� ���
      while(p != NULL){
         r = q;
         q = p;
         p = p->Next();
         q->m_next = r;
      }
	  m_org=q;
   }

};