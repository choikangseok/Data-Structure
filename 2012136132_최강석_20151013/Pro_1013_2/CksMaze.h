#pragma once
#include<stdio.h>

#define WALL 0 
#define START 5
#define EXIT 9
#define EMPTY 1
class CksMaze
{
	int m_w; // 미로의 width
	int m_h; // 미로의 height
	int** m_maze; // 미로의 각 항목 값을 저장
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

				}
			}
			printf("\n");
		}
		printf( "=============================================\n");
		if( fp != stdout ) fclose(fp);
		//파일을 닫아준다.
	} 
};