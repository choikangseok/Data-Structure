#include "CksLinkedListP.h"


void main() {

	printf("\n******************* [ 2015년도 2학기 자료구조 실습과제 10 ] *******************\n\n");
	printf("                          2. Wish List 구현 프로그램   \n\n");

	printf("-------------------         Addtail 2회, AddHead 2회        -------------------\n\n");
	CksLinkedList list1;			// CLinkedList 클래스의 list 객체 생성
	list1.AddTail(new CksItemNode("정장", 8000000, 4, "엄마카드로"));		// 마지막 위치에 리스트 추가
	list1.AddTail(new CksItemNode("노트북", 9500000, 5, "내년에"));		// 마지막 위치에 리스트 추가
	list1.AddHead(new CksItemNode("안경", 150000, 2, "다음달에"));			// 맨 처음 위치에 리스트 추가
	list1.AddHead(new CksItemNode("신발", 100000, 1));						// 맨 처음 위치에 리스트 추가
	list1.Display( "list1 " );													// 리스트 전체 출력

	printf("-------------------   우선순위값이 2인 노드 탐색 & AddNext  -------------------\n\n");
	CksItemNode *n = list1.FindNodePriority( 2 );							// 우선순위값이 2인 노드 탐색
	list1.AddNext(n, new CksItemNode("외투", 100000, 3, "12월 전에"));		// 우선순위값이 2인 노드 뒤에 새로운 노드 삽입
	list1.Display( "list1 " );		

	printf("-------------- RemoveHead() , 우선순위값이 2인 노드 탐색 & 삭제 ---------------\n\n");
	list1.RemoveHead();												// 리스트 맨 앞 노드 삭
	n = list1.FindNodePriority( 2 );									// 우선순위값이 2인 노드 탐색
	list1.Remove( n );												// 그 노드 삭제
	list1.Display( "list1 " );													// 리스트내용 화면출력
	printf("--------------  Reverse() : 리스트 역순 출력    ---------------\n\n");
	list1.Reverse();
	list1.Display("list1" );
	printf("--------------  새로운 리스트 만듦 : AddHead 3회  ---------------\n\n");

	CksLinkedList list2;			// CLinkedList 클래스의 list 객체 생성
	list2.AddHead(new CksItemNode("L2정장", 8000000, 8, "엄마카드로"));		// 마지막 위치에 리스트 추가
	list2.AddHead(new CksItemNode("L2노트북", 9500000, 7, "내년에"));		// 마지막 위치에 리스트 추가
	list2.AddHead(new CksItemNode("L2안경", 150000, 6, "다음달에"));			// 맨 처음 위치에 리스트 추가
	
	list1.Merge(list2);
	list1.Display("Merge(list2)");
	list2.Display("list2");


	
	
	getchar();
	getchar();


}
