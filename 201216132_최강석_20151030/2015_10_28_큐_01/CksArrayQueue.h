#pragma once

#include<stdio.h>

const int MaxQueueSize = 10;

class CksQueue{
	int m_front;	//가장 최근에 삭제된 위치.
	int m_rear;		//가장 최근에 삽인된 위치.
	int m_data[MaxQueueSize];

public:
	CksQueue(void){
		m_front = m_rear = 0; //공백상태로 만들어준다.
	}
	~CksQueue(void){}
	bool IsEmpty(){ return m_front == m_rear;} //front와 rear이 같으면 공백상태.
	bool IsFull() { return m_front == (m_rear+1)%MaxQueueSize;} 
      //전단과 후단위 위치가 1밖에 차이나지 않을 경우
	void EnQueue(int i){
		if(IsFull()){//가득차있을 경우.
			printf("큐가 가득 차 있습니다.\n");	
			return;
		}
		m_rear++;  
		m_rear = m_rear % MaxQueueSize;
		m_data[m_rear] = i;
                //후단을 ++를 해주어 모듈로 연산을 통해 후단에 대입을 해주고 
                //그 값에 데이터를 넣어준다.
	}
	int DeQueue(){
		if(IsEmpty()){//큐가 비어있을 경우.
			printf("큐가 비어 있습니다.\n");
			return -1;
		}
		m_front++;
		m_front = m_front % MaxQueueSize;
		return m_data[m_front];
                //전단을 ++를 해주어 모듈로 연산을 통해 전단에 대입을 해주고
                //그 값에 데이터를 넣어준다.
	}
	int peek(){
		if(IsEmpty()){
			printf("큐가 비어 있습니다.\n");
			return -1;
		}
		return m_data[(m_front+1)% MaxQueueSize];
               //전단의 데이터를 불러들인다.
	}
	void Display(){
		if(!IsEmpty()){//공백이 아닌 경우에 출력.
			int from = m_front + 1;
			int to = m_rear;
			if(from > to) 
				to += MaxQueueSize;
				for(int i =from ;from < to; from ++)
					printf("%3d", m_data[from%MaxQueueSize]);
                                        //모듈로를 통해 원형의 개념으로 출력을 해준다.
		}
		printf("\n");
	}

};