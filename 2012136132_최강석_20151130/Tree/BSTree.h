#pragma once
#include "TNode.h"
class BSTree
{
protected:
	TNode* m_root;//����Ʈ���� ù��° ���
public:
	BSTree(void){ m_root = NULL;}
	~BSTree(void){if(m_root!=NULL) m_root;}

	void PrintPreOrder(){
		//PreOrdre������ Ʈ�� ���.
		printf("[Ʈ���������-PreOrder] \n");
		if(m_root!=NULL)	m_root->PreOrder();
		printf("\n");
	}
	void PrintInOrder(){
		//InOrder������ Ʈ�� ���
		printf("[Ʈ���������-InOrder] \n");
		if(m_root!=NULL)	m_root->InOrder();
		printf("\n");
	}
	void PrintPostOrder(){
		//Postorder������ Ʈ�� ���
		printf("[Ʈ���������-PostOrder]\n");
		if(m_root!=NULL)	m_root->PostOrder();
		printf("\n");
	}
	void Add(TNode* n){
	//��� n�� �����ش�.  
		if(n == NULL) return ;
		if(m_root == NULL) {
			m_root = n;
		}else{
			m_root->Add(n);
			//root�� null�� �ƴҰ�� TNode�� Add�Լ��� ȣ�����ش�.
		}
	}

	void FindItem2(char* itemName){
		presence=0;//Ž���� ������ ��� 1���� �����̵ȴ�..
		printf("[�ݺ�]  ");
		if(itemName == NULL){
			printf("��忡 �Է��� �̸� [%s]�� �����ϴ�.\n",itemName);
			return;
		}else{
			m_root->FindItem2(itemName);
			//����� �ݺ�Ž�� �Լ��� �ҷ��ش�.
		}
		if(presence==0){
			printf("��忡 �Է��� �̸� [%s]�� �����ϴ�.\n",itemName);
		}
	}

	void FindItem(char* itemName){
		presence=0;//Ž���� ������ ��� 1���� �����̵ȴ�.
		printf("[���]  ");
		if(itemName == NULL) return;
		if(m_root == NULL){
			printf("��忡 �Է��� �̸� [%s]�� �����ϴ�.\n",itemName);
			return;
		}
		else{
			m_root->FindItem(itemName);
			//����� ��ȯŽ�� �Լ��� �ҷ��ش�.
		}
		if(presence==0){
			printf("��忡 �Է��� �̸� [%s]�� �����ϴ�.\n",itemName);
		}
	}

	void  SearchPriceRange( int minPrice, int maxPrice  ){
		//����� ���ݹ����� ���� ����ϴ� �Լ��� ������ش�.
		m_root->SearchPriceRange(minPrice, maxPrice);
	}

	int GetHeight(){    
		//��Ʈ�� ���� �ƴҰ�쿡 ����� GetHeight()�� �Լ��� ��ȯ.
      if (m_root != NULL)
         return m_root->GetHeight();
	  else
		  return 0;
	}
	int GetCount(){
		//����� getCount() �Լ��� ��ȯ���ش�.
		return m_root->GetCount();
	}
};

