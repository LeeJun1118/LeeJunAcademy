#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct tagStatus
{
	int iValue;
	char cpString[128];
};

// # 들어간건 전처리 지시문
/*
	
	[전처리 지시문]

	매크로성 키워드들 
	#include
	#define DEBUG(변수명)     상수  
	#if, #else ,#endif
	
	정적으로 분류가 된다.
	#if , #ifdef , #else  ,#endif
	정의가 되어있으면 실행된다

	


*/


	// \ : 바로 밑에 줄이랑 이어준다 



//세미콜론이 이미 찍혀 있는 거라고 본다

//#define WHTITLE(cond) \
//	{ \
//		int i = 0;\
//		WHILE:\
//		i++;\
//		printf_s("goto문은 사용하여 이렇게 반복 할 수 있습니다. \n");\
//		if (i < cond)\
//			goto WHILE;\
//		else\
//			goto EXIT;\
//EXIT:\
//		printf_s("종료 되었습니다. \n");\
//	}
//
//
//#define DEBUG 0
//
//#define SUM(x1,x2) printf_s("%d \n",(x1+x2));
//#define STRING(str) printf_s("%s \n",str);
//
//
//#define failed 0
//
//#define ERR_MESSAGE(cond)\
//	if( !(cond) ) \
//		{\
//			printf("assertion error line %d, file (%s) \n", __line__, __file__);\
//		}

int main(void) {
	
	//const int iNumber = 10; 

	//WHTITLE(10);
	/*
	SUM(10, 20);
	STRING("hello world!! \n");
	system("pause");
	*/

	//
	//ERR_MESSAGE(failed);
	
	// 예제 1

	//일단 한번은 실행된다.
	//int i = 0;
	//do
	//{
	//	printf("%02d \n", i++);  //02d 자리를 두자리 수로 만들겟다
	//} while (i < 10);
	

	//예제 2
	/*do
	{
		printf_s("일단 한번 실행 됩니다.");
	} while (false);*/
	
	
	// [goto]

	// 예제 1

	/*int i = 0;
WHILE:
	i++;

	printf_s("goto문은 사용하여 이렇게 반복 할 수 있습니다. \n");

	if (i < 10)
		goto WHILE;
	else
		goto EXIT;

EXIT:
	printf_s("종료 되었습니다. \n");*/


	// [삼항 연산자]
		

	//컴퓨터한테는 이항연산자
	//printf_s("%d", 1220 + 3250 + 3470 + 4670);

	//예제  1
	
	/*int iTemp = 10;
	int iDest = 20;

	printf_s("%s값이 더 큽니다.\n", (iTemp < iDest) ? "iTemp" : "iDest");
	*/

	//예제 2

	//int itemp = 10;
	//int idest = 20;

	////해당 조건이 맞다면 true 를 반환하므로 if문이 실행됨
	//if ((itemp > idest) ? true : false)
	//	printf_s("itemp 값이 더 크므로 해당 조건은 true입니다. \n");
	//else
	//	printf_s("idest 값이 더 크므로 해당 조건은 false입니다. \n");

	// [Shift Operator]

	// example 1

	/*
	int iNumber = 1;

	printf_s("iNumber_01 << 1 : %d \n", iNumber << 1);
	printf_s("iNumber_01 << 2 : %d \n", iNumber << 2);
	printf_s("iNumber_02 << 1 : %d \n", iNumber << 3);
	printf_s("iNumber_02 << 2 : %d \n", iNumber << 4);
	printf_s("\n");

	iNumber <<= 5;
	printf_s("iNumber_01 << 3 : %d \n", iNumber);
	*/
	
	//FizzBuzz
	/*for (int i = 0; i < 50; i++)
	{
		printf_s("%d ", i);

		if (i % 3 == 0)
			printf_s("Fizz: %d \n", i);

		if (i % 5 == 0)
			printf_s("Buzz : %d \n", i);
		
		printf_s("\n");

	}*/

	// [File Save]
	//Data라는 폴더는 미리 만들어 놓아야한다.
	//Status라는 파일은 여기서 만드는거다
	tagStatus tUser[4];

	FILE* pFile = fopen("../Data/Status.txt","w");


	fprintf(pFile, "공격력 %d \n", 1000);
	fprintf(pFile, "방어력 %d \n", 30);
	fprintf(pFile, "H.P %d \n", 100);
	fprintf(pFile, "M.P %d \n", 20);

	fclose(pFile);

	//[File Load]
	//FILE* pFile = fopen("../Data/Status.txt", "r");
	pFile = fopen("../Data/Status.txt", "r");

	fscanf(pFile, "%s %d", &tUser[0].cpString, &tUser[0].iValue);
	fscanf(pFile, "%s %d", &tUser[1].cpString, &tUser[1].iValue);
	fscanf(pFile, "%s %d", &tUser[2].cpString, &tUser[2].iValue);
	fscanf(pFile, "%s %d", &tUser[3].cpString, &tUser[3].iValue);

	fclose(pFile);

	for (int i = 0; i < 4; i++)
	{
		printf_s("%s : %d \n", tUser[i].cpString, tUser[i].iValue);
	}

	system("pause");
	return 0;
}