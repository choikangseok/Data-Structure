#pragma once
#include <stdio.h>

#define MAX_DEGREE 100

class CksPoly
{
	int m_degree;//�ְ������� ����
	double m_coef[MAX_DEGREE];//�ְ������� ���

public:

	//CksPoly(void){ m_degree=0; }
	//������
	CksPoly(void) : m_degree(0) {  }
	//�ּ��κк��� �ξ� ȿ������ ���(����)
	~CksPoly(void){  }

	void  Read()
	{
		printf("���׽��� �ְ������� �Է��ϼ���: ");
		scanf("%d", &m_degree);

		printf("�� ���� ����� �Է��ϼ���(�� %d��): ", m_degree+1);
		for(int i=0; i<=m_degree; i++)
			scanf("%lf", &m_coef[i]);//=scanf("%lf", m_coef+i);


	}

	void Print( char *msg )//���ڿ��� �޾� �� ���ڿ��� ���
	{
		printf("%6s ", msg);
		for(int i=0; i<m_degree; i++)
		{ //�ְ����׼����� 1������ ���
			printf("(%4.2fx^%d) + ", m_coef[i], m_degree-i);
		}
		//��� ���
		printf("(%4.2f) ", m_coef[m_degree]);
		printf("\n");
	}

	void Print2( char *msg )
	{
		printf("%6s ", msg);
		if(m_degree>0){//�ְ������� 1�̻��ΰ�� x^(�ְ�����)�� ���
			printf("%4.2fx^%d ", m_coef[0], m_degree);
			for(int i=1; i<m_degree; i++){
				// �ְ����״����� ����� �ƴѰ�� �������ƴϸ� + ���ڸ� ���
				// ������ ����� �����ְ� x^%d�� ����� ���ش�.
				//for���ȿ� �����Ƿ� ����� �Ǳ������� ����̵�
				if(m_coef[i]!=0){
					if(m_coef[i]>0){
						printf(" + ");
					}
					printf("%4.2fx^%d ", m_coef[i], m_degree-i);
				}
			}
			if( m_coef[m_degree]!=0){//�ְ������� 1�̻��� ��� ������� +�� "+"�� ���
				//�״��� ������
				if(m_coef[m_degree]>0){
					printf(" + ");
				}
				printf("%4.2f ", m_coef[m_degree]);

			}

		}else{//�ְ������� ���� �� ����� �����Ұ�� 
			printf("%4.2f ", m_coef[m_degree]);
		}
		printf("\n");
	}

	void Add(CksPoly& a, CksPoly& b) 
	{
		int apos = 0, bpos = 0, cpos = 0; //�迭�ε�������
		int degree_a = a.m_degree;
		int degree_b = b.m_degree;
		m_degree = (a.m_degree > b.m_degree) ? a.m_degree : b.m_degree;
		//c��ü�� ���� ������ �ϱ����� ����
		while (apos <= a.m_degree && bpos <= b.m_degree)
		{
			if (degree_a > degree_b) //a�� > b���϶�
			{
				m_coef[cpos++] = a.m_coef[apos++];//a�� +��ȣ
				degree_a--;
			}
			else if (degree_a == degree_b) //a == b���϶�
			{
				m_coef[cpos++] = a.m_coef[apos++] + b.m_coef[bpos++];//a��+b��
				degree_a--;
				degree_b--;
			}			
			else //a�� < b���϶�
			{
				m_coef[cpos++] = b.m_coef[bpos++]; //b�� +��ȣ
				degree_b--;
			}
		}
	}
	void Mult(CksPoly& a, CksPoly& b){
		int i, j, k;

		m_degree=a.m_degree + b.m_degree;
		//�ְ������� ������ ����ū �������� ���̴�
		for(int z=0; z<=m_degree; z++){
			m_coef[z]=0;
		}//for���� �־��־� m_coef���� 0���� �ʱ�ȭ�����ش�.

		for(i=0; i <= a.m_degree; i++){
			for(j=0; j <= b.m_degree; j++){
				for(k=0; k <= m_degree; k++){
					if((i+j) == k){//i+j�� a��b�� �����ָ� �� ������ ������ ���� ��Ÿ����.
						//�׷��� ���� k(����� ����)�� ���ԵǸ� 
						//�� ������ �������� �����ذ��� ���������ش�.
						m_coef[k] += a.m_coef[i] * b.m_coef[j];
					}
				}
			}
		}
	}
	void Trim()
	{	//�ְ����׺��Ͱ˻��� �Ͽ� ������ �ϳ��� �ٿ���
		//������ ����� 0�� �ȳ��ö����� n�� ++������ 
		//���Ͽ� ���Ѵ����� �ְ�����(m_degree) �� n�� ���� ����
		//�־��ش�.
		int n=0;

		for(int i=0; i<m_degree; i++)
		{//������ ����� 0�� �ȳ��ö� ���� n++����
			if(m_coef[i]==0)
				n++;
			else if(m_coef[i] != 0)
				break;
		}

		for(int i=0; i<m_degree; i++)
		{
			m_coef[i] = m_coef[i+n];
			//�ְ������� ����� 0�� ���� ���¸�ŭ �迭�� ����
		}

		m_degree -= n;//������ ���ҽ�Ŵ


	}
};

