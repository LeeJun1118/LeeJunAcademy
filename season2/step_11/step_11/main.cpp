#include "Headers.h"


//** 함수 전방선언
char* SetName();
Student* CreateStudent();
void Initialize(Student* _pStudent);
void Render(Student* _pStudent);


int main(void)
{
	//** 동적 할당
	Student* ptStudent1 = (Student*)malloc(sizeof(Student));
	
	*ptStudent1 = tagStudent(10, 20, 30);
	printf_s("국어 점수 : %d\n", ptStudent1->iKor);
	printf_s("영어 점수 : %d\n", ptStudent1->iEng);
	printf_s("수학 점수 : %d\n", ptStudent1->iMath);

	/*printf_s("%d \n", tStudent.iKor);
	printf_s("%d \n", tStudent.iEng);
	printf_s("%d \n", tStudent.iMath);*/
	//Render(pStudent1);
	

	system("pause");
	return 0;
}



char* SetName()
{
	//** 문자열 입력
	char str[128] = "";

	printf_s("이름 입력 : ");
	scanf_s("%s", str, 128);


	//** 문자열 복사
	char* pName = (char*)malloc(strlen(str));
	strcpy(pName, str);

	return pName;
}


Student* CreateStudent()
{
	Student* pStudent = (Student*)malloc(sizeof(Student));
	Initialize(pStudent);

	return pStudent;
}


void Initialize(Student* _pStudent)
{
	//이름 입력
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