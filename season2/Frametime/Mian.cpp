#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>






//�ð�
int main(void)
{
	//�ð� = ����ð�
	DWORD dwTime = GetTickCount();
	int iCount = 0;

	while (true)
	{
		if (dwTime + 1000 < GetTickCount())
		{
			dwTime = GetTickCount();
			system("cls");
			printf_s("%d\n", iCount++);
		}
	}



	return 0;
}