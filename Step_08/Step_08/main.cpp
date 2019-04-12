#include <stdio.h>
#include <stdlib.h>

struct Student;
struct tagStudent //tag라고 붙인 이유 : 다른 사람이 만들어 넣은 구조체의 이름의 중복을 막기 위해서 쓴다.
{

	int iKor;
	int iEng;
	int iMath;

}Student;

int main (void){
	
	tagStudent tStudent[3];

	tStudent[0].iKor	= 1;
	tStudent[0].iEng	= 2;
	tStudent[0].iMath	= 3;
	
	tStudent[1].iKor	= 10;
	tStudent[1].iEng	= 20;
	tStudent[1].iMath	= 30;

	tStudent[2].iKor	= 100;
	tStudent[2].iEng	= 200;
	tStudent[2].iMath	= 300;


	for (int i = 0; i < 3; i++) {
			printf_s("%d번 점수 \n",i);

		
			printf_s("국어 점수 입력: ");
			scanf_s("%d", &tStudent[i].iKor);

			printf_s("영어 점수 입력: ");
			scanf_s("%d", &tStudent[i].iEng);

			printf_s("수학 점수 입력: ");
			scanf_s("%d", &tStudent[i].iMath);

			printf_s("\n");
		
	}


	for (int i = 0; i < 3; i++)
	{
		printf_s("%d의 점수 \n", i);
		printf_s("국어 점수 : %d \n", tStudent[i].iKor);
		printf_s("영어 점수 : %d \n", tStudent[i].iEng);
		printf_s("수학 점수 : %d \n", tStudent[i].iMath);

		printf_s("\n");
	}

	/*tStudent.iEng	= 80;
	tStudent.iKor	= 70;
	tStudent.iMath	= 100;

	printf_s("영어 점수 : %d \n", tStudent.iEng);
	printf_s("영어 점수 : %d \n", tStudent.iKor);
	printf_s("영어 점수 : %d \n", tStudent.iMath);*/

	system("pause");
}


