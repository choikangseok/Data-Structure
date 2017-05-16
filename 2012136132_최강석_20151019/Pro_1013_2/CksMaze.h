#pragma once
#include<stdio.h>
#include"CksStack.h"
#include <Windows.h>

#define WALL 0 
#define START 5
#define EXIT 9
#define EMPTY 1
#define DONE 2
#define OPTIMUM 3
class CksMaze
{
	int m_w; // 미로의 width
	int m_h; // 미로의 height
	int** m_maze; // 미로의 각 항목 값을 저장
	CksStack m_stack; // 미로 탐색을 위한 스택
	CElement m_start; // 미로의 입구
	CElement m_exit; // 미로의 출구
	CksStack m_OPstack;
public:
	CksMaze() { Init(0, 0);}
	~CksMaze(){ Reset(m_w, m_h); }
	void Init(int w, int h) {
		m_w=w;
		m_h=h;
		//배열에대한 동적 할당을 해준다 먼저 height부터 포인터를 할당하고나서
		//이후에  width에 대한 동적할당을 해준다.
		m_maze= new int * [m_h];
		for(int i =0; i<m_h; i++){
			m_maze[i]=new int[m_w];
		}
		
	} // 이차원 배열을 동적으로 할당

	void Reset(int w, int h) {
		//동적해제
		m_w=w;
		m_h=h;
		//동적해제 같은경우에는 마지막으로 동적 할당 된 값이
		//우선적으로 해제될 수 있게 해준다.
		for(int i =0; i<m_h; i++){
			delete[] m_maze[i];
		}
		delete []m_maze;
	} 


	void Load( char *fname){
		//미로파일을 읽어들이는 함수
		FILE *fp = stdin;
		if(fname !=NULL){
			fp = fopen (fname, "r");//r모드로 파일을 열어준다.
			if(fp == NULL){
				printf("Error 파일이 없습니다\n");
				return;
			}
		}
		int w, h;
		fscanf(fp, "%d %d", &w, &h );;
		Init( w, h );		// 메모리 할당
		for( int i=0 ; i<h ; i++ ) {
			for( int j=0 ; j<w; j++ ) {
				fscanf(fp, "%d", &(m_maze[i][j]) );
			}
		}
		if( fp != stdin ) fclose(fp);
	}
	void setOptimum(){
		CksPoint2D *pt;

		while( (pt = m_OPstack.pop()) != NULL ) { //pt에 m_optimal에서 pop하여 저장한다. !NULL이 나오기 전까지 반복 
			m_maze[pt->y][pt->x] = OPTIMUM; // 최적화 스택에 저장된 배열 값을 다른 모양(☆)이 나오도록 한다.
		}
	}
	void OptimalPath (CksPoint2D& pt) //최적화 경로 추가
	{
		while (m_OPstack.m_top != NULL) {
			if( !(m_OPstack.m_data[m_OPstack.m_top-1].isNeighbor(pt)) ){ //이전 스택과 비교하여 이웃이 아닐 경우 
				m_OPstack.pop(); //최적화스택에서 뺀다.
			}
			else
				break; 
		}
		m_OPstack.push(pt); //pt값을 저장한다.
	}

	void Print(char *fname){
		//현재 Maze를 화면에 출력
		FILE *fp = stdout;
		if( fname != NULL ) { 
			fp = fopen (fname, "r");//r모드로 파일을열어준다.
			if( fp == NULL ) { 
				printf( " Error: 파일을 만들 수 없습니다.\n");
				return;
			}
		}
		system("cls");

		printf( "=============================================\n");
		printf( "  전체 미로의 크기 = ");
		printf("%d x %d\n", m_w, m_h);
		// 가로와 세로를 출력해준다.
		printf( "=============================================\n");

		for( int i=0 ; i<m_h ; i++ ) {
			
			for( int j=0 ; j<m_w ; j++ ) {
				switch (m_maze[i][j]) {		
					//배열 성분에 따라 문자를 출력해준다.
				case WALL	: printf("■" ); break;
				case START	: printf("○" ); break;
				case EXIT	: printf("◎" ); break;
				case EMPTY	: printf("  " ); break;
				case DONE	: printf("□" ); break;
				case OPTIMUM : printf("☆"); break;

				}
			}
			printf("\n");
		}
		printf( "=============================================\n");
		if( fp != stdout ) fclose(fp);
		//파일을 닫아준다.
	}
	
	void setBeginEnd(){
		for( int i=0 ; i<m_h ; i++ )
			for( int j=0 ; j<m_w ; j++ ) {
				if( m_maze[i][j] == START )
					m_start = CksPoint2D( j, i );
				else if ( m_maze[i][j] == EXIT )
					m_exit = CksPoint2D( j, i );
			}
			m_stack.push( m_start );
	}

	void searchExit(){
		setBeginEnd(); //시작과 끝 위치를 찾아 저장하는 함수
		CksPoint2D *pt;

		while ( (pt=m_stack.pop())!=NULL ){//pt가 NULL이 아닐때 까지 pop
			int x = pt->x; // 스타트 x 좌표 의미
			int y = pt->y; // 스타트y좌표 의미

			if( isExitPos(x,y) ){ //미로의 끝을 찾아낸다.
				OptimalPath(*pt);
				
				return;
			}
			else {
				m_maze[y][x] = DONE; //지나간 길을 표시함
				OptimalPath(*pt);

				if (isValidPos(x+1, y) && isPossiblePos(x+1, y) || isExitPos(x+1, y)){
					m_stack.push(x+1, y); // 스택에 push
				}// 오른쪽 => 미로 내에 위치하는지 확인 && 갈수있는 길 인지 확인 || 출구인지 확인 
				if (isValidPos(x-1, y) && isPossiblePos(x - 1, y) || isExitPos(x - 1, y)){
					m_stack.push(x-1, y); // 스택에 push
				}// 왼쪽 => 미로 내에 위치하는지 확인 && 갈수있는 길 인지 확인 || 출구인지 확인
				if (isValidPos(x, y+1) && isPossiblePos(x, y+1) || isExitPos(x , y+1)){
					m_stack.push(x, y+1); // 스택에 push
				}// 위쪽 => 미로 내에 위치하는지 확인 && 갈수있는 길 인지 확인 || 출구인지 확인
				if (isValidPos(x, y-1) && isPossiblePos(x, y-1) || isExitPos(x , y-1)){
					m_stack.push(x, y-1); // 스택에 push
				}// 아래쪽 => 미로 내에 위치하는지 확인 && 갈수있는 길 인지 확인 || 출구인지 확인
			}
			
			Print("maze1.txt");
			printf("[%d][%d]=====>[%d][%d]", x,y, m_exit.x, m_exit.y);
			Sleep(100);
		}
		
	}
	
	bool isValidPos(int x, int y){
		//미로크기 밖인지 아닌지를 검사
		return (x>=0 && x<m_w && y>=0 && y<m_h);
	}
	bool isExitPos(int x, int y){
		//미로의 출구인지를 검사
		return (x==m_exit.x && y==m_exit.y);
	}
	bool isPossiblePos(int x, int y){
		return (m_maze[y][x] == EMPTY);
		//미로 (EMPTY)비었는지를 검사.
	}

};