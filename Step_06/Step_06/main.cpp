#include <stdio.h>
#include <stdlib.h>



int main(void) {
	/* �迭�� ����
	1.����
	2.�ε����� ���� ������ �����ϴ�
	3.������
	
	*/
	/*int iArray[30];

	for (int i = 0; i < 30; i++)
	{

		iArray[i] = i;
		printf_s("%d  \n", iArray[i]);
			
	}
	*/
	


	/* ���� ���⸦ �ʱ�ȭ �غ��ÿ�.
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
	/* ������ *   
		
		& : �ּ� ��ȯ ������
	
	*/

	int iNumber = 10;
	int *piNum = &iNumber;

	printf_s("%p : iNumber �� �ּ� \n", &iNumber);
	printf_s("%p : piNum������ ��� �ִ� �ּ� \n", piNum);

	printf_s("%p : piNum�� �ּ� \n", &piNum);
	
	printf_s("%d       : piNum ������ ��� �ִ� �ּ��� �� \n", *piNum);
	printf_s("%d       : iNumber�� �� \n", iNumber);


	system("pause");
	return 0;
}