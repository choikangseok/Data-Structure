#pragma once

#include<stdio.h>

const int MaxQueueSize = 10;

class CksQueue{
	int m_front;	//���� �ֱٿ� ������ ��ġ.
	int m_rear;		//���� �ֱٿ� ���ε� ��ġ.
	int m_data[MaxQueueSize];

public:
	CksQueue(void){
		m_front = m_rear = 0; //������·� ������ش�.
	}
	~CksQueue(void){}
	bool IsEmpty(){ return m_front == m_rear;} //front�� rear�� ������ �������.
	bool IsFull() { return m_front == (m_rear+1)%MaxQueueSize;} 
      //���ܰ� �Ĵ��� ��ġ�� 1�ۿ� ���̳��� ���� ���
	void EnQueue(int i){
		if(IsFull()){//���������� ���.
			printf("ť�� ���� �� �ֽ��ϴ�.\n");	
			return;
		}
		m_rear++;  
		m_rear = m_rear % MaxQueueSize;
		m_data[m_rear] = i;
                //�Ĵ��� ++�� ���־� ���� ������ ���� �Ĵܿ� ������ ���ְ� 
                //�� ���� �����͸� �־��ش�.
	}
	int DeQueue(){
		if(IsEmpty()){//ť�� ������� ���.
			printf("ť�� ��� �ֽ��ϴ�.\n");
			return -1;
		}
		m_front++;
		m_front = m_front % MaxQueueSize;
		return m_data[m_front];
                //������ ++�� ���־� ���� ������ ���� ���ܿ� ������ ���ְ�
                //�� ���� �����͸� �־��ش�.
	}
	int peek(){
		if(IsEmpty()){
			printf("ť�� ��� �ֽ��ϴ�.\n");
			return -1;
		}
		return m_data[(m_front+1)% MaxQueueSize];
               //������ �����͸� �ҷ����δ�.
	}
	void Display(){
		if(!IsEmpty()){//������ �ƴ� ��쿡 ���.
			int from = m_front + 1;
			int to = m_rear;
			if(from > to) 
				to += MaxQueueSize;
				for(int i =from ;from < to; from ++)
					printf("%3d", m_data[from%MaxQueueSize]);
                                        //���θ� ���� ������ �������� ����� ���ش�.
		}
		printf("\n");
	}

};