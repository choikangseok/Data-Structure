//#include "CksDeque.h"
#include "CksDeQueue.h"
#include "CksDeque.h"

void main(){

	printf("\n************* [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 9 ] *************\n\n");
	printf("                       1. ť �׽�Ʈ ���α׷�\n\n");

	printf("------------ [ ����� �̿����� ���� �� CDeque Ŭ���� ] -----------\n\n");
	CksDeque q;

	printf(" CDeque ���ܻ��� 8�� ���� => ");
	for( int i=1 ; i<9 ; i++){
		q.AddFront(i);
	}
	q.Display();
	
	printf(" CDeque ���ܻ��� 3�� ���� => ");
	q.DelFront();
	q.DelFront();
	q.DelFront();
	
	q.Display();

	printf(" CDeque �Ĵܻ��� 3�� ���� => ");
	q.AddRear(9);
	q.AddRear(10);
	q.AddRear(11);
	
	q.Display();

	printf(" CDeque �Ĵܻ��� 2�� ���� => ");
	q.DelRear();
	q.DelRear();

	q.Display();

	printf("\n\n---------------- [ ����� �̿��� CDeQueue Ŭ���� ] ---------------\n\n");
	CksDeQueue q2;

	printf(" CDeQueue ���ܻ��� 8�� ���� => ");
	for( int i=21 ; i<29 ; i++){
		q2.AddFront(i);
	}
	q2.Display();
	
	printf(" CDeQueue ���ܻ��� 3�� ���� => ");
	q2.DelFront();
	q2.DelFront();
	q2.DelFront();
	
	q2.Display();

	printf(" CDeQueue �Ĵܻ��� 3�� ���� => ");
	q2.AddRear(29);
	q2.AddRear(30);
	q2.AddRear(31);
	
	q2.Display();

	printf(" CDeQueue �Ĵܻ��� 2�� ���� => ");
	q2.DelRear();
	q2.DelRear();

	q2.Display();

	getchar();
	getchar();
}