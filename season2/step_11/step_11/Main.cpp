#include "Headers.h"



//** 전역변수
SCENEID eSCENEID = SCENEID_LOGO;
DWORD dwMonsterTime = 0;

int Collision = 0;
int iSleep = 0;
int iScore = 0;
int iGameover = 0;
int iLogoCheck = 0;


float fPlayerSpeed = 2;
int iPlayerCount = 0;
DWORD FrameTime = 280;


Logo* pLogo[13];


//** 함수 전방선언
void SetScene(Object* _pPlayer[], Object* _pMonster[]);
char* SetName();
Object* CreateObject();


void InitPlayer(Object* _pPlayer);
void PlayerProgress(Object* _pPlayer[], Object* _pMonster[]);
void PlayerRender(Object* _pPlayer[]);

void InitMonster(Object* _pMonster);
void MonsterProgress(Object* _pMonster[]);
void MonsterRender(Object* _pMonster[]);
void CreateMonster(Object* _pMonster[]);

void BackGroundRender();

void SetCursorPosiotion(int _ix, int _iy, char* _str,int _iColor);
void SetCursorPosiotionInteger(int _ix, int _iy, int _value);
void SetCursorColor(int _iColor);
DWORD InputKey();


int main(void)
{
	//** rand Initialize
	srand(GetTickCount());

	//** Create Logo
	for (int i = 0; i < 13; i++)
		pLogo[i] = (Logo*)malloc(sizeof(Logo));

	//** Logo Initialize
	for (int i = 0; i < 13; i++)
		pLogo[i]->TransPos.Position = Vector3(20.f, int(5.f + i));


	pLogo[0]->pName = (char*)"##                       #";
	pLogo[1]->pName = (char*)" ##                     ##";
	pLogo[2]->pName = (char*)" ##          ##        ##";
	pLogo[3]->pName = (char*)" ##          ##        ##         ###     #### #   ###  ##";
	pLogo[4]->pName = (char*)" ##          ##        ##   ####   ### ######  ## #### ####";
	pLogo[5]->pName = (char*)" ##          ##        ##  ######   #####       ##  ####  ##";
	pLogo[6]->pName = (char*)" ##          ##        ## ##    ##  ##          ##   ##   ##";
	pLogo[7]->pName = (char*)" ##          ##        ## ##    ##  ##          ##   ##   ##";
	pLogo[8]->pName = (char*)"  ##         ##        ## ##    ##  ##          ##   ##   ##";
	pLogo[9]->pName = (char*)"   ##        ##        #  ##    ##  ##          ##   ##   ##";
	pLogo[10]->pName = (char*)"    ###     ####      #   ##    ##  ##          ##   ##   ##";
	pLogo[11]->pName = (char*)"     ########  #######     ######   ###         ###  ###  ###";
	pLogo[12]->pName = (char*)"       ####     ####        ####    ###         ###  ###  ###";

	


	//** Create Player
	Object * pPlayer[PLAYER_MAX];

	//** MonsterList Initialize (= NULL)
	Object * pMonster[MONSTER_MAX];

	//** FrameTime Initialize
	DWORD dwTime = GetTickCount();

	//** Create Monster Time Initialize
	dwMonsterTime = GetTickCount();



	while (true)
	{
		if (dwTime + FrameTime + iSleep < GetTickCount())
		{
			dwTime = GetTickCount();
			system("cls");

			if (Collision)
			{
				Collision = 0;
				iSleep = 0;
			}

			SetScene(pPlayer, pMonster);
		}
	}

	system("pause");

	return 0;
}


void SetScene(Object* _pPlayer[], Object* _pMonster[])
{
	switch (eSCENEID)
	{
	case SCENEID_LOGO:
		pLogo[0]->iColor = rand()%16;

		if (iLogoCheck)
		{
			for (int i = 0; i < 13; i++)
			{
				pLogo[i]->TransPos.Position.y -= 1;


				if(pLogo[i]->TransPos.Position.y <= 1)
					eSCENEID = SCENEID_MENU;


				SetCursorPosiotion(
					int(pLogo[i]->TransPos.Position.x),
					int(pLogo[i]->TransPos.Position.y),
					pLogo[i]->pName, pLogo[i]->iColor);
			}
		}

		

		if (GetAsyncKeyState(VK_RETURN))
		{
			for (int i = 0; i < 13; i++)
			{

			}
			pLogo[i]->TransPos.Position.y -= 1;

		}
			eSCENEID = SCENEID_MENU;

		break;

	case SCENEID_MENU:
		FrameTime = 280;

		for (int i = 0; i < PLAYER_MAX; i++)
			_pPlayer[i] = NULL;

		_pPlayer[0] = CreateObject();
		InitPlayer(_pPlayer[0]);

		_pPlayer[0]->pName = (char*)"◎";

		iGameover = 0;
		iPlayerCount = 0;

		for (int i = 0; i < MONSTER_MAX; i++)
			_pMonster[i] = NULL;

		printf_s("SCENEID_MENU\n");
		system("pause");

		eSCENEID = SCENEID_STAGE;
		break;

	case SCENEID_STAGE:
		BackGroundRender();

		//** Progress
		PlayerProgress(_pPlayer, _pMonster);
		MonsterProgress(_pMonster);

		//** Render
		PlayerRender(_pPlayer);
		MonsterRender(_pMonster);


		if (iGameover)
			eSCENEID = SCENEID_MENU;

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

void InitPlayer(Object * _pPlayer)
{
	_pPlayer->pName = (char*)"■";
	_pPlayer->TransPos.eDirection = DIRID_RIGHT;
	_pPlayer->TransPos.Position = Vector3(2.f, 1.f);
	_pPlayer->TransPos.Scale = Vector3((float)strlen(_pPlayer->pName), 1.f);
}

void PlayerProgress(Object * _pPlayer[], Object * _pMonster[])
{
	DWORD dwKey = InputKey();

	if (dwKey & KEYID_UP && _pPlayer[0]->TransPos.eDirection != DIRID_DOWN)
		_pPlayer[0]->TransPos.eDirection = DIRID_UP;

	if (dwKey & KEYID_DOWN && _pPlayer[0]->TransPos.eDirection != DIRID_UP)
		_pPlayer[0]->TransPos.eDirection = DIRID_DOWN;

	if (dwKey & KEYID_LEFT && _pPlayer[0]->TransPos.eDirection != DIRID_RIGHT)
		_pPlayer[0]->TransPos.eDirection = DIRID_LEFT;

	if (dwKey & KEYID_RIGHT && _pPlayer[0]->TransPos.eDirection != DIRID_LEFT)
		_pPlayer[0]->TransPos.eDirection = DIRID_RIGHT;




	for (int i = iPlayerCount; i > 0; i--)
	{
		if (_pPlayer[i])
		{
			_pPlayer[i]->TransPos.Position = _pPlayer[i - 1]->TransPos.Position;
			_pPlayer[i]->TransPos.eDirection = _pPlayer[i - 1]->TransPos.eDirection;
		}
	}




	switch (_pPlayer[0]->TransPos.eDirection)
	{
	case DIRID_UP:
		if (_pPlayer[0]->TransPos.Position.y > 1)
			int(_pPlayer[0]->TransPos.Position.y -= fPlayerSpeed / 2);
		else
			iGameover = 1;
		break;
	case DIRID_DOWN:
		if (_pPlayer[0]->TransPos.Position.y < (WINSIZEY - 3))
			int(_pPlayer[0]->TransPos.Position.y += fPlayerSpeed / 2);
		else
			iGameover = 1;
		break;
	case DIRID_LEFT:
		if (_pPlayer[0]->TransPos.Position.x > 2)
			int(_pPlayer[0]->TransPos.Position.x -= fPlayerSpeed);
		else
			iGameover = 1;
		break;
	case DIRID_RIGHT:
		if (_pPlayer[0]->TransPos.Position.x < (WINSIZEX - 4))
			int(_pPlayer[0]->TransPos.Position.x += fPlayerSpeed);
		else
			iGameover = 1;
		break;
	}


	for (int i = 0; i < MONSTER_MAX; i++)
	{
		if (_pMonster[i])
		{
			if (int(_pPlayer[0]->TransPos.Position.x + _pPlayer[0]->TransPos.Scale.x) > (int)_pMonster[i]->TransPos.Position.x &&
				int(_pMonster[i]->TransPos.Position.x + _pMonster[i]->TransPos.Scale.x) > (int)_pPlayer[0]->TransPos.Position.x &&
				(int)_pMonster[i]->TransPos.Position.y == (int)_pPlayer[0]->TransPos.Position.y)
			{
				free(_pMonster[i]);
				_pMonster[i] = NULL;


				++iPlayerCount;

				_pPlayer[iPlayerCount] = CreateObject();
				InitPlayer(_pPlayer[iPlayerCount]);
				_pPlayer[iPlayerCount]->TransPos.Position = _pPlayer[iPlayerCount - 1]->TransPos.Position;
				_pPlayer[iPlayerCount]->TransPos.eDirection = _pPlayer[iPlayerCount - 1]->TransPos.eDirection;

				if (FrameTime > 40)
					FrameTime -= 20;


				Collision = 1;
				iSleep = 50;
				iScore += 5;
			}
		}
	}
}

void PlayerRender(Object * _pPlayer[])
{
	for (int i = 0; i < iPlayerCount + 1; i++)
	{
		if (_pPlayer[i])
		{
			SetCursorPosiotion(
				int(_pPlayer[i]->TransPos.Position.x),
				int(_pPlayer[i]->TransPos.Position.y),
				_pPlayer[i]->pName,13);
		}
	}
}

void InitMonster(Object * _pMonster)
{
	_pMonster->pName = (char*)"★";
	_pMonster->TransPos.Position = Vector3(0.f, 0.f);
	_pMonster->TransPos.Scale = Vector3((float)strlen(_pMonster->pName), 0.f);
	_pMonster->TransPos.eDirection = DIRID_CENTER;
}

void MonsterProgress(Object * _pMonster[])
{
	//** 일정 시간 마다..
	if (dwMonsterTime + 1500 < GetTickCount())
	{
		dwMonsterTime = GetTickCount();

		//** 몬스터를 생성.
		CreateMonster(_pMonster);
	}
}

void MonsterRender(Object * _pMonster[])
{
	//** 모든 몬스터 리스트를 확인.
	for (int i = 0; i < MONSTER_MAX; i++)
	{
		//** 만약에 몬스터 리스트에 몬스터가 있다면.....
		if (_pMonster[i])
		{
			SetCursorPosiotion(
				int(_pMonster[i]->TransPos.Position.x),
				int(_pMonster[i]->TransPos.Position.y),
				_pMonster[i]->pName,13);
		}
	}
}

void CreateMonster(Object * _pMonster[])
{
	//** 모든 몬스터 리스트를 확인.
	for (int i = 0; i < MONSTER_MAX; i++)
	{
		//** 만약에 몬스터 리스트에 몬스터가 없다면.....
		if (!_pMonster[i])
		{
			//** 몬스터를 생성.
			_pMonster[i] = CreateObject();

			//** 생성된 몬스터를 초기화.
			InitMonster(_pMonster[i]);

			//** 몬스터의 위치를 랜덤한 좌표로 변경.
			_pMonster[i]->TransPos.Position = Vector3(
				float(rand() % (WINSIZEX - 5) + 2),
				float(rand() % (WINSIZEY - 3) + 1));

			//** 모든 작업이 종료된 후 구문 탈출.
			break;
		}
	}
}

void BackGroundRender()
{
	for (int y = 0; y < WINSIZEY - 1; y++)
	{
		if (y == 0 || y == (WINSIZEY - 2))
		{
			SetCursorPosiotion(0, y, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■",15);
		}
		else
		{
			SetCursorPosiotion(0, y, (char*)"■",15);
			SetCursorPosiotion(WINSIZEX - 2, y, (char*)"■",15);

		}
	}
	SetCursorPosiotion(5, WINSIZEY - 1, (char*)"SCORE : ",15);
	SetCursorPosiotionInteger(14, WINSIZEY - 1, iScore);
}

//** 입력된 (x, y)좌표에 문자열 출력.
void SetCursorPosiotion(int _ix, int _iy, char* _str,int _iColor)
{
	//** 좌표를 셋팅.
	COORD pos = { (SHORT)_ix, (SHORT)_iy };

	//** 셋팅된 자표로 콘솔 커서를 이동시킴.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	SetCursorColor(_iColor);

	//** 이동된 위치에 문자열 출력.
	cout << _str;
}

//** 입력된 (x, y)좌표에 정수 출력.
void SetCursorPosiotionInteger(int _ix, int _iy, int _value)
{
	//** 좌표를 셋팅.
	COORD pos = { (SHORT)_ix, (SHORT)_iy };

	//** 셋팅된 자표로 콘솔 커서를 이동시킴.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	

	//** 이동된 위치에 문자열 출력.
	cout << _value;
}

void SetCursorColor(int _iColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _iColor);


}
DWORD InputKey()
{
	DWORD dwInput = 0;

	if (GetAsyncKeyState(VK_UP))
		dwInput |= KEYID_UP;

	if (GetAsyncKeyState(VK_DOWN))
		dwInput |= KEYID_DOWN;

	if (GetAsyncKeyState(VK_LEFT))
		dwInput |= KEYID_LEFT;

	if (GetAsyncKeyState(VK_RIGHT))
		dwInput |= KEYID_RIGHT;

	if (GetAsyncKeyState(VK_SPACE))
		dwInput |= KEYID_SPACE;

	return dwInput;
}



/*
void InitBullet(Object* _pBullet)
{
	_pBullet->pName = (char*)"장풍";

	_pBullet->TransPos.eDirection = DIRID_CENTER;
	_pBullet->TransPos.Position = Vector3(0.f, 0.f);
	_pBullet->TransPos.Scale = Vector3(strlen(_pBullet->pName), 1.f);
}

void BulletProgress(Object* _pBullet[])
{
	//** 모든 총알을 확인.
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//** 만약 총알이 있다면....
		if (_pBullet[i])
		{
			//** 총알의 X 좌표를 2씩 증가 시킨다.


			switch (_pBullet[i]->TransPos.eDirection)
			{
			case DIRID_UP:
				_pBullet[i]->TransPos.Position.y--;

				//** 만약 증가된 후에 Y좌표가 월드좌표 0보다 작다면....
				if ((_pBullet[i]->TransPos.Position.y <= 1) )
				{
					//** 동적 할당 해제
					free(_pBullet[i]);

					//** 초기화
					_pBullet[i] = NULL;
				}
				break;
			case DIRID_DOWN:
				_pBullet[i]->TransPos.Position.y++;

				//** 만약 증가된 후에 Y좌표가 월드좌표 25 보다 크다면....
				if ((_pBullet[i]->TransPos.Position.y >= (WINSIZEY - 1)))
				{
					//** 동적 할당 해제
					free(_pBullet[i]);

					//** 초기화
					_pBullet[i] = NULL;
				}
				break;
			case DIRID_RIGHT:
				_pBullet[i]->TransPos.Position.x += 2;

				//** 만약 증가된 후에 X좌표가 월드좌표 95 보다 크다면....
				if ((_pBullet[i]->TransPos.Position.x +
					_pBullet[i]->TransPos.Scale.x) > (WINSIZEX - 2))
				{
					//** 동적 할당 해제
					free(_pBullet[i]);

					//** 초기화
					_pBullet[i] = NULL;
				}
				break;
			case DIRID_LEFT:
				_pBullet[i]->TransPos.Position.x -= 2;

				//** 만약 증가된 후에 X좌표가 월드좌표 0 보다 작다면....
				if ( (_pBullet[i]->TransPos.Position.x <= 0 ) )
				{
					//** 동적 할당 해제
					free(_pBullet[i]);

					//** 초기화
					_pBullet[i] = NULL;
				}
				break;
			}
		}
	}
}

void BulletRender(Object* _pBullet[])
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//** 만약 총알이 있다면....
		if (_pBullet[i])
		{
			//** 총알을 출력해줌...
			SetCursorPosiotion(
				_pBullet[i]->TransPos.Position.x,
				_pBullet[i]->TransPos.Position.y,
				_pBullet[i]->pName);
		}
	}
}

//** 총알 생성
void CreateBullet(Object* _pBullet[], Object* _pPlayer)
{
	//** 모든 총알 리스트를 확인.
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//** 만약에 총알이 없다면.....
		if (!_pBullet[i])
		{
			//** 총알을 생성.
			_pBullet[i] = CreateObject();

			//** 생성된 총알 초기화.
			InitBullet(_pBullet[i]);

			//** 총알의 위치를 플레이어의 좌표로 변경.
			_pBullet[i]->TransPos.Position = _pPlayer->TransPos.Position;

			//** 플레이어의 현재 방향을 총알에 설정.
			SetBulletDirection(_pBullet[i], _pPlayer->TransPos.eDirection);

			//** 모든작업 종료된후 구문 탈출.
			break;
		}
	}
}

void SetBulletDirection(Object* _pBullet, DIRID _eDir)
{
	_pBullet->TransPos.eDirection = _eDir;
}
*/




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