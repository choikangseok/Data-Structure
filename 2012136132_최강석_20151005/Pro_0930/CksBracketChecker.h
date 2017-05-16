#pragma once
#include "CksStack.h"
#include "cstring"
class CksBracketChecker{
	CksStack m_st;
	int m_nLine;//���μ�
	int m_nChar;//���ڼ�
	char m_filename[200];//�����̸� ���ڹ迭
public:
	CksBracketChecker(void){}
	~CksBracketChecker(){}
	//�����ڿ� �Ҹ���

	bool Check( char* filename ) {
		strcpy( m_filename, filename );
		//Ŭ���� �����̸��� �Ű������ι��� ���ڿ��� �־��ش�.
		FILE *fp = fopen( m_filename, "r" );
		//������ �Ű������ι��� ���ڿ��� ���� �����̸��� r���
		//�� �����ش�.

		printf("%s ���� �˻� ���: \n", filename);

		if( fp == NULL ) {
			printf("Error: ���� �������� �ʽ��ϴ�.\n");
			return 0;
		}
		m_nLine = 1; // line ��ȣ�� 1������ ����
		m_nChar = 0; // ���� ���� ������ 0���� �ʱ�ȭ
		m_st.Reset();// ���ο� ������ üũ�ϱ� ���� ���� ��ü �ʱ�ȭ
		char ch;
		while ( (ch = getc(fp)) != EOF ) {
			//���ڿ��� ���� �о���϶����� �ݺ�
			if( ch == '\n' ) 
				m_nLine++;
			//������ �Ǹ� ���μ��� ���������ش�.
			m_nChar++;
			//�����ϳ��ϳ� �о���� ������ ���ڼ��� ���������ش�.

			if( ch == '[' || ch == '(' || ch == '{' ){
				m_st.Push(ch);
			}
			//���࿡ ���� ��ȣ�� �����ԵǸ� �ش��ϴ� ��ȣ�� ������ ���ش�.
			else if( ch == ']' || ch == ')' || ch == '}' ) {
				//���࿡ �����ʰ�ȣ�� �����ԵǸ� ������ �׾Ҵ� ��ȣ��
				//�񱳸� ���־� ¦�� �̷������ ������ ��ȣ �ݱ� ������
				//�ִٴ� ������ �˷��ش�.
				char prev = m_st.Pop();//--m_top�� ���ְԵȴ�.
				if((   ch == ']' && prev != '[' )
					|| ( ch == ')' && prev != '(')
					|| (  ch == '}'  && prev != '{' ))
				{
					break;
				}
			}
		}
		//���ÿ��� �������� ¦�� �̷������ ���������� ���� 
		//������ ��µȴ�
		//break; ......
		fclose(fp);
		printResult();
		return m_st.IsEmpty();

		//break; ......


	}
	void printResult(){
		//��ȣ�ݱ��� �������� ���.
		if (m_st.IsEmpty()){
			printf("OK: ��ȣ�ݱ� ����\n");
			printf("������ ������ ����: %d\n", m_nLine);
			printf("������ ���� ���� : %d\n\n", m_nChar);

		}else{
			printf("Error(Line %d) : ��ȣ �ݱ� ���� �߰�\n\n", m_nLine);
		}
	}

};


class CksBracketChecker2{
	CksStack m_st;
	int m_nLine;//���μ�
	int m_nChar;//���ڼ�
	char m_filename[200];//�����̸� ���ڹ迭
public:
	CksBracketChecker2(void){}
	~CksBracketChecker2(){}
	//�����ڿ� �Ҹ���

	bool Check( char* filename ) {
		strcpy( m_filename, filename );
		//Ŭ���� �����̸��� �Ű������ι��� ���ڿ��� �־��ش�.
		FILE *fp = fopen( m_filename, "r" );
		//������ �Ű������ι��� ���ڿ��� ���� �����̸��� r���
		//�� �����ش�.

		printf("%s ���� �˻� ���: \n", filename);

		if( fp == NULL ) {
			printf("Error: ���� �������� �ʽ��ϴ�.\n");
			return 0;
		}
		m_nLine = 1; // line ��ȣ�� 1������ ����
		m_nChar = 0; // ���� ���� ������ 0���� �ʱ�ȭ
		m_st.Reset();// ���ο� ������ üũ�ϱ� ���� ���� ��ü �ʱ�ȭ
		char ch, ch2;
		while ( (ch = getc(fp)) != EOF ) {
			//���ڿ��� ���� �о���϶����� �ݺ�
			if( ch == '\n' ) 
				m_nLine++;
			//������ �Ǹ� ���μ��� ���������ش�.
			m_nChar++;
			//�����ϳ��ϳ� �о���� ������ ���ڼ��� ���������ش�.


			//'����'�ΰ��
			if( ch == 39 ){
				// ' <-�� �ƽ�Ű�ڵ尪�� 39�̹Ƿ�  ' <-�� ���ð�츦 �ǹ���
				while( (ch = getc(fp)) != 39){
					m_nChar++;
					//���� ���ڿ��� '<-�� ������ ���ڿ��� �о��ְ�
					//������ ������ ���μ��� ���������ְ�
					//�����ϳ��ϳ� �о���� ������ ���ڼ��� ���������ش�.
					if( ch == '\n' ) {
						m_nLine++;
					}
				}
				m_nChar++;
			}
			if( ch == 34 ){
				// " <-�� �ƽ�Ű�ڵ尪�� 34�̹Ƿ�  " <-�� ���ð�츦 �ǹ���
				while( (ch = getc(fp)) != 34){
					m_nChar++;
					//���� ���ڿ��� '<-�� ������ ���ڿ��� �о��ְ�
					//������ ������ ���μ��� ���������ְ�
					//�����ϳ��ϳ� �о���� ������ ���ڼ��� ���������ش�.
					if( ch == '\n' ) {
						m_nLine++;
					}
				}
				m_nChar++;
			}
			//�ּ��� ���
			if(ch == '/')// ���ڰ� '/'�϶�
			{
				ch = getc(fp);//�� ���� ���ڸ� �Է¹ް�
				//�����ּ� ����ó��
				if(ch == '/'){ //�� ������ �ԷµǴ� ���ڵ� '/'���
					m_nChar++;// ���ڼ� ����
					while((ch = getc(fp)) != EOF){//������ ���������� �ݺ�
						if( ch == '\n'){ //���ڰ� �ٹٲ��� ���
							m_nChar++; // ���ڼ� ����
							m_nLine++;// ���μ� ����
							break; // �ݺ��� Ż��
						}
						else //�� ���� ���
							m_nChar++; // ���ڼ� ����
					}
				}
				else if(ch == '*'){ //�����ּ� ����ó��
					m_nChar++; //���ڼ� ����
					while((ch = getc(fp)) != EOF){ //������ ���������� �ݺ�
						if(ch == '*'){ //���ڰ� *�϶�
							ch = getc(fp); //�ѱ��ڸ� �� �޾Ƽ�

							if(ch == '/'){ //���ڰ� /���
								m_nChar += 2; //���ڼ��� �� �������ϰ�
								break; //�ݺ��� Ż��
							}
						}                  
						else if(ch == '\n'){ //���ڰ� �ٹٲ��̶��
							m_nChar++; //���ڼ� ����
							m_nLine++; //���μ� ����
						}
						else//�� ���� ���
							m_nChar++; //���ڼ� ����
					}
				}
			}

			if( ch == '[' || ch == '(' || ch == '{' ){
				m_st.Push(ch);
			}
			//���࿡ ���� ��ȣ�� �����ԵǸ� �ش��ϴ� ��ȣ�� ������ ���ش�.
			else if( ch == ']' || ch == ')' || ch == '}' ) {
				//���࿡ �����ʰ�ȣ�� �����ԵǸ� ������ �׾Ҵ� ��ȣ��
				//�񱳸� ���־� ¦�� �̷������ ������ ��ȣ �ݱ� ������
				//�ִٴ� ������ �˷��ش�.
				char prev = m_st.Pop();//--m_top�� ���ְԵȴ�.
				if((   ch == ']' && prev != '[' )
					|| ( ch == ')' && prev != '(')
					|| (  ch == '}'  && prev != '{' ))
				{
					break;
				}
			}
		}
		//���ÿ��� �������� ¦�� �̷������ ���������� ���� 
		//������ ��µȴ�
		//break; ......
		fclose(fp);
		printResult();
		return m_st.IsEmpty();

		//break; ......


	}
	void printResult(){
		//��ȣ�ݱ��� �������� ���.
		if (m_st.IsEmpty()){
			printf("OK: ��ȣ�ݱ� ����\n");
			printf("������ ������ ����: %d\n", m_nLine);
			printf("������ ���� ���� : %d\n\n", m_nChar);

		}else{
			printf("Error(Line %d) : ��ȣ �ݱ� ���� �߰�\n\n", m_nLine);
		}
	}
};