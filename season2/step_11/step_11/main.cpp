#include "Headers.h"



//** 전역변수
SCENEID eSCENEID = SCENEID_LOGO;



//** 함수 전방선언
void SetScene(Object* _pPlayer, Object* _pMonster[], Object* _pBullet[]);
char* SetName();
Object* CreateObject();

void InitPlayer(Object* _pPlayer);
void PlayerProgress(Object* _pPlayer, Object* _pBullet[]);
void PlayerRender(Object* _pPlayer);

void InitMonster(Object* _pMonster);
void MonsterProgress(Object* _pMonster[]);
void MonsterRender(Object* _pMonster[]);


void InitBullet(Object* _pBullet);
void BulletProgress(Object* _pPlayer, Object* _pBullet[]);
void BulletRender(Object* _pBullet[]);
void CreateBullet(Object* _pBullet[], Object* _pPlayer);

//** 입력된 (x,y)좌표에 문자열 출력 
void SetCursorPosition(int _ix, int _iy, char* _str);
DWORD InputKey();


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
		pBullet[i] = NULL;
	

	
	//시간 = 현재시간
	DWORD dwTime = GetTickCount();
	
	while (true)
	{
		if (dwTime + 50 < GetTickCount())
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
		BulletProgress(_pPlayer,_pBullet);
		BulletRender(_pBullet);
		
		PlayerProgress(_pPlayer, _pBullet);
		PlayerRender(_pPlayer);
		
		
		/*MonsterProgress(_pMonster);
		MonsterRender(_pMonster);
		*/
		
		
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

	printf_s("당신은 누구인가요 ?\n");	Sleep(10);
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
	
	
}
void MonsterProgress(Object* _pMonster[])
{

	for (int i = 0; i < MONSTER_MAX; i++)
	{
	_pMonster[i]->TransPos.Position.x++;
	_pMonster[i]->TransPos.Position.y++;
			 
	_pMonster[i]->TransPos.Scale.x++;
	_pMonster[i]->TransPos.Scale.y++;


	
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

	

	}
}

void InitPlayer(Object* _pPlayer)
{
	_pPlayer->pName = (char*)"옷";

	_pPlayer->TransPos.Position = Vector3(0.f, 0.f);
	_pPlayer->TransPos.Scale = Vector3(0.f, 0.f);

	
	
}

void PlayerProgress(Object* _pPlayer, Object* _pBullet[])
{

	DWORD dwKey = InputKey();

	if (dwKey & KEYID_UP)
		_pPlayer->TransPos.Position.y--;
			
	if (dwKey & KEYID_DOWN)
		_pPlayer->TransPos.Position.y++;
			
	if (dwKey & KEYID_LEFT)
		_pPlayer->TransPos.Position.x--;
		
	if (dwKey & KEYID_RIGHT)
		_pPlayer->TransPos.Position.x++;
		
	//**만약 스페이스 키를 입력 했다면
	if (dwKey & KEYID_SPACE)
	{
		
		CreateBullet(_pBullet, _pPlayer);
	
	}
}

void PlayerRender(Object* _pPlayer)
{


	SetCursorPosition(_pPlayer->TransPos.Position.x,
					  _pPlayer->TransPos.Position.y, 
					  _pPlayer->pName);

	
}



void InitBullet(Object* _pBullet)
{
	_pBullet->TransPos.Position = Vector3(0.f, 0.f);

	_pBullet->TransPos.Scale = Vector3(0.f, 0.f);
	
	_pBullet->pName = (char*)"장풍";
	

}

void BulletProgress(Object* _pPlayer,Object* _pBullet[])
{
	//** 모든 총알을 확인
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//** 만약 총알이 있다면 
		if (_pBullet[i])
		{
			//** 총알이 x좌표를 2씩 증가시킨다.
			_pBullet[i]->TransPos.Position.x += 2;

			//** 만약 증가된 후에 x좌표가 월드좌표 95보다 크다면
			if (_pBullet[i]->TransPos.Position.x > 115)
			{
				//**동적 할당 해제
				free(_pBullet[i]);

				//** 초기화
				_pBullet[i] = NULL;
				
			}

		}
	}
	

}


void BulletRender(Object* _pBullet[])
{


	for (int i = 0; i < BULLET_MAX; i++)
	{
		//** 만약 총알이 있다면
		if (_pBullet[i])
		{
			//** 총알을 출력해줌
			SetCursorPosition(_pBullet[i]->TransPos.Position.x,
				_pBullet[i]->TransPos.Position.y,
				_pBullet[i]->pName);

		}
	}

}

//**총알 생성
void CreateBullet(Object* _pBullet[], Object* _pPlayer)
{
	//**모든 총알 리스트 확인
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//**만약에 총알이 없다면
		if (!_pBullet[i])
		{
			//**총알을 생성
			_pBullet[i] = CreateObject();
			
			//** 생성된 총알을 초기화
			InitBullet(_pBullet[i]);
			
			//**총알의 위치를 플레이어의 좌표로 변겅
			_pBullet[i]->TransPos.Position = _pPlayer->TransPos.Position;
			
			//**모든작업 종료된후 구문 탈출.
			break;
		}
	}
}

//** 입력된 (x,y)좌표에 문자열 출력 
void SetCursorPosition(int _ix, int _iy, char* _str)
{
	//** 좌표를 셋팅.
	COORD pos = {_ix, _iy};

	//**셋팅된 좌표로 콘솔 커서를 이동시킴.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	
	//이동된 위치에 문자열 출력.
	cout << _str;


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
		dwInput |= KEYID_LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		dwInput |= KEYID_RIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		dwInput |= KEYID_SPACE;
	}

	return dwInput;
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

