#pragma once
#include <stdio.h>

#define MAX_DEGREE 100

class CksPoly
{
	int m_degree;//최고차항의 지수
	double m_coef[MAX_DEGREE];//최고차항의 계수

public:

	//CksPoly(void){ m_degree=0; }
	//생성자
	CksPoly(void) : m_degree(0) {  }
	//주석부분보다 훨씬 효율적인 방법(권장)
	~CksPoly(void){  }

	void  Read()
	{
		printf("다항식의 최고차수를 입력하세요: ");
		scanf("%d", &m_degree);

		printf("각 항의 계수를 입력하세요(총 %d개): ", m_degree+1);
		for(int i=0; i<=m_degree; i++)
			scanf("%lf", &m_coef[i]);//=scanf("%lf", m_coef+i);


	}

	void Print( char *msg )//문자열을 받아 그 문자열을 출력
	{
		printf("%6s ", msg);
		for(int i=0; i<m_degree; i++)
		{ //최고차항서부터 1차까지 출력
			printf("(%4.2fx^%d) + ", m_coef[i], m_degree-i);
		}
		//상수 출력
		printf("(%4.2f) ", m_coef[m_degree]);
		printf("\n");
	}

	void Print2( char *msg )
	{
		printf("%6s ", msg);
		if(m_degree>0){//최고차항이 1이상인경우 x^(최고차항)을 출력
			printf("%4.2fx^%d ", m_coef[0], m_degree);
			for(int i=1; i<m_degree; i++){
				// 최고차항다음이 상수가 아닌경우 음수가아니면 + 문자를 출력
				// 음수면 출력을 안해주고 x^%d를 출력을 해준다.
				//for문안에 있으므로 상수가 되기전까지 출력이됨
				if(m_coef[i]!=0){
					if(m_coef[i]>0){
						printf(" + ");
					}
					printf("%4.2fx^%d ", m_coef[i], m_degree-i);
				}
			}
			if( m_coef[m_degree]!=0){//최고차항이 1이상일 경우 상수값이 +면 "+"를 출력
				//그다음 상수출력
				if(m_coef[m_degree]>0){
					printf(" + ");
				}
				printf("%4.2f ", m_coef[m_degree]);

			}

		}else{//최고차항이 없을 때 상수만 존재할경우 
			printf("%4.2f ", m_coef[m_degree]);
		}
		printf("\n");
	}

	void Add(CksPoly& a, CksPoly& b) 
	{
		int apos = 0, bpos = 0, cpos = 0; //배열인덱스변수
		int degree_a = a.m_degree;
		int degree_b = b.m_degree;
		m_degree = (a.m_degree > b.m_degree) ? a.m_degree : b.m_degree;
		//c객체의 차수 결정을 하기위해 써줌
		while (apos <= a.m_degree && bpos <= b.m_degree)
		{
			if (degree_a > degree_b) //a항 > b항일때
			{
				m_coef[cpos++] = a.m_coef[apos++];//a항 +부호
				degree_a--;
			}
			else if (degree_a == degree_b) //a == b항일때
			{
				m_coef[cpos++] = a.m_coef[apos++] + b.m_coef[bpos++];//a항+b항
				degree_a--;
				degree_b--;
			}			
			else //a항 < b항일때
			{
				m_coef[cpos++] = b.m_coef[bpos++]; //b항 +부호
				degree_b--;
			}
		}
	}
	void Mult(CksPoly& a, CksPoly& b){
		int i, j, k;

		m_degree=a.m_degree + b.m_degree;
		//최고차항의 지수는 제일큰 지수들의 합이다
		for(int z=0; z<=m_degree; z++){
			m_coef[z]=0;
		}//for문을 넣어주어 m_coef값을 0으로 초기화시켜준다.

		for(i=0; i <= a.m_degree; i++){
			for(j=0; j <= b.m_degree; j++){
				for(k=0; k <= m_degree; k++){
					if((i+j) == k){//i+j는 a와b를 곱해주면 그 차수는 더해준 값을 나타낸다.
						//그래서 만약 k(결과의 차수)와 같게되면 
						//그 차수의 지수들을 곱해준값을 대입을해준다.
						m_coef[k] += a.m_coef[i] * b.m_coef[j];
					}
				}
			}
		}
	}
	void Trim()
	{	//최고차항부터검색을 하여 차수를 하나씩 줄여서
		//차수의 계수가 0이 안나올때까지 n을 ++연산을 
		//통하여 구한다음에 최고차항(m_degree) 에 n을 빼준 값을
		//넣어준다.
		int n=0;

		for(int i=0; i<m_degree; i++)
		{//차수의 계수가 0이 안나올때 까지 n++연산
			if(m_coef[i]==0)
				n++;
			else if(m_coef[i] != 0)
				break;
		}

		for(int i=0; i<m_degree; i++)
		{
			m_coef[i] = m_coef[i+n];
			//최고차항의 계수가 0인 수가 나온만큼 배열을 당긴다
		}

		m_degree -= n;//지수를 감소시킴


	}
};

