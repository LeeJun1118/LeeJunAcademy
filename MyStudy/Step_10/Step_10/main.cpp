#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct tagStatus
{
	int iValue;
	char cpString[128];
};

// # ���� ��ó�� ���ù�
/*
	
	[��ó�� ���ù�]

	��ũ�μ� Ű����� 
	#include
	#define DEBUG(������)     ���  
	#if, #else ,#endif
	
	�������� �з��� �ȴ�.
	#if , #ifdef , #else  ,#endif
	���ǰ� �Ǿ������� ����ȴ�

	


*/


	// \ : �ٷ� �ؿ� ���̶� �̾��ش� 



//�����ݷ��� �̹� ���� �ִ� �Ŷ�� ����

//#define WHTITLE(cond) \
//	{ \
//		int i = 0;\
//		WHILE:\
//		i++;\
//		printf_s("goto���� ����Ͽ� �̷��� �ݺ� �� �� �ֽ��ϴ�. \n");\
//		if (i < cond)\
//			goto WHILE;\
//		else\
//			goto EXIT;\
//EXIT:\
//		printf_s("���� �Ǿ����ϴ�. \n");\
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
	
	// ���� 1

	//�ϴ� �ѹ��� ����ȴ�.
	//int i = 0;
	//do
	//{
	//	printf("%02d \n", i++);  //02d �ڸ��� ���ڸ� ���� ����ٴ�
	//} while (i < 10);
	

	//���� 2
	/*do
	{
		printf_s("�ϴ� �ѹ� ���� �˴ϴ�.");
	} while (false);*/
	
	
	// [goto]

	// ���� 1

	/*int i = 0;
WHILE:
	i++;

	printf_s("goto���� ����Ͽ� �̷��� �ݺ� �� �� �ֽ��ϴ�. \n");

	if (i < 10)
		goto WHILE;
	else
		goto EXIT;

EXIT:
	printf_s("���� �Ǿ����ϴ�. \n");*/


	// [���� ������]
		

	//��ǻ�����״� ���׿�����
	//printf_s("%d", 1220 + 3250 + 3470 + 4670);

	//����  1
	
	/*int iTemp = 10;
	int iDest = 20;

	printf_s("%s���� �� Ů�ϴ�.\n", (iTemp < iDest) ? "iTemp" : "iDest");
	*/

	//���� 2

	//int itemp = 10;
	//int idest = 20;

	////�ش� ������ �´ٸ� true �� ��ȯ�ϹǷ� if���� �����
	//if ((itemp > idest) ? true : false)
	//	printf_s("itemp ���� �� ũ�Ƿ� �ش� ������ true�Դϴ�. \n");
	//else
	//	printf_s("idest ���� �� ũ�Ƿ� �ش� ������ false�Դϴ�. \n");

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
	//Data��� ������ �̸� ����� ���ƾ��Ѵ�.
	//Status��� ������ ���⼭ ����°Ŵ�
	tagStatus tUser[4];

	FILE* pFile = fopen("../Data/Status.txt","w");


	fprintf(pFile, "���ݷ� %d \n", 1000);
	fprintf(pFile, "���� %d \n", 30);
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