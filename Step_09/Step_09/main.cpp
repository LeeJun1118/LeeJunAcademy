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
	int iRand = rand() % 45 + 1;
	
	Numbers* ptNumberList[5];
	
	srand(time(NULL));
	

	for (int i = 0; i < 5; i++)
	{

		//5���� ���� ����
		 ptNumberList[i] = (Numbers*)malloc(sizeof(Numbers));
		
		for (int j = 0; j < 6; j++)
		{
			
			//������ ptNumberList�� ����Ű�� Number�� ����
			ptNumberList[i]->Number[j] = rand() % 45 + 1;

			printf_s("%d ", ptNumberList[i]->Number[j]);
		}
		printf_s("\n");

		
	}


	system("pause");

	return 0;
}