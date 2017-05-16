#pragma once
#include "CksQueue.h"
class CksDeQueue : public CksQueue{

public:

	CksDeQueue(void){}
	~CksDeQueue(void){}
	void AddRear(int i){ EnQueue(i);}
	void AddFront(int i){
		if(IsFull()){//���������� ���.
			printf("���� ���� �� �ֽ��ϴ�.\n");	
			return;
		}
		
		m_data[m_front] = i;
		m_front = (m_front-1 +MaxQueueSize) % MaxQueueSize;
		if(m_front < 0) m_front = MaxQueueSize -1;
                //�Ĵ��� ++�� ���־� ���� ������ ���� �Ĵܿ� ������ ���ְ� 
                //�� ���� �����͸� �־��ش�.
	}
	int DelFront(){ return DeQueue();}
	int DelRear(){
		if(IsEmpty()){//ť�� ������� ���.
			printf("���� ��� �ֽ��ϴ�.\n");
			return -1;
		}

		int ret =m_data[m_rear];
		m_rear = (m_rear-1 +MaxQueueSize) % MaxQueueSize;
		return ret;
	}
	int getFront(){ return Peek();}

	int getrear(){
		if(IsEmpty()){
			printf("ť�� ��� �ֽ��ϴ�.\n");
			return -1;
		}
		return m_data[m_rear];
               //������ �����͸� �ҷ����δ�.
	}

};

