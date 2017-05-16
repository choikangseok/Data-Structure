#include <stdio.h>

int cksFiboIter(int n);//반복함수
int cksFiboRecur(int n);//재귀함수
int count [10];//횟수를 알아보기위한 count 전역변수선언

void main()
{
	int i;
	int j =0;
	
		printf("피보나치 수열에서 원하는 항을 입력하시오  : ");
		scanf("%d", &i); //출력시킬 항 입력
		for(j; j<=i; j++){
			printf("반복함수 = %d	", cksFiboIter(j)); //반복함수 출력
			printf("재귀함수 = %d\n", cksFiboRecur(j)); //재귀함수 출력
		}
		printf("\n재귀함수에서의 각 함수의 호출횟수\n");
		
		
		for(j=0; j<=i; j++){
			count[j]=0; //카운터값을 초기화 시켜준다.
		}

		cksFiboRecur(i);
		for (int j = i; j >= 0; j--) //for문 이용하여 0~입력받은 수까지 반복
			printf("Fibo(%2d) = %d\n", j, count[j]); //count 출력
	getchar();
	getchar();
}
int cksFiboIter(int n) //반복함수
{
	if (n < 2) return n;
	else
	{
		int i, tmp, current = 1, last = 0;
		for (i = 2; i <= n; i++) // 반복 방법
		{
			tmp = current;
			current += last;
			last = tmp;
		}
		return current;
	}
}

int cksFiboRecur(int n) //재귀함수
{
	count[n] ++;

	if (n == 0) return 0;
	else if (n == 1) return 1;
	return (cksFiboRecur(n-1) + cksFiboRecur(n-2)); //반환값을 재귀적인 방법으로 호출
}
