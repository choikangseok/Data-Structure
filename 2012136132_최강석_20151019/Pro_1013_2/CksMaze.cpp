
#include "CksMaze.h"
void main()
{
	CksMaze maze;
	maze.Load("maze1.txt");//�ε��Լ�����
	maze.Print("maze1.txt");//����Ʈ�Լ� ����.
	printf( " �Ա��� --> �ⱸ�� ���ã�� ���� [enter]\n");
	getchar();
	maze.searchExit();
	maze.Print("maze1.txt");
	maze.setOptimum();
	
	printf( "����ȭ��� Ž��[enter]\n");
	getchar();
	maze.Print("maze1.txt");
	getchar();
	getchar();
}