
#include "CksMaze.h"
void main()
{
	CksMaze maze;
	maze.Load("maze1.txt");//로드함수실행
	maze.Print("maze1.txt");//프린트함수 실행.
	printf( " 입구○ --> 출구◎ 경로찾기 시작 [enter]\n");
	getchar();
	maze.searchExit();
	maze.Print("maze1.txt");
	maze.setOptimum();
	
	printf( "최적화경로 탐색[enter]\n");
	getchar();
	maze.Print("maze1.txt");
	getchar();
	getchar();
}