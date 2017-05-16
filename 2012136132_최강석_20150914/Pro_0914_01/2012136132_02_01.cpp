#include <stdio.h.>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

double cksPowerIter (double x, int n);//반복함수
double cksPowerRecur(double x, int n);//순환함수

void main()
{
	clock_t t0, t1, t2; //시간의 차를 이용해 함수시간을 구할 변수들
	double time_A, time_B;// 시간저장
	double x; //거듭제곤 시킬 값

	printf("거듭제곱을 시킬 숫자를 입력하세요 : ");
	scanf("%lf", &x);
	printf("==========================================\n");

	for (int i = 1000; i <=  7000; i += 100) //1000부터 7000까지 1000씩증가 (n값)
	{
		printf("%d일 때의 각각의 함수의 수행속도\n", i);
		
		t0 = clock(); //반복 함수 호출하기 전 시간.
		cksPowerIter (x, i); //반복함수 호출
		t1 = clock(); //반복함수 호출후 시간
		cksPowerRecur (x, i); //순환함수 호출
	 	t2 = clock(); //순환함수 호출후 시간
		time_A = (double)(t1 - t0) / CLOCKS_PER_SEC; //시간저장
		time_B = (double)(t2 - t1) / CLOCKS_PER_SEC;

		printf("반환함수 시간 : %lf ", time_A);
		printf("순환함수 시간: %lf  \n", time_B);
		printf("----------------------------------------\n");
	}
}

double cksPowerIter (double x, int n) //반복함수 
{
	int i;
	double r = 1.0;
	for (i = 0; i <= n; i++) 
	{
		r = r * x; //값이 1인 r값에 반복적으로 x를 곱해준다.
		Sleep(1); //시간지연함수
	}
	return r;	//x의 n승이 결과적으로 반환된다.
}

double cksPowerRecur(double x, int n) //순환함수 
{
	if (n == 0) 
	{
		Sleep(1);
		return 1.0;
	}
	else if (n % 2 == 0) // n이 짝수인 경우
	{
		Sleep(1);
		return cksPowerRecur(x * x, n / 2);
	}
	else // n이 홀수인 경우
	{
		Sleep(1);
		return x * cksPowerRecur(x * x, (n - 1) / 2);
	}
	//결과적으로 x의 n승이 반환된다.
}