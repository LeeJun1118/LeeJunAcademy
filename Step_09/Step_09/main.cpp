#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h> //타임 함수를 사용하기 위해 포함 (컴퓨터의 내장되어 있는 시간 값)


/*
typedef struct Student
{
	int iKor;
	int iEng;
	int iMath;

}Student;

*/

typedef struct tagNumbers
{
	int Number[6];

}Numbers;


int main(void) {
	/*
	
	// 구조체 포인터
	Student* ptStudent = (Student*)malloc(sizeof(Student)); //포인터가 있는 위치를 잘 봐야함
	
	ptStudent->iKor		= 10;
	ptStudent->iEng		= 20;
	ptStudent->iMath	= 30;

	

	printf_s("%d\n", ptStudent-> iKor);
	printf_s("%d\n", ptStudent-> iEng);
	printf_s("%d\n", ptStudent-> iMath);

	*/

	/*
	// 구조체 포인터 배열
	Student* ptStudent[3];

	for (int i = 0; i < 3; i++)
	{
		ptStudent[i] = (Student*)malloc(sizeof(Student));
		ptStudent[i]->iKor = 0;
		ptStudent[i]->iEng= 0;
		ptStudent[i]->iMath= 0;
	}
	for (int i = 0;i  < 3; i++)
	{
		printf_s("%d \n", ptStudent[i]->iKor);
		printf_s("%d \n", ptStudent[i]->iEng);
		printf_s("%d \n", ptStudent[i]->iMath);
	}
	*/


	/*
	//난수 생성
	srand(time(NULL)); //난수 생성함수의 기본값을 초기화 하는 함수
	//srand(5);
	int iRand = rand(); //반환 값을 변수에 저장함 

	printf_s("%d \n", iRand);
	
	*/

	/*
	실습 : [구조체 포인터 배열 사용]

	로또 번호 생성 프로그램 만들기

	1.숫자는 1부터 45까지의 정수로 한다.
	2.숫자는 하나의 조합당 6개를 포함하고, 중복된 수는 갖지 않는다.
	3.총 5개의 조합을 만들고, 조합간의 중복된 수는 상관 없다.
	
	tip.
	typedef struct tagNumbers;
	{
		int Number[6];
	}Numbers;

	Numbers* ptNumberList[5];

	int iRand = rand()% 45 +1;
	*/

	srand(time(NULL));
	int iRand = rand() % 45 + 1;
	
	Numbers* ptNumberList[5];
	
	
	

	for (int i = 0; i < 5; i++)
	{
		//5개의 공간 생성
		 ptNumberList[i] = (Numbers*)malloc(sizeof(Numbers));
		
		for (int j = 0; j < 6; j++)
		{
			for (int k = j+1; k < 5; k++)
			{
				if (ptNumberList[i]->Number[j] == ptNumberList[i]->Number[k]) {
					int l = 0;
					while (true) {
						
						for (int l = 0; l < 6; l++)
						{
							if (ptNumberList[i]->Number[j] != ptNumberList[i]->Number[l]) {
								l++;
							}
							else {
								ptNumberList[i]->Number[j] = rand() % 45 + 1;
								if (l == j)
									break;
							}
								
						}
					}
					
					
				}

			}
			

			printf_s("%d ", ptNumberList[i]->Number[j]);
		}
		printf_s("\n");

		
	}


	system("pause");

	return 0;
}