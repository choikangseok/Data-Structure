#pragma once
#include <stdio.h>
class CksMatrix
{
	int m_rows;//���� ��Ÿ���� ����
	int m_cols;//���� ��Ÿ���� ����
	double** m_elem;
public:

	CksMatrix(void) : m_rows(0), m_cols(0), m_elem(NULL)	{}
	//������ 0�� null�� �ʱ�ȭ�� ���ش�.
	~CksMatrix(void)	{
	DeleteMem();//�����Ҵ�� �޸𸮸� ����
	}
	void AllocMem( int r, int c){//�޸𸮸� �Ҵ��ϱ����� �Լ�
		if( r<=0 || c<=0) return ;//�� ���� 0�̸��ϰ�� �Լ�����
		m_rows= r;
		m_cols= c;
		//Ŭ������ ������� �Ű������� ���� �־���.
		m_elem = new double* [m_rows];
		//�������� �����Ҵ��� ����
		//������ �迭 �����̵ȴ�.
		for(int i = 0; i<m_rows ; i++)
			m_elem[i] = new double [m_cols];
		//������ �迭�� ����Ű�°͵��� ��迭��(�����Ҵ� �Ŀ�)
	}
	void DeleteMem(){
		if(m_elem != NULL){
			for(int i = 0; i<m_rows; i++)
				delete [] m_elem[i];
			delete [] m_elem;
			//�޸� �Ҹ��� �࿡���� �Ҹ� ���� �״���.
			//�������� �Ҹ� ������ ���ش�.
		
		}
	}
	void Read(){
		printf("����� ���Ǽ��� ���Ǽ��� �Է��Ͻÿ� : ");
		int r, c;
		scanf("%d %d", &r, &c);
		AllocMem(r, c); //���� �޸𸮸� �Ҵ�
		printf("�� ���� �Է��Ͻÿ� (�� %d��): ", r*c);
		for(int i=0; i<r ; i++)
			for(int j=0; j<c ; j++)
				scanf("%lf", &(m_elem[i][j]));
//�� ���� �Է��� ����.
	}

	void print(char *msg = "Matrix = "){
		//Ư���� ��ü������ ����� ������ش�.
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
		//�� ��ü�� ��� ���� �ٸ��� �Լ� ����.
		//�ƴҰ�� �Ű�����(���۷���)�� ��� ����ŭ
		//���� �����Ҵ����ش�.
		AllocMem(a.m_rows, a.m_cols);
		for(int i = 0; i<m_rows; i++){
			for(int j=0; j<m_cols ; j++){
				m_elem[i][j]=a.m_elem[i][j]+b.m_elem[i][j];
				// ���۷��� a,b(��ü)�� [i][j]����
				//���� ���� Ŭ���� m_elem[i][j]��
				//�־��ش�.
			}
		}

	}


};
