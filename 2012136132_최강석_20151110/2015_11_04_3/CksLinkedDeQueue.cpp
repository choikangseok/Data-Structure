#include "CksLinkedDeQueue.h"

void main(){

	printf("\n***************** [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 9 ] *****************\n\n");
	printf("                       3. ���� �� �׽�Ʈ ���α׷�   \n\n");

	CksLinkedDeQueue que;

	printf(" CLinkedDeQueue �Ĵ� ���� (1-9)  => ");
	for( int i=1 ; i<9 ; i++){
	que.AddRear(new CksNode(i));
	}
	//AddRear�� �Ĵܻ����� �մϴ�.
	que.Display();
	printf(" CLinkedDeQueue ���� ���� 2��  => ");
	que.DeleteFront();//���ܻ����� �մϴ�.
	que.DeleteFront();//���ܻ����� �մϴ�.
	que.Display();
	printf(" CLinkedDeQueue ���� ����  10, 11 �߰� => ");
	que.AddFront(new CksNode(10));//���ܿ� 10�� �߰�
	que.AddFront(new CksNode(11));//���ܿ� 11�� �߰�
	que.Display();
	printf(" CLinkedDeQueue �Ĵ� ���� 2��  => ");
	que.DeleteRear();//�Ĵܻ����� �մϴ�.
	que.DeleteRear();//�Ĵܻ����� �մϴ�.
	que.Display();


	getchar();
	getchar();
}