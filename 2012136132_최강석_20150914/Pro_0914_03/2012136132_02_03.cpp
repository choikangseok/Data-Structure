#include<stdio.h>

void hanoi_tower(int n, char from, char tmp, char to);
//하노이타워 함수
void hanoi_tower_noprint(int n, char from, char tmp, char to); 
//출력이없는 하노이타워 함수
int count = 0; // 원판의 총 움직인 횟수getchar();

void main(){
	int n, i;
	printf("원판의 개수를 입력하세요 : ");
	scanf("%d", &n);
	hanoi_tower(n, 'A', 'B', 'C');
	//출력정보가 들어있는 하노이타워 함수 호출

	printf("원판이 총 움직인 횟수 : %d \n", count);
	printf("--------------------------------\n");

	for(i= 3; i<=15; i++){
		//3개부터 15개까지 원판에서 각각 총 움직인 횟수를 출력
		count=0;//초기화를 해준다.
		hanoi_tower_noprint(i, 'A', 'B', 'C');
		printf("%5d개의 원판에서 총 움직인 횟수 : %d\n", i, count);
	}
	getchar();
	getchar();
}

void hanoi_tower(int n, char from, char tmp, char to){
	//출력정보가 들어있는 하노이타워 함수
	count++;
	if(n==1){
		printf("%c => %c (크기가 1인 원판)\n", from, to);
	}
	else{
		hanoi_tower(n-1, from, to ,tmp);
		printf(" %c => %c (크기가 %d인 원판).\n", from, to, n);
		hanoi_tower(n-1, tmp, from, to);
	}
}
void hanoi_tower_noprint(int n, char from, char tmp, char to){
//출력이 없는 하노이타워 함수.
//출력부분 빼고는 나머지 위 함수와 같다.
	count++;
	if(n==1){
	}
	else{
		hanoi_tower_noprint(n-1, from, to ,tmp);
		hanoi_tower_noprint(n-1, tmp, from, to);
	}
}
