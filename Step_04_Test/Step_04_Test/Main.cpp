#include <stdio.h>
#include <stdlib.h>




int main(void)
{
	/******************************************

		** ����)

		* Ű�� �����Ը� �Է��Ͽ� �� ������ Ȯ���ϴ�
			���α׷��� �ۼ��Ͻÿ�.

		* Tip.

			* Ű(Cm) /= 100; = [���ͷ� ��ȯ]
			* ������(BMI) = ������(Kg) / ( Ű(Cm) * Ű(Cm) )

			* float ���� double ���� Ȯ���Ͽ� �ۼ�.

			* 18.5���� ������ ��ü��
			* 18.5 ���� ũ�� 22.99 ���� ������ ����
			* 23.00 ���� ũ�� 24.99 ���� ������ ��ü��
			* 25.00 ���� ũ�� 29.99 ���� ������ ��
			* 30.00 ���� ũ�� �� ��

	*******************************************/

	float height = 0.0;
	float weight = 0.0;
	float bmi = 0.0;



	printf_s("�����Ը� �Է��ϼ��� \n");
	scanf_s("%f", &weight);

	printf_s("Ű�� �Է��ϼ��� \n");
	scanf_s("%f", &height);


	height /= 100;


	bmi = weight / (height * height);

	/*printf_s("%f \n", bmi);
	printf_s("%f \n", weight);
	printf_s("%f \n", height);*/

	if (bmi >= 30.00)
	{
		printf_s("�� �� �Դϴ�. \n");
		
	}
	else if (bmi >= 25.00)
	{
		printf_s("�� �Դϴ�. \n");
	}

	else if (bmi >= 23.00)
	{
		printf_s("��ü�� �Դϴ�. \n");
	}

	else if (bmi >= 18.5)
	{
		printf_s("���� �Դϴ�. \n");
	}

	else 
	{
		printf_s("��ü�� �Դϴ�. \n");
	}

	system("pause");
	return 0;
}