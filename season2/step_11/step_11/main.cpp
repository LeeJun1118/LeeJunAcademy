#include "Headers.h"



//** 전역변수
SCENEID eSCENEID = SCENEID_LOGO;



//** 함수 전방선언
void SetScene(Object* _pPlayer, Object* _pMonster[], Object* _pBullet[]);
char* SetName();
Object* CreateObject();

void InitPlayer(Object* _pPlayer);
void PlayerProgress(Object* _pPlayer);
void PlayerRender(Object* _pPlayer);

void InitMonster(Object* _pMonster);
void MonsterProgress(Object* _pMonster[]);
void MonsterRender(Object* _pMonster[]);


void InitBullet(Object* _pBullet);
void BulletProgress(Object* _pBullet[]);
void BulletRender(Object* _pBullet[]);


//Vector3의 3요소 : Position, Scale, Lotation
int main(void)
{
	//**Player
	Object* pPlayer = CreateObject();
	InitPlayer(pPlayer);

	//**Monster
	Object* pMonster[MONSTER_MAX];
	for (int i = 0; i < MONSTER_MAX; i++)
	{
		pMonster[i] = CreateObject();
		InitMonster(pMonster[i]);
	}


	//**Bullet
	Object* pBullet[BULLET_MAX];
	for (int i = 0; i < BULLET_MAX; i++)
	{
		pBullet[i] = CreateObject();
		InitBullet(pBullet[i]);
	}

	
	//시간 = 현재시간
	DWORD dwTime = GetTickCount();
	
	while (true)
	{
		if (dwTime + 1000 < GetTickCount())
		{
			dwTime = GetTickCount();
			system("cls");
			
			
			SetScene(pPlayer,pMonster,pBullet);
		}
	}

	/*
	
	while (true)
	{
		system("cls");

		SetScene(pPlayer,pMonster);
	}

	*/
	//** 아래 코드는 수정하지 마세요
	/*
	srand(GetTickCount() * GetTickCount());
	
	*/
	//for (int i = 0; i < 10; i++)
	//{
	//	int iRand = rand();


	//	/*****************************************************
	//		** [문제]
	//		변수 iRand 의 값이 홀수인지 짝수인지 확인하고,
	//		짝수는 0을 홀수는 1을 출력하는 프로그램을 작성하시오.
	//		출력의 예:)
	//			12451 = 1
	//			76388 = 0
	//			24517 = 1
	//			95124 = 0
	//				.
	//				.
	//				.
	//		본 예제는 총 10 회 출력 됩니다.
	//	******************************************************/

	//	//** 풀이한 코드를 작성합니다.
	//	if (iRand % 2 == 0)
	//		printf_s("%d = 0 \n", iRand);
	//	else
	//		printf_s("%d = 1 \n", iRand);

	//	Sleep(100);

	//	//** 아주 잘하셨습니다 !!

	//	//** 풀이한 코드 작성을 끝냅니다.
	//}
	

	system("pause");

	return 0;
}

void SetScene(Object* _pPlayer, Object* _pMonster[], Object* _pBullet[])
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
		
		
		MonsterProgress(_pMonster);
		MonsterRender(_pMonster);
		
		BulletProgress(_pBullet);
		BulletRender(_pBullet);
		
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

	printf_s("당신은 누구인가요 ?\n");	Sleep(1000);
	printf_s("입력 : ");
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


void InitMonster(Object* _pMonster)
{

	_pMonster->TransPos.Scale = Vector3(0.f, 0.f);
	_pMonster->TransPos.Position = Vector3(0.f, 0.f);

	_pMonster->pName = (char*)"Monster";
	_pMonster->iAtt = 10;
	_pMonster->iDef = 8;
	_pMonster->iHP = 20;
	_pMonster->iMP = 5;
			 
	
}
void MonsterProgress(Object* _pMonster[])
{

	for (int i = 0; i < MONSTER_MAX; i++)
	{
	_pMonster[i]->TransPos.Position.x++;
	_pMonster[i]->TransPos.Position.y++;
			 
	_pMonster[i]->TransPos.Scale.x++;
	_pMonster[i]->TransPos.Scale.y++;


	_pMonster[i]->iAtt++;
	_pMonster[i]->iDef++;
	_pMonster[i]->iHP++;
	_pMonster[i]->iMP++;

	}
}
void MonsterRender(Object* _pMonster[])
{
	for (int i = 0; i < MONSTER_MAX; i++)
	{
	printf_s("Position y : %f\n", _pMonster[i]->TransPos.Position.y);
	printf_s("Position x : %f\n", _pMonster[i]->TransPos.Position.x);

	printf_s("Scale x : %f\n", _pMonster[i]->TransPos.Scale.x);
	printf_s("Scale y : %f\n", _pMonster[i]->TransPos.Scale.y);

	printf_s("닉네임 : %s\n", _pMonster[i]->pName);

	printf_s("공격력 : %d\n", _pMonster[i]->iAtt);
	printf_s("방어력 : %d\n", _pMonster[i]->iDef);
	printf_s("체력 : %d\n", _pMonster[i]->iHP);
	printf_s("마력 : %d\n", _pMonster[i]->iMP);

	}
}

void InitPlayer(Object* _pPlayer)
{
	_pPlayer->TransPos.Position = Vector3(0.f, 0.f);
	_pPlayer->TransPos.Scale = Vector3(0.f, 0.f);

	_pPlayer->pName = SetName();
	_pPlayer->iAtt = 10;
	_pPlayer->iDef = 8;
	_pPlayer->iHP = 20;
	_pPlayer->iMP = 5;
}

void PlayerProgress(Object* _pPlayer)
{
	_pPlayer->TransPos.Position.x++;
	_pPlayer->TransPos.Position.y++;
	
	_pPlayer->TransPos.Scale.x++;
	_pPlayer->TransPos.Scale.y++;


	_pPlayer->iAtt++;
	_pPlayer->iDef++;
	_pPlayer->iHP++;
	_pPlayer->iMP++;
}

void PlayerRender(Object* _pPlayer)
{
	printf_s("Position x : %f\n", _pPlayer->TransPos.Position.x);
	printf_s("Position y : %f\n", _pPlayer->TransPos.Position.y);
	
	printf_s("Scale x : %f\n", _pPlayer->TransPos.Scale.x);
	printf_s("Scale y : %f\n", _pPlayer->TransPos.Scale.y);

	printf_s("닉네임 : %s\n", _pPlayer->pName);

	printf_s("공격력 : %d\n", _pPlayer->iAtt);
	printf_s("방어력 : %d\n", _pPlayer->iDef);
	printf_s("체력 : %d\n", _pPlayer->iHP);
	printf_s("마력 : %d\n", _pPlayer->iMP);
}

void InitBullet(Object* _pBullet) 
{
	_pBullet->TransPos.Scale = Vector3(0.f, 0.f);
	_pBullet->TransPos.Position = Vector3(0.f, 0.f);

	_pBullet->pName = (char*)"Bullet";
	_pBullet->iAtt = 10;
	_pBullet->iDef = 8;
	_pBullet->iHP = 20;
	_pBullet->iMP = 5;

}
void BulletProgress(Object* _pBullet[])
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		_pBullet[i]->TransPos.Position.x++;
		_pBullet[i]->TransPos.Position.y++;

		_pBullet[i]->TransPos.Scale.x++;
		_pBullet[i]->TransPos.Scale.y++;


		_pBullet[i]->iAtt++;
		_pBullet[i]->iDef++;
		_pBullet[i]->iHP++;
		_pBullet[i]->iMP++;

	}
	

}


void BulletRender(Object* _pBullet[])
{

	for (int i = 0; i < BULLET_MAX; i++)
	{
		printf_s("Position y : %f\n", _pBullet[i]->TransPos.Position.y);
		printf_s("Position x : %f\n", _pBullet[i]->TransPos.Position.x);

		printf_s("Scale x : %f\n", _pBullet[i]->TransPos.Scale.x);
		printf_s("Scale y : %f\n", _pBullet[i]->TransPos.Scale.y);

		printf_s("닉네임 : %s\n", _pBullet[i]->pName);

		printf_s("공격력 : %d\n", _pBullet[i]->iAtt);
		printf_s("체력 : %d\n", _pBullet[i]->iHP);
		

	}

}






/*
//** [비트 연산]
//** 아래 예제를 복사하여 main에 붙혀넣기 후 확인하세요~

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
		printf_s("STATE_LEFT\n");
	}
	if (c & STATE_RIGHT)
	{
		printf_s("STATE_RIGHT\n");
	}
	if (c & STATE_ATT)
	{
		printf_s("STATE_ATT\n");
	}
	if (c & STATE_DIE)
	{
		printf_s("STATE_DIE\n");
	}
*/