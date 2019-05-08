#pragma once

typedef struct tagObject
{
	char* pName;

	int iAtt;
	int iDef;

	int iHp;
	int iMp;

	tagObject() {};

	tagObject(int _iAtt, int _iDef, int _iHp, int _iMp)
		: iAtt(_iAtt), iDef(_iDef), iHp(_iHp), iMp(_iMp) {};

}Object;
