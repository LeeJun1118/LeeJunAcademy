#include <stdio.h>
#include <stdlib.h>



int main(void) {
	/* 배열의 장점
	1.편리함
	2.인덱스에 직접 접근이 가능하다
	3.빠르다
	
	*/
	/*int iArray[30];

	for (int i = 0; i < 30; i++)
	{

		iArray[i] = i;
		printf_s("%d  \n", iArray[i]);
			
	}
	*/
	


	/* 다음 보기를 초기화 해보시오.
		int iArray[2][3][4][5] =
	*/
	/*int iArray[2][3][4][5] =
	{
		{
			   {
				{1,2,3,4,5},
				{1,2,3,4,5},
				{1,2,3,4,5},
				{1,2,3,4,5}


			    },
			 {
				{1,2,3,4,5},
				{1,2,3,4,5},
				{1,2,3,4,5},
				{1,2,3,4,5}

			 },
		    	{
				{1,2,3,4,5},
				{1,2,3,4,5},
				{1,2,3,4,5},
				{1,2,3,4,5}


			    }
		},

		{
				  {
					{1,2,3,4,5},
					{1,2,3,4,5},
					{1,2,3,4,5},
					{1,2,3,4,5}
				  },
				{
					{1,2,3,4,5},
					{1,2,3,4,5},
					{1,2,3,4,5},
					{1,2,3,4,5}
				},
				  {
					{1,2,3,4,5},
					{1,2,3,4,5},
					{1,2,3,4,5},
					{1,2,3,4,5}


				  } 
		}
	};

	int iArray2[2][3][4][5];
	int iCount = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int l = 0; l < 5; l++)
				{
					iArray2[i][j][k][l] = iCount++;
					printf_s("%d \n", iArray2[i][j][k][l]);
				}
			}
		}
	}*/
	/* 포인터 *   
		& : 주소 반환 연산자

		포인터 변수에 *를 붙이면 변수가 가리키고 있는 공간의 data를 반환한다.
	*/
	//  %p는 주소를 출력하는 서식 문자
	int iNumber = 10;
	int *piNum = &iNumber;

	printf_s("%p : iNumber 의 주소 \n", &iNumber);
	printf_s("%p : piNum변수가 담고 있는 주소 \n", piNum); //piNum한테는 그게 data

	printf_s("%p : piNum의 주소 \n", &piNum);  //piNum자기 주소
	
	printf_s("%d       : piNum 변수가 담고 있는 주소의 값 \n", *piNum); //   *를 쓰면 자기(주소)가 가리키는 data에 접근 가능
	printf_s("%d       : iNumber의 값 \n", iNumber);


	system("pause");
	return 0;
}