#pragma once
#include "CksPoint2D.h"
#define MAX_STACK_SIZE 1000

typedef CksPoint2D CElement;
class CksStack
{
public:
	CElement m_data[MAX_STACK_SIZE]; // 요소의 배열(구조체 1000개 선언)
	int m_top; // 요소의 개수 /
	CksStack() { m_top = 0; } // 스택 생성자 
	~CksStack(){} // 스택 소멸자

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