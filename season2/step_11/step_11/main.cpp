#include "Headers.h"


//** 열거형 
//enum { AAA, BBB, CCC, DDD, EEE, FFF, GGG };

//** 상수, 정수
enum SCENEID 
{ 
	매뉴			,
	학생추가		, 
	학생삭제		, 
	학생정보변경	,
};

//** 전역변수
SCENEID eSCENEID = 매뉴;


//** 함수 전방선언
void SetScene();
char* SetName();
Student* CreateStudent();
void Initialize(Student* _pStudent);
void Render(Student* _pStudent);


int main(void)
{
	//배열에 넣어봐라
	//Student* ptStudent[3] = CreateStudent();

	//크기가 3인 포인터 배열을 선언했다.
	
	Student* ptStudent[3];
	
	SetScene();
	/*
	for (int i = 0; i < 3; i++)
	{
		ptStudent[i] = CreateStudent();
	}
	
	*/
	
	


	for (int i = 0; i < 3; i++)
	{
		Render(ptStudent[i]);
	}


	/*while (true)
	{
		system("cls");
		SetScene();
	}*/


	system("pause");

	return 0;
}

void SetScene()
{
	switch (eSCENEID)
	{
	case 매뉴:
	{
		printf_s("1. 학생 추가\n");
		printf_s("2. 학생 삭제\n");
		printf_s("3. 학생 정보 변경\n");

		int iChoice = 0;
		printf_s("입력 : ");
		scanf_s("%d", &iChoice);

		if (iChoice == 1) {
			eSCENEID = 학생추가;
			Student* ptStudent[3];
			for (int i = 0; i < 3; i++)
			{
				ptStudent[i] = CreateStudent();
			}

		}
		else if (iChoice == 2)
			eSCENEID = 학생삭제;
		else if (iChoice == 3)
			eSCENEID = 학생정보변경;
	}
		break;

	case 학생추가:
		system("cls");
		printf_s("학생 추가 매뉴 \n");
		eSCENEID = 매뉴;
		system("pause");
		break;

	case 학생삭제:
		system("cls");
		printf_s("학생 삭제 매뉴 \n");
		eSCENEID = 매뉴;
		system("pause");
		break;

	case 학생정보변경:
		system("cls");
		printf_s("학생 정보 변경 매뉴 \n");
		eSCENEID = 매뉴;
		system("pause");
		break;
	}
	
}


char* SetName()
{
	//** 문자열 입력
	char str[128] = "";

	printf_s("이름 입력 : ");
	scanf_s("%s", str, 128);

	//** 문자열 복사

	// strlen() = 문자열의 길이를 반환.
	char* pName = (char*)malloc(strlen(str));
	// strcpy() = 문자열 복사.
	strcpy(pName, str);

	return pName;
}



Student* CreateStudent()
{
	//** 포인터 변수 생성 및 동적할당.
	Student* pStudent = (Student*)malloc(sizeof(Student));
	
	
	Initialize(pStudent);



	return pStudent;
}

void Initialize(Student* _pStudent)
{
	_pStudent->pName = SetName();

	//** 각 점수 입력
	printf_s("국어 점수 입력 : ");
	scanf_s("%d", &_pStudent->iKor);

	printf_s("영어 점수 입력 : ");
	scanf_s("%d", &_pStudent->iEng);

	printf_s("수학 점수 입력 : ");
	scanf_s("%d", &_pStudent->iMath);
}

void Render(Student* _pStudent)
{
	//** 출력
	printf_s("\n\n** 점수 출력 **\n");
	printf_s("학생 이름 : %s\n", _pStudent->pName);
	printf_s("국어 점수 : %d\n", _pStudent->iKor);
	printf_s("영어 점수 : %d\n", _pStudent->iEng);
	printf_s("수학 점수 : %d\n", _pStudent->iMath);
}