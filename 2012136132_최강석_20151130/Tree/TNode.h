#pragma once
#include"Item.h"
static int CountNode=0;
bool presence=0;
class TNode  : public Item
{
protected:
	TNode* m_left;//������ ��Ÿ�� ���
	TNode* m_right;//�������� ��Ÿ�� ���

public:
	
	  
	TNode(int priority=0, char* name="", int price=0, char*msg="..."): 
	  Item(priority, name, price, msg),m_left(NULL), m_right(NULL) {
	  CountNode++;}
	~TNode(void){ 
		if(m_left!=NULL)	delete m_left;
		if(m_right!=NULL)	delete m_right;
	}
	void PreOrder(){
		//��¼��� �ڱ��ڽ�->����->�����ʼ�
		Print();
		if(m_left!=NULL) m_left->PreOrder();
		if(m_right!=NULL) m_right->PreOrder();
	}
	void InOrder(){
		//��¼��� ���ʳ��->�ڱ��ڽ�->�����ʼ�
		if(m_left!=NULL) m_left->InOrder();
		Print();
		if(m_right!=NULL) m_right->InOrder();
	}
	void PostOrder(){
		//��¼��� ���ʳ��->������->�ڱ��ڽ�
		if(m_left!=NULL) m_left->PostOrder();
		if(m_right!=NULL) m_right->PostOrder();
		Print();
	}
	void Add( TNode *n){
		//strcmp�̿�
		//if(n->m_data < m_data)
		if(strcmp(n->m_name, m_name) < 0)
		{
			//�߰��Ϸ��� ����� �̸� ������ �켱������ �켱�ΰ��
			//���ʼ��� ��忡 �־��ݴϴ�.
			if(m_left==NULL) m_left = n;
			else m_left->Add(n);
		}
		else
		{
			//�߰��Ϸ��� ����� �̸� ������ �켱������ ���ų� �������
			//�����ʼ��� ��忡 �־��ݴϴ�.
			if(m_right==NULL) m_right = n;
			else m_right->Add(n);
		}
	}
	void FindItem2(char* itemName){
		//�ݺ����� Ž�� �Լ�.

		TNode *p = this;
		//������ġ(m_root)�������� ����

		while(p!=NULL){

			//�̸��� �켱������ ���Ͽ�
			//���ų� �������� p�� p�� ������ ��带 ����
			//�켱������ �������� p�� p�� ���� ��� �������ݴϴ�.
			if(strcmp(p->m_name,itemName)==0){
				p->Print();
				presence=1;//Ž������ ������
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

			//�̸��� �켱������ ���Ͽ�
			//���ų� �������� �����ʳ���� ��ġ���� ����Լ�ȣ��
			//�켱������ �������� ���ʳ���� ��ġ���� ����Լ� ȣ��
		if(strcmp(m_name,itemName)==0){
			Print();
			presence=1;//Ž������ ������.
			if(m_right!=NULL){
				m_right->FindItem(itemName);
				//�����ʳ���� ����Լ�ȣ��
			}
		}

		else if(strcmp(itemName, m_name)<0){
			if(m_left!=NULL){
				m_left->FindItem(itemName);
				//���ʳ���� ����Լ�ȣ��
			}
		}

		else{
			if(m_right!=NULL){
				m_right->FindItem(itemName);
				//�����ʳ���� ����Լ�ȣ��
			}
		}
		return;
	}
	void  SearchPriceRange( int minPrice, int maxPrice ){
		//���� �������ִ� ������ ������ش�.

		if((m_price>=minPrice) && (m_price<=maxPrice))
			Print();//���� ������������ �ش�Ǵ� ����� ������ ���.
		if(m_left!=NULL) m_left->SearchPriceRange(minPrice, maxPrice);
		if(m_right!=NULL) m_right->SearchPriceRange(minPrice, maxPrice);
	}
	int GetHeight(){//����� ���̸� ���ϴ� �Լ�.
		int l_height = 0, r_height = 0;

		if(m_left != NULL)
			l_height = m_left->GetHeight();
		if(m_right != NULL)
			r_height = m_right->GetHeight();

		if(l_height > r_height)
			//���ʿ���,�����ʿ����� �񱳸��Ͽ� ū ���� ��ȯ�� �ϰ� ���ش�.
			return 1 + l_height;
		else
			return 1 + r_height;
	}	int GetCount(){
		//��������ȣ��� CountNode++�� ȣ���ϰ� �ǹǷ�
		//CountNode�� ��ȯ���ָ� �ȴ�.
		return CountNode;
	}
};

