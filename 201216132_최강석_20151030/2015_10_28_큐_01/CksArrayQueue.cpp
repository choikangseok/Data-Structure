#include "CksArrayQueue.h"

void main(){

	CksQueue q;//��ü����.
	for(int i = 0; i<10; i++){
		q.EnQueue(i);//��ü�� �迭�� set�ϴ� �Լ�ȣ��
	}
	q.Display();	//0 1 2 3 ..... 9 �迭 ������ ���.
	q.DeQueue();   //���� ���Ҹ� ����. 0
	q.DeQueue();   //���� ���Ҹ� ����. 1
	q.DeQueue();   //���� ���Ҹ� ����. 2
	q.Display();	//3 4 5 .........9
	getchar();
	getchar();
}