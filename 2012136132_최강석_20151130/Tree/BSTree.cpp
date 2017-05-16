
#include "BSTree.h"

void main()
{
	printf("\n******************* [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 12 ] *******************\n\n");
	printf("                1. ����Ž��Ʈ���� ������ Wish List ���� ���α׷�   \n\n");

	BSTree t;

	t.Add( new TNode( 4, "����", 80, "����ī���" ) );
	t.Add( new TNode( 5, "��Ʈ��", 950, "���⿡" ) );
	t.Add( new TNode( 2, "�Ȱ�", 15, "�����޿�" ) );
	t.Add( new TNode( 1, "�Ź�", 10 ) );
	t.Add( new TNode( 3, "����", 10, "12�� ����" ) );
	t.Add( new TNode( 6, "���", 10, "���⿩�� ����" ) );
	t.Add( new TNode( 7, "���̾", 3, "���ظ���" ) );
	
	t.PrintPreOrder();
	t.PrintInOrder();
	t.PrintPostOrder();

	printf("-------------------         [ t.FindItem(''���̾'') ]         -------------------\n\n");
	t.FindItem("���̾");
	t.FindItem2("���̾");
	printf("-------------------         [ t.FindItem(''�Ƿθ�'') ]         -------------------\n\n");
	
	t.FindItem("�Ƿθ�");
	t.FindItem2("�Ƿθ�");
	
	printf("\n-------------------      [ t.SearchPriceRange(1, 30) ]      -------------------\n\n");
	t.SearchPriceRange(1, 30);

	printf("\n-------------------     [ t.GetHeight(), t.GetCount() ]     -------------------\n\n");
	printf("[BSTree�� ��ü t�� ����     : %2d]\n", t.GetHeight());
	printf("[BSTree�� ��ü t�� ��尳�� : %2d]\n", t.GetCount());

	getchar();
}
