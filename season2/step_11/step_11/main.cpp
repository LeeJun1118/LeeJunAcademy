#include "Headers.h"



//** ��������
SCENEID eSCENEID = SCENEID_LOGO;



//** �Լ� ���漱��
void SetScene(Object* _pPlayer);
char* SetName();
Object* CreateObject();

void InitPlayer(Object* _pPlayer);
void PlayerProgress(Object* _pPlayer);
void PlayerRender(Object* _pPlayer);



int main(void)
{
	/*
	Object* pPlayer = CreateObject();
	InitPlayer(pPlayer);

	while (true)
	{
		system("cls");
		SetScene(pPlayer);
	}
	*/





	//** �Ʒ� �ڵ�� �������� ������

	for (int i = 0; i < 10; i++)
	{
		srand(GetTickCount() * GetTickCount());
		int iRand = rand();
		

		/*****************************************************
			** [����]

			���� iRand �� ���� Ȧ������ ¦������ Ȯ���ϰ�,
			¦���� 0�� Ȧ���� 1�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

			����� ��:)

				12451 = 1
				76388 = 0
				24517 = 1
				95124 = 0
					.
					.
					.

			�� ������ �� 10 ȸ ��� �˴ϴ�.

		******************************************************/

		
		//** Ǯ���� �ڵ带 �ۼ��մϴ�.
	
	
		
		if (iRand % 2 == 0) {

			Sleep(100);
			printf_s("%d = 0 \n", iRand);
		}
			
		else {

			Sleep(100);
			printf_s("%d = 1 \n",iRand);
		}
		


		//** Ǯ���� �ڵ� �ۼ��� �����ϴ�.
	}

	system("pause");

	return 0;
}

void SetScene(Object* _pPlayer)
{
	switch (eSCENEID)
	{
	case SCENEID_LOGO:
		printf_s("SCENEID_LOGO\n");
		system("pause");

		eSCENEID = SCENEID_MENU;
		break;

	case SCENEID_MENU:
		printf_s("SCENEID_MENU\n");
		system("pause");

		eSCENEID = SCENEID_STAGE;
		break;

	case SCENEID_STAGE:
		PlayerProgress(_pPlayer);
		PlayerRender(_pPlayer);
		break;

	case SCENEID_STORE:
		printf_s("SCENEID_STORE\n");
		system("pause");
		break;

	case SCENEID_OPTION:
		printf_s("SCENEID_OPTION\n");
		system("pause");
		break;

	case SCENEID_EXIT:
		printf_s("SCENEID_EXIT\n");
		system("pause");
		break;
	}
}


char* SetName()
{
	char str[128] = "";

	printf_s("����� �����ΰ��� ?\n");	Sleep(1000);
	printf_s("�Է� : ");
	scanf_s("%s", str, 128);

	char* pName = (char*)malloc(strlen(str));
	strcpy(pName, str);

	return pName;
}

Object* CreateObject()
{
	Object* pObj = (Object*)malloc(sizeof(Object));

	return pObj;
}

void InitPlayer(Object* _pPlayer)
{
	_pPlayer->pName = SetName();
	_pPlayer->iAtt = 10;
	_pPlayer->iDef = 8;
	_pPlayer->iHP = 20;
	_pPlayer->iMP = 5;
}

void PlayerProgress(Object* _pPlayer)
{
	_pPlayer->iAtt++;
	_pPlayer->iDef++;
	_pPlayer->iHP++;
	_pPlayer->iMP++;
}

void PlayerRender(Object* _pPlayer)
{
	printf_s("�г��� : %s\n", _pPlayer->pName);
	printf_s("���ݷ� : %d\n", _pPlayer->iAtt);
	printf_s("���� : %d\n", _pPlayer->iDef);
	printf_s("ü�� : %d\n", _pPlayer->iHP);
	printf_s("���� : %d\n", _pPlayer->iMP);
}








/*
//** [��Ʈ ����]
//** �Ʒ� ������ �����Ͽ� main�� �����ֱ� �� Ȯ���ϼ���~

	// 00000001 = 1
	// 00000010 = 2
	// 00000100 = 4
	// 00001000 = 8
	// 00010000 = 16
	// 00100000 = 32
	// 01000000 = 64

	const char STATE_UP		= 1;
	const char STATE_DOWN	= 2;
	const char STATE_LEFT	= 4;
	const char STATE_RIGHT	= 8;
	const char STATE_ATT	= 16;
	const char STATE_DIE	= 32;

	char c = 3;

	if (c & STATE_UP)
	{
		printf_s("STATE_UP\n");
	}
	if (c & STATE_DOWN)
	{
		printf_s("STATE_DOWN\n");
	}
	if (c & STATE_LEFT)
	{
		printf_s("STATE_DOWN\n");
	}
	if (c & STATE_RIGHT)
	{
		printf_s("STATE_DOWN\n");
	}
	if (c & STATE_ATT)
	{
		printf_s("STATE_DOWN\n");
	}
	if (c & STATE_DIE)
	{
		printf_s("STATE_DOWN\n");
	}
*/