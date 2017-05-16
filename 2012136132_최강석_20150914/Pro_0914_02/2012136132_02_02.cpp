#include <stdio.h>

int cksFiboIter(int n);//�ݺ��Լ�
int cksFiboRecur(int n);//����Լ�
int count [10];//Ƚ���� �˾ƺ������� count ������������

void main()
{
	int i;
	int j =0;
	
		printf("�Ǻ���ġ �������� ���ϴ� ���� �Է��Ͻÿ�  : ");
		scanf("%d", &i); //��½�ų �� �Է�
		for(j; j<=i; j++){
			printf("�ݺ��Լ� = %d	", cksFiboIter(j)); //�ݺ��Լ� ���
			printf("����Լ� = %d\n", cksFiboRecur(j)); //����Լ� ���
		}
		printf("\n����Լ������� �� �Լ��� ȣ��Ƚ��\n");
		
		
		for(j=0; j<=i; j++){
			count[j]=0; //ī���Ͱ��� �ʱ�ȭ �����ش�.
		}

		cksFiboRecur(i);
		for (int j = i; j >= 0; j--) //for�� �̿��Ͽ� 0~�Է¹��� ������ �ݺ�
			printf("Fibo(%2d) = %d\n", j, count[j]); //count ���
	getchar();
	getchar();
}
int cksFiboIter(int n) //�ݺ��Լ�
{
	if (n < 2) return n;
	else
	{
		int i, tmp, current = 1, last = 0;
		for (i = 2; i <= n; i++) // �ݺ� ���
		{
			tmp = current;
			current += last;
			last = tmp;
		}
		return current;
	}
}

int cksFiboRecur(int n) //����Լ�
{
	count[n] ++;

	if (n == 0) return 0;
	else if (n == 1) return 1;
	return (cksFiboRecur(n-1) + cksFiboRecur(n-2)); //��ȯ���� ������� ������� ȣ��
}
