#include <stdio.h>
#include <stdlib.h>



int main(void) {

	int iArray[30];

	for (int i = 0; i < 30; i++)
	{

		iArray[i] = i;
		printf_s("%d  \n", iArray[i]);
			
	}

	system("pause");
	return 0;
}