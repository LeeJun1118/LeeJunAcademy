#include "Headers.h"


typedef struct tagObject
{
	int iNumber;
	char* Name;

}Object;



DWORD InputKey();


int main(void)
{
	Object* pObjectList[OBJECRID_MAX][OBJ_MAX];

	for (int i = 0; i < OBJECRID_MAX; i++)
	{
		for (int j = 0; j < OBJ_MAX ; j++)
		{
			pObjectList[i][j] = (Object*)malloc(sizeof(Object));
			pObjectList[i][j]->iNumber = i * OBJ_MAX + j;

			switch (i)
			{
			case OBJECRID_MONSTER:
				pObjectList[i][j]->Name = (char*)"Monster";
				break;

			case OBJECRID_BULLET:
				pObjectList[i][j]->Name = (char*)"Bullet";
				break;

			case OBJECRID_POTION:
				pObjectList[i][j]->Name = (char*)"Potion";
				break;

			case OBJECRID_NPC:
				pObjectList[i][j]->Name = (char*)"NPC";
				break;
			}
		}
	}

	
	for (int i = 0; i < OBJECRID_MAX; i++)
	{
		for (int j = 0; j < OBJ_MAX; j++)
		{
			printf_s("%d : %s\n", 
				pObjectList[i][j]->iNumber,
				pObjectList[i][j]->Name);
		}
	}
	

	/*for (int i = 0; i < OBJ_MAX; i++)
	{
		printf_s("%d : %s\n",
			pObjectList[OBJECRID_POTION][i]->iNumber,
			pObjectList[OBJECRID_POTION][i]->Name);
	}*/



	system("pause");






	Object* pMonster[3];

	for (int i = 0; i < 3; i++)
	{
		pMonster[i] = (Object*)malloc(sizeof(Object));
	}


	Object* pBullet[3];

	for (int i = 0; i < 3; i++)
	{
		pBullet[i] = (Object*)malloc(sizeof(Object));
	}




	DWORD dwTime = GetTickCount();

	while (true)
	{
		if (dwTime + 50 < GetTickCount())
		{
			dwTime = GetTickCount();
			system("cls");

			DWORD dwKey = InputKey();

			if (dwKey & KEYID_UP)
			{
				printf_s("KEYID_UP\n");
			}
			if (dwKey & KEYID_DOWN)
			{
				printf_s("KEYID_DOWN\n");
			}
			if (dwKey & KEYID_LEFT)
			{
				printf_s("KEYID_LEFT\n");
			}
			if (dwKey & KEYID_RIGHT)
			{
				printf_s("KEYID_RIGHT\n");
			}
			if (dwKey & KEYID_SPACE)
			{
				printf_s("KEYID_SPACE\n");
			}
		}
	}

	return 0;
}


DWORD InputKey()
{
	DWORD dwInput = 0;

	if (GetAsyncKeyState(VK_UP))
	{
		dwInput |= KEYID_UP;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		dwInput |= KEYID_DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		dwInput |= KEYID_RIGHT;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		dwInput |= KEYID_LEFT;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		dwInput |= KEYID_SPACE;
	}

	return dwInput;
}
