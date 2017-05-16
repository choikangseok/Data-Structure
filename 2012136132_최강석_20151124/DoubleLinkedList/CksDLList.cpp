#include "cksDLList.h"

void main() {

	printf("\n******************* [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 11 ] *******************\n\n");
	printf("                1. ���߸���Ʈ�� ������ Wish List ���� ���α׷�   \n\n");

	printf("-------------------         Addtail 2ȸ, AddHead 2ȸ        -------------------\n\n");
	CksDLList list1;													// CLinkedList Ŭ������ list ��ü ����
	list1.AddTail(new CksDNode("����", 8000000, 4, "����ī���"));		// ������ ��ġ�� ����Ʈ �߰�
	list1.AddTail(new CksDNode("��Ʈ��", 9500000, 5, "���⿡"));		// ������ ��ġ�� ����Ʈ �߰�
	list1.AddHead(new CksDNode("�Ȱ�", 150000, 2, "�����޿�"));		// �� ó�� ��ġ�� ����Ʈ �߰�
	list1.AddHead(new CksDNode("�Ź�", 100000, 1));					// �� ó�� ��ġ�� ����Ʈ �߰�
	list1.Display( "list1 " );											// ����Ʈ ��ü ���
	

	printf("-------------------   �켱�������� 2�� ��� Ž�� & AddNext  -------------------\n\n");
	CksDNode *n = list1.FindNodePriority( 2 );							// �켱�������� 2�� ��� Ž��
	list1.AddNext(n, new CksDNode("����", 100000, 3, "12�� ����"));	// �켱�������� 2�� ��� �ڿ� ���ο� ��� ����
	list1.Display( "list1 " );			
	
	printf("------------------- Reverse()ȣ�� list1 ���  -------------------\n\n");
	list1.Reverse();
	list1.Display("list1");

	printf("--------------  list2�� ���ο� ����Ʈ ���� : list2.AddHead 3ȸ & list1.Merge(list2) ---------------\n\n");

	CksDLList list2;			// CLinkedList Ŭ������ list ��ü ����
	list2.AddHead(new CksDNode("L2����", 8000000, 8, "����ī���"));		// ������ ��ġ�� ����Ʈ �߰�
	list2.AddHead(new CksDNode("L2��Ʈ��", 9500000, 7, "���⿡"));		// ������ ��ġ�� ����Ʈ �߰�
	list2.AddHead(new CksDNode("L2�Ȱ�", 150000, 6, "�����޿�"));			// �� ó�� ��ġ�� ����Ʈ �߰�
	list1.Merge(list2);
	list1.Display("list1");
	list2.Display("list2");
	
	printf("------- RemoveHead() , �켱�������� 2�� ��� Ž�� & ����, RemoveTail() --------\n\n");
	list1.RemoveHead();													// ����Ʈ �� �� ��� ����
	n = list1.FindNodePriority( 2 );									// �켱�������� 2�� ��� Ž��
	list1.Remove(n);													// �� ��� ����
	list1.RemoveTail();													// ����Ʈ �� �� ��� ����
	list1.Display( "list1 " );											// ����Ʈ���� ȭ�����													

	printf("------------- List1 DisplayRev() : �Ųٷ� ���(������������x) �ݺ� ------------\n\n");
	list1.DisplayRev( "list1 " );										// ����Ʈ���� ���� ȭ�����

	printf("------------- List1 DisplayRev() : �Ųٷ� ���(������������x) ��� ------------\n\n");
	list1.DisplayRevRecur( "list1 " );										// ����Ʈ���� ���� ȭ�����

	printf("-------------------   list1�� ��� �׸� ���� & list1 ���  -------------------\n\n");
	list1.Clear();													// ����Ʈ�� ��� �׸� ����
	list1.Display( "list1 " );				// ����Ʈ���� ȭ�����
	
	
	getchar();
	getchar();


}
