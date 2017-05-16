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
      printf("[%s 전체 항목 수 = %2d] : \n", str, m_nNodes);
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
         n->m_next = m_org; //m_rear가 가리키던걸 노드를 추가한 뒤 가리키게 하고
         m_org = n; //m_rear에 e를 넣는다.
      }
      m_nNodes++; //노드의 개수 증가
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
      while(!IsEmpty())//NULL이 나올때 까지 반복
         RemoveHead();//리스트의 노드를 반복적으로 삭제
   }
   CksItemNode* FindNodePriority(int n){
      CksItemNode* p = NULL; //노드값을 NULL로 둔다.
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
 
   
   void Reverse(){//리버스 함수
		CksItemNode *p, *q, *r;
		p = GetHead();
		q = NULL; // q는 역순으로 만들 노드
      while(p != NULL){
         r = q;
         q = p;
         p = p->Next();
         q->m_next = r;
      }
	  m_org=q;
   }

};