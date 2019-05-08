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
	Object* pPlayer = CreateObject();
	InitPlayer(pPlayer);

	while (true)
	{
		system("cls");
		SetScene(pPlayer);
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


	default:
		break;
	}
}


char* SetName()
{
	//** ���ڿ� �Է�
	char str[128] = "";
	
	printf_s("����� �����ΰ��� ?\n"); Sleep(2000);
	
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
	_pPlayer->pName	= SetName();
	_pPlayer->iAtt	= 10;
	_pPlayer->iDef	= 8;
	_pPlayer->iHp	= 20;
	_pPlayer->iMp	= 5;
}
void PlayerProgress(Object* _pPlayer)
{
	
	_pPlayer->iAtt++;
	_pPlayer->iDef++;
	_pPlayer->iHp++;
	_pPlayer->iMp++;

}
void PlayerRender(Object* _pPlayer)
{
	printf_s("�г��� : %s\n", _pPlayer->pName);
	printf_s("���ݷ� : %d\n", _pPlayer->iAtt);
	printf_s("���� : %d\n", _pPlayer->iDef);
	printf_s("ü�� : %d\n", _pPlayer->iHp);
	printf_s("���� : %d\n", _pPlayer->iMp);
}
