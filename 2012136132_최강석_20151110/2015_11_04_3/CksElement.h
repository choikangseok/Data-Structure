#pragma once
#include <stdio.h>
class CksElement
{
	int num;
	//�����ϳ��� �����Ƿ�
public:
	// ������
	CksElement(int n=0)
	{
		num=n;
	}

	// �Ҹ���
	~CksElement(void){}
	int GetInt(){
		return num;	
	}
	void Display(){printf("%d ", num);}
	//�������

};