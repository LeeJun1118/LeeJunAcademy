#pragma once

typedef struct tagObject
{
	char* pName;

	int iAtt;
	int iDef;

	int iHP;
	int iMP;

	tagObject() {};

	tagObject(int _iAtt, int _iDef, int _iHP, int _iMP)
		: iAtt(_iAtt), iDef(_iDef), iHP(_iHP), iMP(_iMP) {};

}Object;
