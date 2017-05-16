#pragma once
#include "CksPoint2D.h"
#define MAX_STACK_SIZE 1000

typedef CksPoint2D CElement;
class CksStack
{
public:
	CElement m_data[MAX_STACK_SIZE]; // ����� �迭(����ü 1000�� ����)
	int m_top; // ����� ���� /
	CksStack() { m_top = 0; } // ���� ������ 
	~CksStack(){} // ���� �Ҹ���

	void push( int x, int y ) {

		push( CksPoint2D( x, y ) );
	}
	void push( CksPoint2D &pt ) {
		m_data[m_top++] = pt;
	}
	CksPoint2D* pop () { //pop
		if( m_top==0 ) return NULL;
		else  return &m_data[--m_top];
	}
	CksPoint2D* peek () { //peek
		if( m_top==0 ) return NULL;
		else  return &m_data[m_top-1];
	}
};