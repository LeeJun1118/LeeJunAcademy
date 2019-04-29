#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct tagStatus
{
	int iValue;
	char cpString[128];
};


/************************************
	** [��ó�� ���ù�]

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
		printf_s("goto ���� ����Ͽ� �̷��� �ݺ� �� �� �ֽ��ϴ�.\n");\
\
		if (i < cond)\
			goto WHILE;\
		else\
			goto EXIT;\
	EXIT:\
		printf_s("���� �Ǿ����ϴ�.\n");\
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
	printf_s("������ 1 �� ��� ��.\n");
#else
	printf_s("�Ʒ����� ��� ��.\n");
#endif


//#undef DEBUG	// ���� ������ �ִٸ� ���̻� ��ó���⸦ ��� �� �� ����.


#if DEBUG
	printf_s("������ ��� ��.\n");
#else
	printf_s("�Ʒ����� ��� ��.\n");
#endif

//#undef DEBUG	// ���� ������ �ִٸ� ���̻� ��ó���⸦ ��� �� �� ����.

#ifdef DEBUG
	printf_s("������ ��� ��.\n");
#else
	printf_s("�Ʒ����� ��� ��.\n");
#endif

	//#undef DEBUG	// ���� ������ �ִٸ� ���̻� ��ó���⸦ ��� �� �� ����.

#ifndef DEBUG
	printf_s("������ ��� ��.\n");
#else
	printf_s("�Ʒ����� ��� ��.\n");
#endif
	*/








	/**********************************
		** [do~while]

		* ������ 1ȸ ����ǰ�, ������ Ȯ���Ͽ�
			�ݺ��������� ����.

	************************************/


	//** ���� 1
	/*
	int i = 0;

	do 
	{
		printf_s("%02d\n", i++);
	} while (i < 10);
	*/
	
	


	//** ���� 2
	/*
	do
	{
		printf_s("�ϴ� �ѹ� ���� �˴ϴ�.");
	} while (false);
	*/
	







	/*****************
		** [goto]
	*******************/

	//** ���� 1
	/*
	int i = 0;
WHILE:
	i++;

	printf_s("goto ���� ����Ͽ� �̷��� �ݺ� �� �� �ֽ��ϴ�.\n");

	if (i < 10)
		goto WHILE;
	else
		goto EXIT;
EXIT:
	printf_s("���� �Ǿ����ϴ�.\n");*/
	









	/******************************
		** [���� ������]

		* (����) ? true : false

	*******************************/





	
	//** ���� 01
	/*
	int iTemp = 10;
	int iDest = 20;

	printf_s("%s ���� �� Ů�ϴ�.",(iTemp < iDest) ? "iTemp" : "iDest");
	*/
	





	//** ���� 02
	/*
	int iTemp = 10;
	int iDest = 20;

	
	//** �ش� ������ �´ٸ� true �� ��ȯ�ϹǷ� if ���� �����.
	if ((iTemp > iDest) ? true : false)
		printf_s("iTemp ���� �� ũ�Ƿ� �ش� ������ true �Դϴ�.\n");
	else
		printf_s("iTemp ���� �� �����Ƿ� �ش� ������ false �Դϴ�.\n");
	*/














	/**************************
		** [����Ʈ ������]
	***************************/



	//** ���� 1

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
			** [����] FizzBuzz

			1 ~ 50 ���� ����ϸ鼭 3�� ����� Fizz, 5�� ����� Buzz ��
			�׸��� 3�� 5�� ������� FizzBuzz ����ϴ� ���α׷��� �ۼ� �Ͻÿ�.

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

	fprintf(pFile, "���ݷ� %d\n", 150);
	fprintf(pFile, "���� %d\n", 80);
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

	//** ���
	for (int i = 0; i < 4; i++)
	{
		printf_s("%s : %d\n", tUser[i].cpString, tUser[i].iValue);
	}
	*/


	system("pause");

	return 0;
}