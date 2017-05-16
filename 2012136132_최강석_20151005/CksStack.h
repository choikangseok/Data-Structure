#pragma once
#include <stdio.h>
#define MAX_STACK_SIZE 100 //스택사이즈
typedef char CElement;

class CksStack
{
	CElement m_data[MAX_STACK_SIZE];
	int m_top;
public:
	CksStack(void) { Reset();}
	~CksStack(void) { }
	//생성자
	void Reset() {m_top = 0;}
	//리셋을 해주면 스택이 가리키는 값은 0번 째의 성분으로 바꿔줌
	bool IsEmpty(){return m_top == 0;}
	//스택이 빈값이면 TRUE 빈값이 아니면 FALSE
	bool IsFull() { return m_top ==MAX_STACK_SIZE;}
	//스택이 가리키는 값이 100사이즈가 되면 TRUE
	//아닐 경우 FALSE

	void Push ( CElement e ) {
		//스택 쌓기 함수
		if( IsFull()) {
			printf("Error: 스택 포화 에러\n");
			return;
			//스택이 포화일때 포화에러 메세지 출력
		}
		m_data[m_top++] = e;
		//스택이 포화가 되지않을경우 해당 값을 스택을 해주고
		//스택 가리키는 값을 ++를해줌.
	}
	CElement Pop () {
		//스택을 빼줌
		if(IsEmpty()){
			//스택이 빈값이라면 에러를 출력해준다.
			printf("Error : 스택 공백 에러\n");
			return 0;
		}
		return m_data[--m_top];
		//스택이 빈값이 아니라면 해당하는 스택을 --
		//을 통해 제거해준다.
	}
	CElement Peek (){
		//스택된 값중 제일 최근 값을 출력해준다.
		if(IsEmpty()){
			//스택이 빈 값일 경우는 스택 에러 출력
			printf("Error : 스택 공백 에러\n");
			return 0;
		}
		//현재 스택이 가리키는 값 이전까지 스택이 되므로
		//1을 빼주고 출력해준다.
		return m_data[m_top-1];
		//m_top은 변함이 없다.
	}
	//추가적인 멤버 함수
	void Display(){
		//스택 출력.
		printf("[스택 항목의 수 = %2d]\n", m_top);
		for(int i =0 ; i<m_top ; i++){
			printf("<%c>", m_data[i]);
			printf("\n");
		}
	}
};