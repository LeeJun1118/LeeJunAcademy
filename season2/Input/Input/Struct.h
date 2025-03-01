#pragma once


typedef struct tagVector3
{
	float x, y, z;

	tagVector3() {};

	tagVector3(float _x, float _y) : x(_x), y(_y), z(0) {};

	tagVector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) {};

}Vector3;


typedef struct tagTransform
{
	Vector3 Position;
	Vector3 Scale;

}Transform;


typedef struct tagObject
{
	char* pName;

	Transform TransPos;

	int iAtt;
	int iDef;

	int iHP;
	int iMP;

	tagObject() {};

	tagObject(int _iAtt, int _iDef, int _iHP, int _iMP)
		: iAtt(_iAtt), iDef(_iDef), iHP(_iHP), iMP(_iMP) {};

}Object;
