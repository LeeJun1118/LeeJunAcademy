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
			* ������(fBmi) = ������(Kg) / ( Ű(Cm) * Ű(Cm) )

			* float ���� double ���� Ȯ���Ͽ� �ۼ�.

			* 18.5���� ������ ��ü��
			* 18.5 ���� ũ�� 22.99 ���� ������ ����
			* 23.00 ���� ũ�� 24.99 ���� ������ ��ü��
			* 25.00 ���� ũ�� 29.99 ���� ������ ��
			* 30.00 ���� ũ�� �� ��

	*******************************************/

	//** �밡���� ǥ��� 
	float fHeight = 0.0;
	float fWeight = 0.0;
	float fBmi = 0.0;



	printf_s("�����Ը� �Է��ϼ��� : ");
	scanf_s("%f", &fWeight);

	printf_s("Ű�� �Է��ϼ��� : ");
	scanf_s("%f", &fHeight);


	fHeight /= 100;
	fBmi = fWeight / (fHeight * fHeight);

	if (fBmi < 18.5)
	{
		printf_s("��ü�� �Դϴ�. \n");
	}
	else if (fBmi >= 18.5 && fBmi <= 22.99)
	{
		printf_s("���� �Դϴ�. \n");
	}
	else if (fBmi >= 23.00 && fBmi <= 24.99)
	{
		printf_s("��ü�� �Դϴ�. \n");
	}
	else if (fBmi >= 25.00 && fBmi <= 29.99)
	{
		printf_s("�� �Դϴ�. \n");
	}
	else 
	{
		printf_s("�� �� �Դϴ�. \n");
	}

	system("pause");
	return 0;
}