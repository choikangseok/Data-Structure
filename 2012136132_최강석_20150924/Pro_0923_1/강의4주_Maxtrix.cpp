#include "CksMatrix.h"

void main(){
	
	CksMatrix a, b, c;
	//��� Ŭ���� a,b,c ����
	a.Read();
	b.Read();
	//a.b���Է¹���
	c.Add(a, b);
	//c�� a,b�� ���������� �־���.
	a.print("A  ");
	b.print("B  ");
	c.print("A+B  ");
	//�� ����� ���,
	getchar();
	getchar();
}