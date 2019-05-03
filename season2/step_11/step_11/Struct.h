#pragma once

typedef struct tagStudent
{
	char* pName;
	int iKor;
	int iEng;
	int iMath;

	//** 생성됨과 동시에 호출 됨.
	tagStudent() //** 생성자.
	{
		iKor = 0;
		iEng = 0;
		iMath = 0;
		printf_s("생성 되었습니다.\n");
	};

	//** 사용자가 호출 할 때 호출 됨.
	tagStudent(int _iKor, int _iEng, int _iMath)
	{	//** 복사 생성자
		iKor = _iKor;
		iEng = _iEng;
		iMath = _iMath;
		printf_s("복사 생성되었습니다.\n");
	};

}Student;
