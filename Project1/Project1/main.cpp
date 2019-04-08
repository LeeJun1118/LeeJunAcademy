#include <stdio.h>
#include <stdlib.h>


int main(void) {
	/*
	★★★★★배열의 장점 외우기!
	1.인덱스에 직접 접근하는게 가능
	2.편리함 (변수 생성시)
	3.접근 속도가 항상 일정-> 매우 빠르다. 배열이 일렬로 나열되어 있기 때문이다.
	*/   

	/*
	★단점
	길이 값을 한번 선언하면 변경이 불가능하다. 처음에 선언된 길이 값 외에는 따로 변경할 수 없다.
	배열의 길에는 실수가 오면 안된다.정수형(상수)이어야 한다.  
	
	*/
	int iArray[10] = { 0,1,2,3,4,5,6,7,8,9 };

	iArray[0] = 0;
	iArray[1] = 10;
	iArray[2] = 20;
	iArray[3] = 30;
	iArray[4] = 40;
	iArray[5] = 50;
	iArray[6] = 60;
	iArray[7] = 70;
	iArray[8] = 80;
	iArray[9] = 90;

	
	for (int i = 0; i < 10; i++)
	{
		printf_s("%d \n",iArray[i]);
	}

	printf_s("%d \n", iArray[3]);



	system("pause");
	return 0;
}