
#include "CksMaze.h"
void main()
{
	CksMaze maze;
	maze.Load("maze1.txt");//로드함수실행
	maze.Print("maze1.txt");//프린트함수 실행.
	getchar();
	getchar();
}