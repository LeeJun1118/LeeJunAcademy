#include <stdio.h>
#include <stdlib.h>

/********************************************************
	** [요청사항]

	* [010.3958.7179]


	** [필수 사항]

	* 오픈톡 참여(강제) : https://open.kakao.com/o/g6HuIslb

	* 참여시 프로필 설정은 비공개로 해도 됩니다. 
	* 본명 말고 닉네임 적으셔도 됩니다.

	* 단톡방에 하기 어려운 말은 꼭 개인톡으로 해주시고,
		개인톡으로 말씀하실때 꼭 누군지 먼저 이야기 해주세요~

********************************************************/


int main(void)
{
	/*********************
		* 배열과 포인터
	**********************/

	//**  [실습]
	/*
	int iNum1 = 10;
	int iNum2 = 20;

	iNum1 = iNum2;



	int *piNum1 = &iNum1;
	int *piNum2;

	piNum2 = piNum1;
	*/




	/*
	int iArray[5] = { 0, 1, 2, 3, 4 };

	int *piPointer = iArray;

	printf_s("%d\n", *(piPointer++));
	printf_s("%d\n", *(piPointer++));
	printf_s("%d\n", *(piPointer));
	printf_s("%d\n", *(piPointer + 1));
	printf_s("%d\n", *(piPointer + 2));
	printf_s("%d\n", *(piPointer + 3));	// <= 쓰레기 값
	
	system("pause");
	*/







	/*
	int iArray[5] = { 0, 1, 2, 3, 4 };
	int *piPointer = iArray;

	for (int i = 0; i < 5; i++)
	{
		printf_s("%d\n", *(piPointer + i));
	}
	system("pause");
	*/
	


	/*
	int iArray[5] = { 0, 1, 2, 3, 4 };
	int* piter = iArray;

	for (int i = 0; i < 5; i++)
	{
		printf_s("%d\n", *(piter + i));
	}
	system("pause");
	*/
	


	/*
	int iArray[5] = { 0, 1, 2, 3, 4 };
	int *piPointer = iArray;

	for (int i = 0; i < 5; i++)
	{
		printf_s("%d\n", piPointer[i]);
	}
	system("pause");
	*/



	/********************************************************
		** [배열과 문자열]

		* [PPT 참고 ->  (../Resource/배열_문자열.png)]

	********************************************************/

	//**  [실습]

	/*
	char iArray[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	char* piter = iArray;

	for (int i = 0; i < 6; i++)
	{
		printf_s("%c", *(piter + i));
	}
	printf_s("\n");

	printf_s("%s\n", iArray);

	system("pause");
	*/



	/*
	char cString[] = { 'H', 'i', 0, 'T', 'h', 'e', 'r', 'e', 32 };
	
	for (int i = 0; i < 9; i++)
	{
		printf_s("%c", cString[i]);
	}
	printf_s("\n");

	printf_s("%s\n", cString);

	system("pause");
	*/


	/********************************************************
		** [포인터 문자열]

		* [PPT 참고 ->  (.. / Resource / 배열_문자열.png)]

	********************************************************/

	//**  [실습]

	/*
	char* pcString = (char*)"홍길동";
	
	printf_s("%s", pcString);
	printf_s("%d\n", sizeof(pcString));

	printf_s("%d\n", sizeof(__int64));



	system("pause");
	*/
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


	return 0;
}