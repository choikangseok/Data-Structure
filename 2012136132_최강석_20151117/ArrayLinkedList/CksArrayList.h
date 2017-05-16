#pragma once
#include <stdio.h>
const int MAX_LIST_SIZE=100;
typedef int CElement;

class CksArrayList{
	CElement m_data[MAX_LIST_SIZE] ;//������ ����
	int m_len; //�������� ��
public:
	CksArrayList(void){m_len=0;}//������
	~CksArrayList(void){}//�Ҹ���

	bool IsEmpty(){	return m_len==0;}//�������� ���� 0 �� ���� ��
	bool IsFull() {	return m_len==MAX_LIST_SIZE;}//�����Ͱ� �������� ���
	CElement GetEntry(int pos){ return m_data[pos];}//(pos�� ��ġ)�ش� �Ǵ� �������� ���� ��ȯ
	int GetLength(){ return m_len;}//�������� ���̸� ��ȯ�մϴ�.
	void Clear() {m_len = 0;}//�������� ���� 0���� �����մϴ�.
	void Replace (int pos, CElement e){ m_data[pos] = e;}//pos�� ��ġ�� �����͸� e�� �ٲپ� �ݴϴ�.
	void Display(char* str){//�����͵��� ����մϴ�.

		printf("       [%s��ü �׸� �� = %2d] : ",str, m_len);
		for(int i =0 ; i<m_len ; i++)
			printf(" %2d    ", m_data[i]);
		printf("\n");
	}
	void Add(int pos, CElement e){//pos�� ��ġ�� Add�� �����ݴϴ�.
		if(!IsFull() && pos >=0){
			for(int i = m_len; i>pos; i--)
				m_data[i]=m_data[i-1];
			m_data[pos]=e;
			m_len++;
		}
	}
	void AddTail(CElement e){Add(m_len, e); }//�迭�������� ���ܿ� e�� �߰��� �ݴϴ�.
	void AddHead(CElement e){Add(0,e);}//�迭�������� �պκп� e�� �߰����ݴϴ�.
	CElement RemoveHead(){return Remove(0);}//�迭�������� �պκ��� �����ݴϴ�.
	CElement RemoveTail(){return Remove(m_len);}//�迭�������� ������ �����ݴϴ�.
	CElement Remove(int pos){ //�迭�������� pos�� ��ġ�� �迭�� �����ݴϴ�.
		if(0<=pos && pos<=m_len){
			CElement elem = m_data[pos];
			for(int i=pos+1; i<m_len; i++)
				m_data[i-1] = m_data[i];
			m_len--;
			return elem;
		}
		else 
			printf("��ġ ����\n");
	}
};