#pragma once
#include<stdio.h>

#define WALL 0 
#define START 5
#define EXIT 9
#define EMPTY 1
class CksMaze
{
	int m_w; // �̷��� width
	int m_h; // �̷��� height
	int** m_maze; // �̷��� �� �׸� ���� ����
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

				}
			}
			printf("\n");
		}
		printf( "=============================================\n");
		if( fp != stdout ) fclose(fp);
		//������ �ݾ��ش�.
	} 
};