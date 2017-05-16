#pragma once
#include <stdio.h>
#define MAX_STACK_SIZE 100 //���û�����
typedef char CElement;

class CksStack
{
	CElement m_data[MAX_STACK_SIZE];
	int m_top;
public:
	CksStack(void) { Reset();}
	~CksStack(void) { }
	//������
	void Reset() {m_top = 0;}
	//������ ���ָ� ������ ����Ű�� ���� 0�� °�� �������� �ٲ���
	bool IsEmpty(){return m_top == 0;}
	//������ ���̸� TRUE ���� �ƴϸ� FALSE
	bool IsFull() { return m_top ==MAX_STACK_SIZE;}
	//������ ����Ű�� ���� 100����� �Ǹ� TRUE
	//�ƴ� ��� FALSE

	void Push ( CElement e ) {
		//���� �ױ� �Լ�
		if( IsFull()) {
			printf("Error: ���� ��ȭ ����\n");
			return;
			//������ ��ȭ�϶� ��ȭ���� �޼��� ���
		}
		m_data[m_top++] = e;
		//������ ��ȭ�� ����������� �ش� ���� ������ ���ְ�
		//���� ����Ű�� ���� ++������.
	}
	CElement Pop () {
		//������ ����
		if(IsEmpty()){
			//������ ���̶�� ������ ������ش�.
			printf("Error : ���� ���� ����\n");
			return 0;
		}
		return m_data[--m_top];
		//������ ���� �ƴ϶�� �ش��ϴ� ������ --
		//�� ���� �������ش�.
	}
	CElement Peek (){
		//���õ� ���� ���� �ֱ� ���� ������ش�.
		if(IsEmpty()){
			//������ �� ���� ���� ���� ���� ���
			printf("Error : ���� ���� ����\n");
			return 0;
		}
		//���� ������ ����Ű�� �� �������� ������ �ǹǷ�
		//1�� ���ְ� ������ش�.
		return m_data[m_top-1];
		//m_top�� ������ ����.
	}
	//�߰����� ��� �Լ�
	void Display(){
		//���� ���.
		printf("[���� �׸��� �� = %2d]\n", m_top);
		for(int i =0 ; i<m_top ; i++){
			printf("<%c>", m_data[i]);
			printf("\n");
		}
	}
};