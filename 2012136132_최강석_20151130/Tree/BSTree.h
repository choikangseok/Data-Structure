#pragma once
#include "TNode.h"
class BSTree
{
protected:
	TNode* m_root;//이진트리의 첫번째 노드
public:
	BSTree(void){ m_root = NULL;}
	~BSTree(void){if(m_root!=NULL) m_root;}

	void PrintPreOrder(){
		//PreOrdre순으로 트리 출력.
		printf("[트리내용출력-PreOrder] \n");
		if(m_root!=NULL)	m_root->PreOrder();
		printf("\n");
	}
	void PrintInOrder(){
		//InOrder순으로 트리 출력
		printf("[트리내용출력-InOrder] \n");
		if(m_root!=NULL)	m_root->InOrder();
		printf("\n");
	}
	void PrintPostOrder(){
		//Postorder순으로 트리 출력
		printf("[트리내용출력-PostOrder]\n");
		if(m_root!=NULL)	m_root->PostOrder();
		printf("\n");
	}
	void Add(TNode* n){
	//노드 n을 더해준다.  
		if(n == NULL) return ;
		if(m_root == NULL) {
			m_root = n;
		}else{
			m_root->Add(n);
			//root가 null이 아닐경우 TNode의 Add함수를 호출해준다.
		}
	}

	void FindItem2(char* itemName){
		presence=0;//탐색에 성공할 경우 1값이 대입이된다..
		printf("[반복]  ");
		if(itemName == NULL){
			printf("노드에 입력한 이름 [%s]가 없습니다.\n",itemName);
			return;
		}else{
			m_root->FindItem2(itemName);
			//노드의 반복탐색 함수를 불러준다.
		}
		if(presence==0){
			printf("노드에 입력한 이름 [%s]가 없습니다.\n",itemName);
		}
	}

	void FindItem(char* itemName){
		presence=0;//탐색에 성공할 경우 1값이 대입이된다.
		printf("[재귀]  ");
		if(itemName == NULL) return;
		if(m_root == NULL){
			printf("노드에 입력한 이름 [%s]가 없습니다.\n",itemName);
			return;
		}
		else{
			m_root->FindItem(itemName);
			//노드의 순환탐색 함수를 불러준다.
		}
		if(presence==0){
			printf("노드에 입력한 이름 [%s]가 없습니다.\n",itemName);
		}
	}

	void  SearchPriceRange( int minPrice, int maxPrice  ){
		//노드의 가격범위에 따라 출력하는 함수를 출력해준다.
		m_root->SearchPriceRange(minPrice, maxPrice);
	}

	int GetHeight(){    
		//루트가 빈값이 아닐경우에 노드의 GetHeight()의 함수를 반환.
      if (m_root != NULL)
         return m_root->GetHeight();
	  else
		  return 0;
	}
	int GetCount(){
		//노드의 getCount() 함수를 반환해준다.
		return m_root->GetCount();
	}
};

