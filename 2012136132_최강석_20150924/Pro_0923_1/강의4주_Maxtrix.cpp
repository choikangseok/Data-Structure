#include "CksMatrix.h"

void main(){
	
	CksMatrix a, b, c;
	//행렬 클래스 a,b,c 선언
	a.Read();
	b.Read();
	//a.b를입력받음
	c.Add(a, b);
	//c에 a,b를 더한정보를 넣어줌.
	a.print("A  ");
	b.print("B  ");
	c.print("A+B  ");
	//각 행렬을 출력,
	getchar();
	getchar();
}