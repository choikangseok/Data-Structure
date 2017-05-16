#include "CksBracketChecker.h"

void main()
{
	CksBracketChecker2 checker2;
	checker2.Check("CksElement.h");
	checker2.Check("CksBracketChecker.h");
	checker2.Check("CksBracketChecker.cpp");

	getchar();
	getchar();
}