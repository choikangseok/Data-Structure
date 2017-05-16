#pragma once
#include "CksQueue.h"
class CksDeQueue : public CksQueue{

public:

	CksDeQueue(void){}
	~CksDeQueue(void){}
	void AddRear(int i){ EnQueue(i);}
	void AddFront(int i){
		if(IsFull()){//가득차있을 경우.
			printf("덱이 가득 차 있습니다.\n");	
			return;
		}
		
		m_data[m_front] = i;
		m_front = (m_front-1 +MaxQueueSize) % MaxQueueSize;
		if(m_front < 0) m_front = MaxQueueSize -1;
                //후단을 ++를 해주어 모듈로 연산을 통해 후단에 대입을 해주고 
                //그 값에 데이터를 넣어준다.
	}
	int DelFront(){ return DeQueue();}
	int DelRear(){
		if(IsEmpty()){//큐가 비어있을 경우.
			printf("덱이 비어 있습니다.\n");
			return -1;
		}

		int ret =m_data[m_rear];
		m_rear = (m_rear-1 +MaxQueueSize) % MaxQueueSize;
		return ret;
	}
	int getFront(){ return Peek();}

	int getrear(){
		if(IsEmpty()){
			printf("큐가 비어 있습니다.\n");
			return -1;
		}
		return m_data[m_rear];
               //전단의 데이터를 불러들인다.
	}

};

