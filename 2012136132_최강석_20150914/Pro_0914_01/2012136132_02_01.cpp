#include <stdio.h.>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

double cksPowerIter (double x, int n);//�ݺ��Լ�
double cksPowerRecur(double x, int n);//��ȯ�Լ�

void main()
{
	clock_t t0, t1, t2; //�ð��� ���� �̿��� �Լ��ð��� ���� ������
	double time_A, time_B;// �ð�����
	double x; //�ŵ����� ��ų ��

	printf("�ŵ������� ��ų ���ڸ� �Է��ϼ��� : ");
	scanf("%lf", &x);
	printf("==========================================\n");

	for (int i = 1000; i <=  7000; i += 100) //1000���� 7000���� 1000������ (n��)
	{
		printf("%d�� ���� ������ �Լ��� ����ӵ�\n", i);
		
		t0 = clock(); //�ݺ� �Լ� ȣ���ϱ� �� �ð�.
		cksPowerIter (x, i); //�ݺ��Լ� ȣ��
		t1 = clock(); //�ݺ��Լ� ȣ���� �ð�
		cksPowerRecur (x, i); //��ȯ�Լ� ȣ��
	 	t2 = clock(); //��ȯ�Լ� ȣ���� �ð�
		time_A = (double)(t1 - t0) / CLOCKS_PER_SEC; //�ð�����
		time_B = (double)(t2 - t1) / CLOCKS_PER_SEC;

		printf("��ȯ�Լ� �ð� : %lf ", time_A);
		printf("��ȯ�Լ� �ð�: %lf  \n", time_B);
		printf("----------------------------------------\n");
	}
}

double cksPowerIter (double x, int n) //�ݺ��Լ� 
{
	int i;
	double r = 1.0;
	for (i = 0; i <= n; i++) 
	{
		r = r * x; //���� 1�� r���� �ݺ������� x�� �����ش�.
		Sleep(1); //�ð������Լ�
	}
	return r;	//x�� n���� ��������� ��ȯ�ȴ�.
}

double cksPowerRecur(double x, int n) //��ȯ�Լ� 
{
	if (n == 0) 
	{
		Sleep(1);
		return 1.0;
	}
	else if (n % 2 == 0) // n�� ¦���� ���
	{
		Sleep(1);
		return cksPowerRecur(x * x, n / 2);
	}
	else // n�� Ȧ���� ���
	{
		Sleep(1);
		return x * cksPowerRecur(x * x, (n - 1) / 2);
	}
	//��������� x�� n���� ��ȯ�ȴ�.
}