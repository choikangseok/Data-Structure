#include "CksBracketChecker.h"
void main()
{

	CksBracketChecker checker;
	checker.Check("CksStack.h");
	checker.Check("CksBracketChecker.h");
	checker.Check("Pro_0930_1_1.cpp");
	printf("----------------------------\n");
	
	
	/**/ /**/
	
	
	CksBracketChecker2 checker2;
	checker2.Check("CksStack.h");
	checker2.Check("CksBracketChecker.h");
	checker2.Check("Pro_0930_1_1.cpp");

	getchar();
	getchar();
}