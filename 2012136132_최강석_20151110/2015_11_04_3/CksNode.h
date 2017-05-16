#pragma once
#include "CksElement.h"

class CksNode : public CksElement // ����� ������ ���� ��� Ŭ����
{
public:
	CksNode* m_link; // ���� ��带 ����Ű�� ������ ����
	CksNode* f_link; // �� ��带 ����Ű�� ������ ����.
	CksNode(int num = 0) : CksElement(num) { 
		//������
		m_link = NULL; 
		f_link = NULL;
	}
	~CksNode(void) { }
	//�Ҹ���
	CksNode* Next(){return m_link;}///���� ����Ű�� ��� ��ȯ.
	CksNode* Prev(){return f_link;}//������ ����Ű�� ��� ��ȯ.
	void AddNext(CksNode *p){//�Ĵܿ� ��带 ������
		m_link = p;
		p->f_link = this;
		p->m_link = NULL;
	}
	void AddPrev(CksNode *p){//���ܿ� ��带 ������
		f_link = p;
		p->m_link = this;
		p->f_link = NULL;
	}
	
};