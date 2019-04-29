#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct tagStatus
{
	int iValue;
	char cpString[128];
};


/************************************
	** [전처리 지시문]

		* #include
		* #define
		* #if, #else, #endif

*************************************/

/*
#define WHILE(cond) \
	{\
		int i = 0;\
	WHILE:\
		i++;\
		printf_s("goto 문을 사용하여 이렇게 반복 할 수 있습니다.\n");\
\
		if (i < cond)\
			goto WHILE;\
		else\
			goto EXIT;\
	EXIT:\
		printf_s("종료 되었습니다.\n");\
	}
*/

#define DEBUG 0

#define SUM(x1, x2) printf_s("%d\n",(x1+x2));
#define STRING(str) printf_s("%s\n",str);


#define failed 0

#define ERR_MESSAGE(cond)\
	if( !(cond) )\
	{\
		printf( "assertion error line %d, file(%s)\n",__LINE__, __FILE__ );\
	}

int main(void)
{
	//WHILE(10);

	/*
	SUM(10, 20);
	STRING("Hello World!!");
	system("pause");
	*/

	//ERR_MESSAGE(failed);
	
	/*
#if defined(DEBUG)
	printf_s("윗줄이 1 번 출력 됨.\n");
#else
	printf_s("아래줄이 출력 됨.\n");
#endif


//#undef DEBUG	// 현재 구문이 있다면 더이상 전처리기를 사용 할 수 없다.


#if DEBUG
	printf_s("윗줄이 출력 됨.\n");
#else
	printf_s("아래줄이 출력 됨.\n");
#endif

//#undef DEBUG	// 현재 구문이 있다면 더이상 전처리기를 사용 할 수 없다.

#ifdef DEBUG
	printf_s("윗줄이 출력 됨.\n");
#else
	printf_s("아래줄이 출력 됨.\n");
#endif

	//#undef DEBUG	// 현재 구문이 있다면 더이상 전처리기를 사용 할 수 없다.

#ifndef DEBUG
	printf_s("윗줄이 출력 됨.\n");
#else
	printf_s("아래줄이 출력 됨.\n");
#endif
	*/








	/**********************************
		** [do~while]

		* 무조건 1회 실행되고, 조건을 확인하여
			반복실행할지 결정.

	************************************/


	//** 예제 1
	/*
	int i = 0;

	do 
	{
		printf_s("%02d\n", i++);
	} while (i < 10);
	*/
	
	


	//** 예제 2
	/*
	do
	{
		printf_s("일단 한번 실행 됩니다.");
	} while (false);
	*/
	







	/*****************
		** [goto]
	*******************/

	//** 예제 1
	/*
	int i = 0;
WHILE:
	i++;

	printf_s("goto 문을 사용하여 이렇게 반복 할 수 있습니다.\n");

	if (i < 10)
		goto WHILE;
	else
		goto EXIT;
EXIT:
	printf_s("종료 되었습니다.\n");*/
	









	/******************************
		** [삼항 연산자]

		* (조건) ? true : false

	*******************************/





	
	//** 예제 01
	/*
	int iTemp = 10;
	int iDest = 20;

	printf_s("%s 값이 더 큽니다.",(iTemp < iDest) ? "iTemp" : "iDest");
	*/
	





	//** 예제 02
	/*
	int iTemp = 10;
	int iDest = 20;

	
	//** 해당 조건이 맞다면 true 를 반환하므로 if 문이 실행됨.
	if ((iTemp > iDest) ? true : false)
		printf_s("iTemp 값이 더 크므로 해당 조건은 true 입니다.\n");
	else
		printf_s("iTemp 값이 더 작으므로 해당 조건은 false 입니다.\n");
	*/














	/**************************
		** [쉬프트 연산자]
	***************************/



	//** 예제 1

	/*
	int iNumber = 1;
	
	printf_s("iNumber_01 << 1 : %d\n", iNumber << 1);
	printf_s("iNumber_01 << 2 : %d\n", iNumber << 2);
	printf_s("iNumber_02 << 1 : %d\n", iNumber << 3);
	printf_s("iNumber_02 << 2 : %d\n", iNumber << 4);
	printf_s("\n");

	iNumber <<= 5;
	printf_s("iNumber_01 <<= 3 :%d\n", iNumber);
	*/




















	/********************************************************************
			** [예제] FizzBuzz

			1 ~ 50 까지 출력하면서 3의 배수는 Fizz, 5의 배수는 Buzz 를
			그리고 3과 5의 공배수는 FizzBuzz 출력하는 프로그램을 작성 하시오.

	********************************************************************/


	/*
	for (int i = 1; i < 51; i++)
	{
		printf_s("%d ", i);

		if ((i % 3) == 0)
			printf_s("Fizz");

		if ((i % 5) == 0)
			printf_s("Buzz");

		printf_s("\n");
	}
	*/










	//** [File Save]
	
	/*
	FILE *pFile = fopen("../Data/Status.txt", "w");

	fprintf(pFile, "공격력 %d\n", 150);
	fprintf(pFile, "방어력 %d\n", 80);
	fprintf(pFile, "H.P %d\n", 120);
	fprintf(pFile, "M.P %d\n", 30);

	fclose(pFile);
	*/
	



	//** [File Load]

	/*
	tagStatus tUser[4];

	FILE *pFile = fopen("../Data/Status.txt", "r");

	fscanf(pFile, "%s %d", &tUser[0].cpString, &tUser[0].iValue);
	fscanf(pFile, "%s %d", &tUser[1].cpString, &tUser[1].iValue);
	fscanf(pFile, "%s %d", &tUser[2].cpString, &tUser[2].iValue);
	fscanf(pFile, "%s %d", &tUser[3].cpString, &tUser[3].iValue);
	fclose(pFile);

	//** 출력
	for (int i = 0; i < 4; i++)
	{
		printf_s("%s : %d\n", tUser[i].cpString, tUser[i].iValue);
	}
	*/


	system("pause");

	return 0;
}