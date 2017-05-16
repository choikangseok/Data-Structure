#include "CksLinkedDeQueue.h"

void main(){

	printf("\n***************** [ 2015년도 2학기 자료구조 실습과제 9 ] *****************\n\n");
	printf("                       3. 연결 덱 테스트 프로그램   \n\n");

	CksLinkedDeQueue que;

	printf(" CLinkedDeQueue 후단 삽입 (1-9)  => ");
	for( int i=1 ; i<9 ; i++){
	que.AddRear(new CksNode(i));
	}
	//AddRear로 후단삽입을 합니다.
	que.Display();
	printf(" CLinkedDeQueue 전단 삭제 2번  => ");
	que.DeleteFront();//전단삭제를 합니다.
	que.DeleteFront();//전단삭제를 합니다.
	que.Display();
	printf(" CLinkedDeQueue 전단 삽입  10, 11 추가 => ");
	que.AddFront(new CksNode(10));//전단에 10을 추가
	que.AddFront(new CksNode(11));//전단에 11을 추가
	que.Display();
	printf(" CLinkedDeQueue 후단 삭제 2번  => ");
	que.DeleteRear();//후단삭제를 합니다.
	que.DeleteRear();//후단삭제를 합니다.
	que.Display();


	getchar();
	getchar();
}