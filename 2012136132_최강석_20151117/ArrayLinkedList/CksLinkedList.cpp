#include "CksArrayList.h"

void main(){
	printf("\n******************* [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 10 ] *******************\n\n");
	printf("                          1. Array List ���� ���α׷�   \n\n");

	CksArrayList list1;			// ����Ʈ ��ü List1 ����

	printf("Add() 3ȸ, AddHead() 1ȸ, AddTail() 1ȸ\n\n");
	list1.Add( 0, 10 );			// ����Ʈ 0 ��ġ�� 20 ����
	list1.Add( 0, 20 );			// ����Ʈ 0 ��ġ�� 10 ����
	list1.Add( 0, 30 );			// ����Ʈ 0 ��ġ�� 30 ����
	list1.AddHead( 40 );		// ����Ʈ �� �տ� 40 ����
	list1.AddTail( 50 );		// ����Ʈ �� �ڿ� 50 ����
	list1.Display( "list1 " );	// list1 ���

	printf("\nRemove( 2 ), RemoveHead() 1ȸ, RemoveTail() 1ȸ\n\n");
	list1.Remove( 2 );			// ����Ʈ 2��° ��ġ �׸� ����
	list1.RemoveHead();			// ����Ʈ �� ���� ��ġ �׸� ����
	list1.RemoveTail();			// ����Ʈ �� �� ��ġ �׸� ����
	list1.Display( "list1 " );	// list1 ���

	printf("\nReplace( 1, 90)\n\n");
	list1.Replace( 1, 90);		// 1�� ��ġ�� �׸� 90���� ����
	list1.Display( "list1 " );	// list1 ���
	
	printf("\nClear()\n\n");
	list1.Clear();				// ����Ʈ�� ��� �׸� ����
	list1.Display( "list1 " );	// list1 ���

	getchar();
	getchar();
}