#pragma once
#include <stdio.h>
class CksElement
{
	int num;
	//문자하나만 받으므로
public:
	// 생성자
	CksElement(int n=0)
	{
		num=n;
	}

	// 소멸자
	~CksElement(void){}
	int GetInt(){
		return num;	
	}
	void Display(){printf("%d ", num);}
	//숫자출력

};