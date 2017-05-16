#pragma once
#include <stdio.h>
class CksMatrix
{
	int m_rows;//열을 나타내줄 변수
	int m_cols;//행을 나타내줄 변수
	double** m_elem;
public:

	CksMatrix(void) : m_rows(0), m_cols(0), m_elem(NULL)	{}
	//생성자 0과 null로 초기화를 해준다.
	~CksMatrix(void)	{
	DeleteMem();//동적할당된 메모리를 제거
	}
	void AllocMem( int r, int c){//메모리를 할당하기위한 함수
		if( r<=0 || c<=0) return ;//행 열이 0미만일경우 함수종료
		m_rows= r;
		m_cols= c;
		//클래스의 행과열에 매개변수의 값을 넣어줌.
		m_elem = new double* [m_rows];
		//열에대한 동적할당을 해줌
		//포인터 배열 생성이된다.
		for(int i = 0; i<m_rows ; i++)
			m_elem[i] = new double [m_cols];
		//포인터 배열이 가리키는것들은 행배열들(동적할당 후에)
	}
	void DeleteMem(){
		if(m_elem != NULL){
			for(int i = 0; i<m_rows; i++)
				delete [] m_elem[i];
			delete [] m_elem;
			//메모리 소멸은 행에대한 소멸 먼저 그다음.
			//열에대한 소멸 순으로 해준다.
		
		}
	}
	void Read(){
		printf("행렬의 행의수와 열의수를 입력하시오 : ");
		int r, c;
		scanf("%d %d", &r, &c);
		AllocMem(r, c); //실제 메모리를 할당
		printf("각 항을 입력하시오 (총 %d개): ", r*c);
		for(int i=0; i<r ; i++)
			for(int j=0; j<c ; j++)
				scanf("%lf", &(m_elem[i][j]));
//각 항을 입력을 받음.
	}

	void print(char *msg = "Matrix = "){
		//특정한 객체에대한 행렬을 출력해준다.
		printf("%s [%d x %d]\n", msg, m_rows, m_cols);
		for(int i = 0; i<m_rows; i++){
			printf("\n");
			for(int j=0; j<m_cols ; j++)
				printf("%5.1f", m_elem[i][j] );
		}
		printf("\n\n");

	}
	void Add( CksMatrix& a, CksMatrix & b){
		if( a.m_rows != b.m_rows 
			&& a.m_cols != b.m_cols) return;
		//두 객체의 행과 열이 다르면 함수 종료.
		//아닐경우 매개변수(레퍼런스)의 행과 열만큼
		//새로 동적할당해준다.
		AllocMem(a.m_rows, a.m_cols);
		for(int i = 0; i<m_rows; i++){
			for(int j=0; j<m_cols ; j++){
				m_elem[i][j]=a.m_elem[i][j]+b.m_elem[i][j];
				// 레퍼런스 a,b(객체)의 [i][j]성분
				//들의 합을 클래스 m_elem[i][j]에
				//넣어준다.
			}
		}

	}


};
