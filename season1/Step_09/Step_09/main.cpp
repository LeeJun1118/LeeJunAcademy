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

	/**********************************************
			===============solution================
			** 실습 : [구조체 포인터 배열 사용]

			* 로또 번호 생성 프로그램 만들기.

			※ 요구 사항 ※

				A. 숫자는 1부터 45까지의 정수로 한다.
				B. 숫자는 하나의 조합당 6개를 포함하고,
					중복된 수는 갖지 않는다.

				C. 총 5 개의 조합을 만들고,
					조합간의 중복된 숫자는 상관없다.

			** Tip

			typedef struct tagNumbers
			{
				int Number[6];

			}Numbers;

			Numbers* ptNumberList[5];

			==============================

			1 ~ 45 사이의 난수 생성 방법.

			int iRand = rand() % 45 + 1;


		***********************************************/

		//** 난수 초기화
	srand(time(NULL));


	//** 조합 리스트 선언.
	Numbers* pNumberList[5];

	//** 조합 저장소 생성 & 난수 저장
	for (int i = 0; i < 5; i++)
	{
		pNumberList[i] = (Numbers*)malloc(sizeof(Numbers));

		for (int j = 0; j < 6; j++)
		{
			pNumberList[i]->Number[j] = rand() % 45 + 1;
		}
	}

	//** 같은 번호 확인후 변경 과정
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{

				//** 같은 숫자가 있는지 확인.
				if (pNumberList[i]->Number[j] == pNumberList[i]->Number[k])
				{
					//** 만약 같은 숫자가 있다면...

					int l = 0;

					while (true)
					{
						//** 같은 숫자를 발견한 숫자의 뒷쪽에 위치한 숫자를 검색.
						int iNumber = rand() % 45 + 1;

						//** 발견된 같은숫자의 뒷쪽에 위치한 숫자와 일치하는지 확인.
						if (iNumber == pNumberList[i]->Number[l])
						{
							//** 일치 한다면 다시 변경
							iNumber = rand() % 45 + 1;

							l--;	//** 증가된 값을 다시 내려준다. (다시 확인해야 하기 때문에...)
						}
						else
						{
							//** 일치하는 숫자가 없다면 정상적으로 대입시킨다.
							pNumberList[i]->Number[j] = iNumber;
							break;	// 그리고 탈출
						}

						if (l == j)
							break;
						else
							l++;
					}
				}
			}
		}
	}


	//** 정렬
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = j + 1; k < 6; k++)
			{
				if (pNumberList[i]->Number[j] > pNumberList[i]->Number[k])
				{
					int iTemp = pNumberList[i]->Number[j];
					pNumberList[i]->Number[j] = pNumberList[i]->Number[k];
					pNumberList[i]->Number[k] = iTemp;
				}
			}
		}
	}


	//** 출력
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf_s("%d  ", pNumberList[i]->Number[j]);
		}
		printf_s("\n");
	}

	system("pause");

	return 0;
}