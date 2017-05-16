
#include "BSTree.h"

void main()
{
	printf("\n******************* [ 2015년도 2학기 자료구조 실습과제 12 ] *******************\n\n");
	printf("                1. 이진탐색트리로 구현한 Wish List 구현 프로그램   \n\n");

	BSTree t;

	t.Add( new TNode( 4, "정장", 80, "엄마카드로" ) );
	t.Add( new TNode( 5, "노트북", 950, "내년에" ) );
	t.Add( new TNode( 2, "안경", 15, "다음달에" ) );
	t.Add( new TNode( 1, "신발", 10 ) );
	t.Add( new TNode( 3, "외투", 10, "12월 전에" ) );
	t.Add( new TNode( 6, "운동복", 10, "내년여름 위해" ) );
	t.Add( new TNode( 7, "다이어리", 3, "새해맞이" ) );
	
	t.PrintPreOrder();
	t.PrintInOrder();
	t.PrintPostOrder();

	printf("-------------------         [ t.FindItem(''다이어리'') ]         -------------------\n\n");
	t.FindItem("다이어리");
	t.FindItem2("다이어리");
	printf("-------------------         [ t.FindItem(''또로리'') ]         -------------------\n\n");
	
	t.FindItem("또로리");
	t.FindItem2("또로리");
	
	printf("\n-------------------      [ t.SearchPriceRange(1, 30) ]      -------------------\n\n");
	t.SearchPriceRange(1, 30);

	printf("\n-------------------     [ t.GetHeight(), t.GetCount() ]     -------------------\n\n");
	printf("[BSTree의 객체 t의 높이     : %2d]\n", t.GetHeight());
	printf("[BSTree의 객체 t의 노드개수 : %2d]\n", t.GetCount());

	getchar();
}
