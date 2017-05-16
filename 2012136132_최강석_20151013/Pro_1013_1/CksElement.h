#pragma once
#include <stdio.h>
class CksElement
{
	char m_ch;
	//문자하나만 받으므로
public:
	// 생성자
	CksElement(char ch=0)
	{
		m_ch = ch;
	}

	// 소멸자
	~CksElement(void){}

	char getch(){
		return m_ch;
		//메인함수에서 접근을 해주기위한 함수
	}
	void Display(){printf("%c ", m_ch);}
	//문자출력.

};