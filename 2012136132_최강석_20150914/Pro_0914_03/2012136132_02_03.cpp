#include<stdio.h>

void hanoi_tower(int n, char from, char tmp, char to);
//�ϳ���Ÿ�� �Լ�
void hanoi_tower_noprint(int n, char from, char tmp, char to); 
//����̾��� �ϳ���Ÿ�� �Լ�
int count = 0; // ������ �� ������ Ƚ��getchar();

void main(){
	int n, i;
	printf("������ ������ �Է��ϼ��� : ");
	scanf("%d", &n);
	hanoi_tower(n, 'A', 'B', 'C');
	//��������� ����ִ� �ϳ���Ÿ�� �Լ� ȣ��

	printf("������ �� ������ Ƚ�� : %d \n", count);
	printf("--------------------------------\n");

	for(i= 3; i<=15; i++){
		//3������ 15������ ���ǿ��� ���� �� ������ Ƚ���� ���
		count=0;//�ʱ�ȭ�� ���ش�.
		hanoi_tower_noprint(i, 'A', 'B', 'C');
		printf("%5d���� ���ǿ��� �� ������ Ƚ�� : %d\n", i, count);
	}
	getchar();
	getchar();
}

void hanoi_tower(int n, char from, char tmp, char to){
	//��������� ����ִ� �ϳ���Ÿ�� �Լ�
	count++;
	if(n==1){
		printf("%c => %c (ũ�Ⱑ 1�� ����)\n", from, to);
	}
	else{
		hanoi_tower(n-1, from, to ,tmp);
		printf(" %c => %c (ũ�Ⱑ %d�� ����).\n", from, to, n);
		hanoi_tower(n-1, tmp, from, to);
	}
}
void hanoi_tower_noprint(int n, char from, char tmp, char to){
//����� ���� �ϳ���Ÿ�� �Լ�.
//��ºκ� ����� ������ �� �Լ��� ����.
	count++;
	if(n==1){
	}
	else{
		hanoi_tower_noprint(n-1, from, to ,tmp);
		hanoi_tower_noprint(n-1, tmp, from, to);
	}
}
