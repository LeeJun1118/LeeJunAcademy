#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>






//시간
int main(void)
{
	//시간 = 현재시간
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