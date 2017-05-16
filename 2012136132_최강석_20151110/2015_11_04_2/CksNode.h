#pragma once
#include "CksElement.h"

class CksNode : public CksElement // ����� ������ ���� ��� Ŭ����
{
	CksNode* m_link; // ���� ��带 ����Ű�� ������ ����
public:
	CksNode(int num = 0) : CksElement(num) { 
		//������
		m_link = NULL; 
	}
	~CksNode(void) { }
	//�Ҹ���
	CksNode* GetLink(){
		return m_link;	
	}
	CksNode* Next() {
		//���� ��带 ����Ű�� ��� �����͸� ��ȯ���ش�.
		return m_link;
	}

	void SetLink(CksNode *p) {
		m_link = p; 
		//���� ��带 ����Ű�� ��� �����͸� �������ش�.
	}
	void AddNext(CksNode *p) {
		// ���ο� ��带 ����Ű�� ��� �����͸� �߰����ش�.
		if( p != NULL ) {
			p->m_link = m_link;
			m_link = p;
		}
	}
	
	CksNode* RemoveNext( ) {
		CksNode* p = m_link;
		//��带 ���Ÿ����ش�.
		if( p != NULL ) 
			m_link = p->m_link;
		return p;
	}

};