#include <stdio.h>
#include <stdlib.h>




int main(void)
{
	/******************************************

		** 예제)

		* 키와 몸무게를 입력하여 비만 지수를 확인하는
			프로그램을 작성하시오.

		* Tip.

			* 키(Cm) /= 100; = [미터로 변환]
			* 비만지수(fBmi) = 몸무게(Kg) / ( 키(Cm) * 키(Cm) )

			* float 형과 double 형을 확인하여 작성.

			* 18.5보다 작으면 저체중
			* 18.5 보다 크고 22.99 보다 작으면 정상
			* 23.00 보다 크고 24.99 보다 작으면 과체중
			* 25.00 보다 크고 29.99 보다 작으면 비만
			* 30.00 보다 크면 고도 비만

	*******************************************/

	//** 헝가리안 표기법 
	float fHeight = 0.0;
	float fWeight = 0.0;
	float fBmi = 0.0;



	printf_s("몸무게를 입력하세요 : ");
	scanf_s("%f", &fWeight);

	printf_s("키를 입력하세요 : ");
	scanf_s("%f", &fHeight);


	fHeight /= 100;
	fBmi = fWeight / (fHeight * fHeight);

	if (fBmi < 18.5)
	{
		printf_s("저체중 입니다. \n");
	}
	else if (fBmi >= 18.5 && fBmi <= 22.99)
	{
		printf_s("정상 입니다. \n");
	}
	else if (fBmi >= 23.00 && fBmi <= 24.99)
	{
		printf_s("과체중 입니다. \n");
	}
	else if (fBmi >= 25.00 && fBmi <= 29.99)
	{
		printf_s("비만 입니다. \n");
	}
	else 
	{
		printf_s("고도 비만 입니다. \n");
	}

	system("pause");
	return 0;
}