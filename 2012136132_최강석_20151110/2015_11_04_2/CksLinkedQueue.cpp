#include "CksLinkedQueue.h"

void main(){

	printf("\n***************** [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 9 ] *****************\n\n");
	printf("                       2. ���� ť �׽�Ʈ ���α׷�   \n\n");

	CksLinkedQueue que;

	printf(" CLinkedQueue ���� 8�� ���� => ");
	for( int i=1 ; i<9 ; i++){
		que.EnQueue(new CksNode(i));
	}
	que.Display();
	
	printf(" CLinkedQueue ���� 3�� ���� => ");
	CksNode* n;
	n = que.DeQueue(); delete n;
	n = que.DeQueue(); delete n;
	n = que.DeQueue(); delete n;

	que.Display();

	printf(" CLinkedQueue ��ȯ Peek() ���� => %2d", que.Peek()->GetInt() );

	getchar();
	getchar();
}
