#pragma once
#include "CksNode.h"
class CksLinkedStack
{
	CksNode m_org; // ��� ������
public:
	CksLinkedStack() { m_org = NULL; } // ������
	~CksLinkedStack() { while(!IsEmpty()) delete Pop();} // �Ҹ���

	CksNode* GetHead(){ return m_org.Next(); }
	//����� ������ ����Ű�� �Լ�
	bool IsEmpty( ) { return GetHead() == NULL; }
	//��尡 ������� ��尡 ����Ű�� ������ ������ ���ش�.
	void AddHead(CksNode *n){
		m_org.AddNext(n);
		//��带 �߰����ش�.
	}
	
	CksNode* RemoveHead(){//����� ��������͸� ����.
		return m_org.RemoveNext();
	}

	void clear(){
		//��尡 �� ���� ������
		//��� �����͸� �Ҹ��Ѵ�.
		while(!IsEmpty())
			delete RemoveHead();
	}

	void Push(char ch) {
		AddHead(new CksNode(ch));
		//ch��  ���� ��带 �����Ҵ��Ͽ� �߰����ش�.
	}
	void Reset(){ 
		clear();
		m_org.SetLink(NULL);
		//�ʱ�ȭ�� ����.
	}

	CksNode* Pop() {
		//������� ��� ����ó���� ���ش�.
		if(IsEmpty()){
			return 0;
		}
		return RemoveHead();
		//��������͸� �������ش�.
	}
	CksNode* Peek(){
		//������� ��� ����ó���� ���ش�.
		if(IsEmpty()){
			return 0;
		}
		return GetHead();
		//��尡 ����Ű�� ���� ��ȯ�Ѵ�.
	}

	int GetLength()
	{// �����Ͱ� ���� ��带 ����ų�� ���� ���ö����� count�� ���ش�.
		
		int count = 0;
		for(CksNode* p = GetHead(); p!=NULL; p=p->Next())
			count++;
		return count;
	}

	void Display()
	{	//���ڸ� ������ش�.
		//��� �����Ͱ� Null�϶����� ���ڸ� ��������ش�.
		printf("[%d����]", GetLength());
		for(CksNode* p = GetHead(); p != NULL; p = p->Next())
			p->Display();
		printf("\n");
	}
};