#pragma once
#include "CksStack.h"
#include "cstring"
class CksBracketChecker{
	CksStack m_st;
	int m_nLine;//라인수
	int m_nChar;//문자수
	char m_filename[200];//파일이름 문자배열
public:
	CksBracketChecker(void){}
	~CksBracketChecker(){}
	//생성자와 소멸자

	bool Check( char* filename ) {
		strcpy( m_filename, filename );
		//클래스 파일이름에 매개변수로받은 문자열을 넣어준다.
		FILE *fp = fopen( m_filename, "r" );
		//파일을 매개변수로받은 문자열과 같은 파일이름을 r모드
		//로 열어준다.

		printf("%s 파일 검사 결과: \n", filename);

		if( fp == NULL ) {
			printf("Error: 파일 존재하지 않습니다.\n");
			return 0;
		}
		m_nLine = 1; // line 번호를 1번부터 시작
		m_nChar = 0; // 읽은 문자 개수는 0으로 초기화
		m_st.Reset();// 새로운 파일을 체크하기 위해 스택 객체 초기화
		char ch;
		while ( (ch = getc(fp)) != EOF ) {
			//문자열의 끝을 읽어들일때까지 반복
			if( ch == '\n' ) 
				m_nLine++;
			//개행이 되면 라인수를 증가시켜준다.
			m_nChar++;
			//문자하나하나 읽어들일 때마다 문자수를 증가시켜준다.

			if( ch == '[' || ch == '(' || ch == '{' ){
				m_st.Push(ch);
			}
			//만약에 왼쪽 괄호를 만나게되면 해당하는 괄호를 스택을 해준다.
			else if( ch == ']' || ch == ')' || ch == '}' ) {
				//만약에 오른쪽괄호를 만나게되면 이전에 쌓았던 괄호와
				//비교를 해주어 짝이 이루어지지 않으면 괄호 닫기 문제가
				//있다는 정보를 알려준다.
				char prev = m_st.Pop();//--m_top을 해주게된다.
				if((   ch == ']' && prev != '[' )
					|| ( ch == ')' && prev != '(')
					|| (  ch == '}'  && prev != '{' ))
				{
					break;
				}
			}
		}
		//스택에서 정상적인 짝이 이루어지면 정상적으로 밑의 
		//정보가 출력된다
		//break; ......
		fclose(fp);
		printResult();
		return m_st.IsEmpty();

		//break; ......


	}
	void printResult(){
		//괄호닫기의 문제유무 출력.
		if (m_st.IsEmpty()){
			printf("OK: 괄호닫기 정상\n");
			printf("파일의 라인의 개수: %d\n", m_nLine);
			printf("파일의 문자 개수 : %d\n\n", m_nChar);

		}else{
			printf("Error(Line %d) : 괄호 닫기 문제 발견\n\n", m_nLine);
		}
	}

};


class CksBracketChecker2{
	CksStack m_st;
	int m_nLine;//라인수
	int m_nChar;//문자수
	char m_filename[200];//파일이름 문자배열
public:
	CksBracketChecker2(void){}
	~CksBracketChecker2(){}
	//생성자와 소멸자

	bool Check( char* filename ) {
		strcpy( m_filename, filename );
		//클래스 파일이름에 매개변수로받은 문자열을 넣어준다.
		FILE *fp = fopen( m_filename, "r" );
		//파일을 매개변수로받은 문자열과 같은 파일이름을 r모드
		//로 열어준다.

		printf("%s 파일 검사 결과: \n", filename);

		if( fp == NULL ) {
			printf("Error: 파일 존재하지 않습니다.\n");
			return 0;
		}
		m_nLine = 1; // line 번호를 1번부터 시작
		m_nChar = 0; // 읽은 문자 개수는 0으로 초기화
		m_st.Reset();// 새로운 파일을 체크하기 위해 스택 객체 초기화
		char ch, ch2;
		while ( (ch = getc(fp)) != EOF ) {
			//문자열의 끝을 읽어들일때까지 반복
			if( ch == '\n' ) 
				m_nLine++;
			//개행이 되면 라인수를 증가시켜준다.
			m_nChar++;
			//문자하나하나 읽어들일 때마다 문자수를 증가시켜준다.


			//'문자'인경우
			if( ch == 39 ){
				// ' <-의 아스키코드값은 39이므로  ' <-가 나올경우를 의미함
				while( (ch = getc(fp)) != 39){
					m_nChar++;
					//다음 문자열이 '<-일 때까지 문자열을 읽어주고
					//개행을 만나면 라인수를 증가시켜주고
					//문자하나하나 읽어들일 때마다 문자수를 증가시켜준다.
					if( ch == '\n' ) {
						m_nLine++;
					}
				}
				m_nChar++;
			}
			if( ch == 34 ){
				// " <-의 아스키코드값은 34이므로  " <-가 나올경우를 의미함
				while( (ch = getc(fp)) != 34){
					m_nChar++;
					//다음 문자열이 '<-일 때까지 문자열을 읽어주고
					//개행을 만나면 라인수를 증가시켜주고
					//문자하나하나 읽어들일 때마다 문자수를 증가시켜준다.
					if( ch == '\n' ) {
						m_nLine++;
					}
				}
				m_nChar++;
			}
			//주석의 경우
			if(ch == '/')// 문자가 '/'일때
			{
				ch = getc(fp);//그 다음 글자를 입력받고
				//단일주석 예외처리
				if(ch == '/'){ //그 다음에 입력되는 글자도 '/'라면
					m_nChar++;// 글자수 증가
					while((ch = getc(fp)) != EOF){//파일이 끝날때까지 반복
						if( ch == '\n'){ //문자가 줄바꿈인 경우
							m_nChar++; // 글자수 증가
							m_nLine++;// 라인수 증가
							break; // 반복문 탈출
						}
						else //그 외의 경우
							m_nChar++; // 글자수 증가
					}
				}
				else if(ch == '*'){ //복수주석 예외처리
					m_nChar++; //글자수 증가
					while((ch = getc(fp)) != EOF){ //파일이 끝날때까지 반복
						if(ch == '*'){ //글자가 *일때
							ch = getc(fp); //한글자를 더 받아서

							if(ch == '/'){ //글자가 /라면
								m_nChar += 2; //글자수를 두 개증가하고
								break; //반복문 탈출
							}
						}                  
						else if(ch == '\n'){ //문자가 줄바꿈이라면
							m_nChar++; //글자수 증가
							m_nLine++; //라인수 증가
						}
						else//그 외의 경우
							m_nChar++; //글자수 증가
					}
				}
			}

			if( ch == '[' || ch == '(' || ch == '{' ){
				m_st.Push(ch);
			}
			//만약에 왼쪽 괄호를 만나게되면 해당하는 괄호를 스택을 해준다.
			else if( ch == ']' || ch == ')' || ch == '}' ) {
				//만약에 오른쪽괄호를 만나게되면 이전에 쌓았던 괄호와
				//비교를 해주어 짝이 이루어지지 않으면 괄호 닫기 문제가
				//있다는 정보를 알려준다.
				char prev = m_st.Pop();//--m_top을 해주게된다.
				if((   ch == ']' && prev != '[' )
					|| ( ch == ')' && prev != '(')
					|| (  ch == '}'  && prev != '{' ))
				{
					break;
				}
			}
		}
		//스택에서 정상적인 짝이 이루어지면 정상적으로 밑의 
		//정보가 출력된다
		//break; ......
		fclose(fp);
		printResult();
		return m_st.IsEmpty();

		//break; ......


	}
	void printResult(){
		//괄호닫기의 문제여부 출력.
		if (m_st.IsEmpty()){
			printf("OK: 괄호닫기 정상\n");
			printf("파일의 라인의 개수: %d\n", m_nLine);
			printf("파일의 문자 개수 : %d\n\n", m_nChar);

		}else{
			printf("Error(Line %d) : 괄호 닫기 문제 발견\n\n", m_nLine);
		}
	}
};