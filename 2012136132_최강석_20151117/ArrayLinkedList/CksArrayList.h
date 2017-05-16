#pragma once
#include <stdio.h>
const int MAX_LIST_SIZE=100;
typedef int CElement;

class CksArrayList{
	CElement m_data[MAX_LIST_SIZE] ;//데이터 변수
	int m_len; //데이터의 수
public:
	CksArrayList(void){m_len=0;}//생성자
	~CksArrayList(void){}//소멸자

	bool IsEmpty(){	return m_len==0;}//데이터의 수가 0 일 경우는 참
	bool IsFull() {	return m_len==MAX_LIST_SIZE;}//데이터가 가득차는 경우
	CElement GetEntry(int pos){ return m_data[pos];}//(pos의 위치)해당 되는 데이터의 값을 반환
	int GetLength(){ return m_len;}//데이터의 길이를 반환합니다.
	void Clear() {m_len = 0;}//데이터의 수를 0으로 설정합니다.
	void Replace (int pos, CElement e){ m_data[pos] = e;}//pos의 위치의 데이터를 e로 바꾸어 줍니다.
	void Display(char* str){//데이터들을 출력합니다.

		printf("       [%s전체 항목 수 = %2d] : ",str, m_len);
		for(int i =0 ; i<m_len ; i++)
			printf(" %2d    ", m_data[i]);
		printf("\n");
	}
	void Add(int pos, CElement e){//pos의 위치에 Add를 더해줍니다.
		if(!IsFull() && pos >=0){
			for(int i = m_len; i>pos; i--)
				m_data[i]=m_data[i-1];
			m_data[pos]=e;
			m_len++;
		}
	}
	void AddTail(CElement e){Add(m_len, e); }//배열데이터의 말단에 e를 추가해 줍니다.
	void AddHead(CElement e){Add(0,e);}//배열데이터의 앞부분에 e를 추가해줍니다.
	CElement RemoveHead(){return Remove(0);}//배열데이터의 앞부분을 지워줍니다.
	CElement RemoveTail(){return Remove(m_len);}//배열데이터의 말단을 지워줍니다.
	CElement Remove(int pos){ //배열데이터의 pos에 위치한 배열을 지워줍니다.
		if(0<=pos && pos<=m_len){
			CElement elem = m_data[pos];
			for(int i=pos+1; i<m_len; i++)
				m_data[i-1] = m_data[i];
			m_len--;
			return elem;
		}
		else 
			printf("위치 오류\n");
	}
};