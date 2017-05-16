#include "CksArrayQueue.h"

void main(){

	CksQueue q;//객체선언.
	for(int i = 0; i<10; i++){
		q.EnQueue(i);//객체의 배열을 set하는 함수호출
	}
	q.Display();	//0 1 2 3 ..... 9 배열 정보를 출력.
	q.DeQueue();   //전단 원소를 제거. 0
	q.DeQueue();   //전단 원소를 제거. 1
	q.DeQueue();   //전단 원소를 제거. 2
	q.Display();	//3 4 5 .........9
	getchar();
	getchar();
}