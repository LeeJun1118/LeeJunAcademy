#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h> //Ÿ�� �Լ��� ����ϱ� ���� ���� (��ǻ���� ����Ǿ� �ִ� �ð� ��)


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
	
	// ����ü ������
	Student* ptStudent = (Student*)malloc(sizeof(Student)); //�����Ͱ� �ִ� ��ġ�� �� ������
	
	ptStudent->iKor		= 10;
	ptStudent->iEng		= 20;
	ptStudent->iMath	= 30;

	

	printf_s("%d\n", ptStudent-> iKor);
	printf_s("%d\n", ptStudent-> iEng);
	printf_s("%d\n", ptStudent-> iMath);

	*/

	/*
	// ����ü ������ �迭
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
	//���� ����
	srand(time(NULL)); //���� �����Լ��� �⺻���� �ʱ�ȭ �ϴ� �Լ�
	//srand(5);
	int iRand = rand(); //��ȯ ���� ������ ������ 

	printf_s("%d \n", iRand);
	
	*/

	/*
	�ǽ� : [����ü ������ �迭 ���]

	�ζ� ��ȣ ���� ���α׷� �����

	1.���ڴ� 1���� 45������ ������ �Ѵ�.
	2.���ڴ� �ϳ��� ���մ� 6���� �����ϰ�, �ߺ��� ���� ���� �ʴ´�.
	3.�� 5���� ������ �����, ���հ��� �ߺ��� ���� ��� ����.
	
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
		//5���� ���� ����
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
			** �ǽ� : [����ü ������ �迭 ���]

			* �ζ� ��ȣ ���� ���α׷� �����.

			�� �䱸 ���� ��

				A. ���ڴ� 1���� 45������ ������ �Ѵ�.
				B. ���ڴ� �ϳ��� ���մ� 6���� �����ϰ�,
					�ߺ��� ���� ���� �ʴ´�.

				C. �� 5 ���� ������ �����,
					���հ��� �ߺ��� ���ڴ� �������.

			** Tip

			typedef struct tagNumbers
			{
				int Number[6];

			}Numbers;

			Numbers* ptNumberList[5];

			==============================

			1 ~ 45 ������ ���� ���� ���.

			int iRand = rand() % 45 + 1;


		***********************************************/

		//** ���� �ʱ�ȭ
	srand(time(NULL));


	//** ���� ����Ʈ ����.
	Numbers* pNumberList[5];

	//** ���� ����� ���� & ���� ����
	for (int i = 0; i < 5; i++)
	{
		pNumberList[i] = (Numbers*)malloc(sizeof(Numbers));

		for (int j = 0; j < 6; j++)
		{
			pNumberList[i]->Number[j] = rand() % 45 + 1;
		}
	}

	//** ���� ��ȣ Ȯ���� ���� ����
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{

				//** ���� ���ڰ� �ִ��� Ȯ��.
				if (pNumberList[i]->Number[j] == pNumberList[i]->Number[k])
				{
					//** ���� ���� ���ڰ� �ִٸ�...

					int l = 0;

					while (true)
					{
						//** ���� ���ڸ� �߰��� ������ ���ʿ� ��ġ�� ���ڸ� �˻�.
						int iNumber = rand() % 45 + 1;

						//** �߰ߵ� ���������� ���ʿ� ��ġ�� ���ڿ� ��ġ�ϴ��� Ȯ��.
						if (iNumber == pNumberList[i]->Number[l])
						{
							//** ��ġ �Ѵٸ� �ٽ� ����
							iNumber = rand() % 45 + 1;

							l--;	//** ������ ���� �ٽ� �����ش�. (�ٽ� Ȯ���ؾ� �ϱ� ������...)
						}
						else
						{
							//** ��ġ�ϴ� ���ڰ� ���ٸ� ���������� ���Խ�Ų��.
							pNumberList[i]->Number[j] = iNumber;
							break;	// �׸��� Ż��
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


	//** ����
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


	//** ���
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