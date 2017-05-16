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
	int m_w; // �̷��� width
	int m_h; // �̷��� height
	int** m_maze; // �̷��� �� �׸� ���� ����
	CksStack m_stack; // �̷� Ž���� ���� ����
	CElement m_start; // �̷��� �Ա�
	CElement m_exit; // �̷��� �ⱸ
	CksStack m_OPstack;
public:
	CksMaze() { Init(0, 0);}
	~CksMaze(){ Reset(m_w, m_h); }
	void Init(int w, int h) {
		m_w=w;
		m_h=h;
		//�迭������ ���� �Ҵ��� ���ش� ���� height���� �����͸� �Ҵ��ϰ���
		//���Ŀ�  width�� ���� �����Ҵ��� ���ش�.
		m_maze= new int * [m_h];
		for(int i =0; i<m_h; i++){
			m_maze[i]=new int[m_w];
		}
		
	} // ������ �迭�� �������� �Ҵ�

	void Reset(int w, int h) {
		//��������
		m_w=w;
		m_h=h;
		//�������� ������쿡�� ���������� ���� �Ҵ� �� ����
		//�켱������ ������ �� �ְ� ���ش�.
		for(int i =0; i<m_h; i++){
			delete[] m_maze[i];
		}
		delete []m_maze;
	} 


	void Load( char *fname){
		//�̷������� �о���̴� �Լ�
		FILE *fp = stdin;
		if(fname !=NULL){
			fp = fopen (fname, "r");//r���� ������ �����ش�.
			if(fp == NULL){
				printf("Error ������ �����ϴ�\n");
				return;
			}
		}
		int w, h;
		fscanf(fp, "%d %d", &w, &h );;
		Init( w, h );		// �޸� �Ҵ�
		for( int i=0 ; i<h ; i++ ) {
			for( int j=0 ; j<w; j++ ) {
				fscanf(fp, "%d", &(m_maze[i][j]) );
			}
		}
		if( fp != stdin ) fclose(fp);
	}
	void setOptimum(){
		CksPoint2D *pt;

		while( (pt = m_OPstack.pop()) != NULL ) { //pt�� m_optimal���� pop�Ͽ� �����Ѵ�. !NULL�� ������ ������ �ݺ� 
			m_maze[pt->y][pt->x] = OPTIMUM; // ����ȭ ���ÿ� ����� �迭 ���� �ٸ� ���(��)�� �������� �Ѵ�.
		}
	}
	void OptimalPath (CksPoint2D& pt) //����ȭ ��� �߰�
	{
		while (m_OPstack.m_top != NULL) {
			if( !(m_OPstack.m_data[m_OPstack.m_top-1].isNeighbor(pt)) ){ //���� ���ð� ���Ͽ� �̿��� �ƴ� ��� 
				m_OPstack.pop(); //����ȭ���ÿ��� ����.
			}
			else
				break; 
		}
		m_OPstack.push(pt); //pt���� �����Ѵ�.
	}

	void Print(char *fname){
		//���� Maze�� ȭ�鿡 ���
		FILE *fp = stdout;
		if( fname != NULL ) { 
			fp = fopen (fname, "r");//r���� �����������ش�.
			if( fp == NULL ) { 
				printf( " Error: ������ ���� �� �����ϴ�.\n");
				return;
			}
		}
		system("cls");

		printf( "=============================================\n");
		printf( "  ��ü �̷��� ũ�� = ");
		printf("%d x %d\n", m_w, m_h);
		// ���ο� ���θ� ������ش�.
		printf( "=============================================\n");

		for( int i=0 ; i<m_h ; i++ ) {
			
			for( int j=0 ; j<m_w ; j++ ) {
				switch (m_maze[i][j]) {		
					//�迭 ���п� ���� ���ڸ� ������ش�.
				case WALL	: printf("��" ); break;
				case START	: printf("��" ); break;
				case EXIT	: printf("��" ); break;
				case EMPTY	: printf("  " ); break;
				case DONE	: printf("��" ); break;
				case OPTIMUM : printf("��"); break;

				}
			}
			printf("\n");
		}
		printf( "=============================================\n");
		if( fp != stdout ) fclose(fp);
		//������ �ݾ��ش�.
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
		setBeginEnd(); //���۰� �� ��ġ�� ã�� �����ϴ� �Լ�
		CksPoint2D *pt;

		while ( (pt=m_stack.pop())!=NULL ){//pt�� NULL�� �ƴҶ� ���� pop
			int x = pt->x; // ��ŸƮ x ��ǥ �ǹ�
			int y = pt->y; // ��ŸƮy��ǥ �ǹ�

			if( isExitPos(x,y) ){ //�̷��� ���� ã�Ƴ���.
				OptimalPath(*pt);
				
				return;
			}
			else {
				m_maze[y][x] = DONE; //������ ���� ǥ����
				OptimalPath(*pt);

				if (isValidPos(x+1, y) && isPossiblePos(x+1, y) || isExitPos(x+1, y)){
					m_stack.push(x+1, y); // ���ÿ� push
				}// ������ => �̷� ���� ��ġ�ϴ��� Ȯ�� && �����ִ� �� ���� Ȯ�� || �ⱸ���� Ȯ�� 
				if (isValidPos(x-1, y) && isPossiblePos(x - 1, y) || isExitPos(x - 1, y)){
					m_stack.push(x-1, y); // ���ÿ� push
				}// ���� => �̷� ���� ��ġ�ϴ��� Ȯ�� && �����ִ� �� ���� Ȯ�� || �ⱸ���� Ȯ��
				if (isValidPos(x, y+1) && isPossiblePos(x, y+1) || isExitPos(x , y+1)){
					m_stack.push(x, y+1); // ���ÿ� push
				}// ���� => �̷� ���� ��ġ�ϴ��� Ȯ�� && �����ִ� �� ���� Ȯ�� || �ⱸ���� Ȯ��
				if (isValidPos(x, y-1) && isPossiblePos(x, y-1) || isExitPos(x , y-1)){
					m_stack.push(x, y-1); // ���ÿ� push
				}// �Ʒ��� => �̷� ���� ��ġ�ϴ��� Ȯ�� && �����ִ� �� ���� Ȯ�� || �ⱸ���� Ȯ��
			}
			
			Print("maze1.txt");
			printf("[%d][%d]=====>[%d][%d]", x,y, m_exit.x, m_exit.y);
			Sleep(100);
		}
		
	}
	
	bool isValidPos(int x, int y){
		//�̷�ũ�� ������ �ƴ����� �˻�
		return (x>=0 && x<m_w && y>=0 && y<m_h);
	}
	bool isExitPos(int x, int y){
		//�̷��� �ⱸ������ �˻�
		return (x==m_exit.x && y==m_exit.y);
	}
	bool isPossiblePos(int x, int y){
		return (m_maze[y][x] == EMPTY);
		//�̷� (EMPTY)��������� �˻�.
	}

};