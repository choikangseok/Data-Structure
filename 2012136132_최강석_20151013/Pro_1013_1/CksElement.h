#pragma once
#include <stdio.h>
class CksElement
{
	char m_ch;
	//�����ϳ��� �����Ƿ�
public:
	// ������
	CksElement(char ch=0)
	{
		m_ch = ch;
	}

	// �Ҹ���
	~CksElement(void){}

	char getch(){
		return m_ch;
		//�����Լ����� ������ ���ֱ����� �Լ�
	}
	void Display(){printf("%c ", m_ch);}
	//�������.

};