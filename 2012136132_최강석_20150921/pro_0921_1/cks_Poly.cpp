#include "Poly.h"

void main()
{
	printf("\n************* [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 3 ] *************\n\n");
	printf("                         1. ���׽� ���\n\n");

	CksPoly a, b, c, d;
	a.Read(); // ù ��° ���׽��� �Է� ����
	b.Read(); // �� ��° ���׽��� �Է� ����

	printf("\n******************************************************************\n\n");

	a.Print("    Print(A) = ");
	b.Print("    Print(B) = ");

	a.Print2("   Print2(A) = ");
	b.Print2("   Print2(B) = ");
	
	c.Add (a, b); // �� ���׽��� ���� ���

	c.Print2("      A + B  = ");
	c.Trim();
	c.Print2(" Trim(A + B) = ");

	d.Mult (a, b); // �� ���׽��� ���� ���
	d.Print2("      A * B  = ");
	d.Trim();
	d.Print2(" Trim(A * B) = ");
	 
	getchar();
	getchar();
}