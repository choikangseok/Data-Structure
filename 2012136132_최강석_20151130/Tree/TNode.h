#pragma once
#include"Item.h"
static int CountNode=0;
bool presence=0;
class TNode  : public Item
{
protected:
	TNode* m_left;//왼쪽을 나타낼 노드
	TNode* m_right;//오른쪽을 나타낼 노드

public:
	
	  
	TNode(int priority=0, char* name="", int price=0, char*msg="..."): 
	  Item(priority, name, price, msg),m_left(NULL), m_right(NULL) {
	  CountNode++;}
	~TNode(void){ 
		if(m_left!=NULL)	delete m_left;
		if(m_right!=NULL)	delete m_right;
	}
	void PreOrder(){
		//출력순이 자기자신->왼쪽->오른쪽순
		Print();
		if(m_left!=NULL) m_left->PreOrder();
		if(m_right!=NULL) m_right->PreOrder();
	}
	void InOrder(){
		//출력순이 왼쪽노드->자기자신->오른쪽순
		if(m_left!=NULL) m_left->InOrder();
		Print();
		if(m_right!=NULL) m_right->InOrder();
	}
	void PostOrder(){
		//출력순이 왼쪽노드->오른쪽->자기자신
		if(m_left!=NULL) m_left->PostOrder();
		if(m_right!=NULL) m_right->PostOrder();
		Print();
	}
	void Add( TNode *n){
		//strcmp이용
		//if(n->m_data < m_data)
		if(strcmp(n->m_name, m_name) < 0)
		{
			//추가하려는 노드의 이름 성분이 우선순위가 우선인경우
			//왼쪽성분 노드에 넣어줍니다.
			if(m_left==NULL) m_left = n;
			else m_left->Add(n);
		}
		else
		{
			//추가하려는 노드의 이름 성분의 우선순위가 같거나 낮은경우
			//오른쪽성분 노드에 넣어줍니다.
			if(m_right==NULL) m_right = n;
			else m_right->Add(n);
		}
	}
	void FindItem2(char* itemName){
		//반복적인 탐색 함수.

		TNode *p = this;
		//현재위치(m_root)에서부터 시작

		while(p!=NULL){

			//이름의 우선순위를 비교하여
			//같거나 낮을경우는 p에 p의 오른쪽 노드를 대입
			//우선순위가 높을경우는 p에 p의 왼쪽 노들 대입해줍니다.
			if(strcmp(p->m_name,itemName)==0){
				p->Print();
				presence=1;//탐색값이 존재함
				p=p->m_right;

			}else if(strcmp(itemName, p->m_name)<0){
				p=p->m_left;
			}else{
				p=p->m_right;
			}
		}
		return;
	}
	void FindItem( char* itemName ){

			//이름의 우선순위를 비교하여
			//같거나 낮을경우는 오른쪽노드의 위치에서 재귀함수호출
			//우선순위가 높을경우는 왼쪽노드의 위치에서 재귀함수 호출
		if(strcmp(m_name,itemName)==0){
			Print();
			presence=1;//탐색값이 존재함.
			if(m_right!=NULL){
				m_right->FindItem(itemName);
				//오른쪽노드의 재귀함수호출
			}
		}

		else if(strcmp(itemName, m_name)<0){
			if(m_left!=NULL){
				m_left->FindItem(itemName);
				//왼쪽노드의 재귀함수호출
			}
		}

		else{
			if(m_right!=NULL){
				m_right->FindItem(itemName);
				//오른쪽노드의 재귀함수호출
			}
		}
		return;
	}
	void  SearchPriceRange( int minPrice, int maxPrice ){
		//가격 범위에있는 노드들을 출력해준다.

		if((m_price>=minPrice) && (m_price<=maxPrice))
			Print();//가격 범위에있으면 해당되는 노드의 성분을 출력.
		if(m_left!=NULL) m_left->SearchPriceRange(minPrice, maxPrice);
		if(m_right!=NULL) m_right->SearchPriceRange(minPrice, maxPrice);
	}
	int GetHeight(){//노드의 높이를 구하는 함수.
		int l_height = 0, r_height = 0;

		if(m_left != NULL)
			l_height = m_left->GetHeight();
		if(m_right != NULL)
			r_height = m_right->GetHeight();

		if(l_height > r_height)
			//왼쪽연결,오른쪽연결을 비교를하여 큰 값을 반환을 하게 해준다.
			return 1 + l_height;
		else
			return 1 + r_height;
	}	int GetCount(){
		//노드생성자호출시 CountNode++가 호출하게 되므로
		//CountNode를 반환해주면 된다.
		return CountNode;
	}
};

