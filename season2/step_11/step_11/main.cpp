#include "Headers.h"



//** ��������
SCENEID eSCENEID = SCENEID_LOGO;



//** �Լ� ���漱��
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

//** �Էµ� (x,y)��ǥ�� ���ڿ� ��� 
void SetCursorPosition(int _ix, int _iy, char* _str);
DWORD InputKey();


//Vector3�� 3��� : Position, Scale, Lotation
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
	

	
	//�ð� = ����ð�
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
	//** �Ʒ� �ڵ�� �������� ������
	/*
	srand(GetTickCount() * GetTickCount());
	
	*/
	//for (int i = 0; i < 10; i++)
	//{
	//	int iRand = rand();


	//	/*****************************************************
	//		** [����]
	//		���� iRand �� ���� Ȧ������ ¦������ Ȯ���ϰ�,
	//		¦���� 0�� Ȧ���� 1�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	//		����� ��:)
	//			12451 = 1
	//			76388 = 0
	//			24517 = 1
	//			95124 = 0
	//				.
	//				.
	//				.
	//		�� ������ �� 10 ȸ ��� �˴ϴ�.
	//	******************************************************/

	//	//** Ǯ���� �ڵ带 �ۼ��մϴ�.
	//	if (iRand % 2 == 0)
	//		printf_s("%d = 0 \n", iRand);
	//	else
	//		printf_s("%d = 1 \n", iRand);

	//	Sleep(100);

	//	//** ���� ���ϼ̽��ϴ� !!

	//	//** Ǯ���� �ڵ� �ۼ��� �����ϴ�.
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

	printf_s("����� �����ΰ��� ?\n");	Sleep(10);
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

	printf_s("�г��� : %s\n", _pMonster[i]->pName);

	

	}
}

void InitPlayer(Object* _pPlayer)
{
	_pPlayer->pName = (char*)"��";

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
		
	//**���� �����̽� Ű�� �Է� �ߴٸ�
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
	
	_pBullet->pName = (char*)"��ǳ";
	

}

void BulletProgress(Object* _pPlayer,Object* _pBullet[])
{
	//** ��� �Ѿ��� Ȯ��
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//** ���� �Ѿ��� �ִٸ� 
		if (_pBullet[i])
		{
			//** �Ѿ��� x��ǥ�� 2�� ������Ų��.
			_pBullet[i]->TransPos.Position.x += 2;

			//** ���� ������ �Ŀ� x��ǥ�� ������ǥ 95���� ũ�ٸ�
			if (_pBullet[i]->TransPos.Position.x > 115)
			{
				//**���� �Ҵ� ����
				free(_pBullet[i]);

				//** �ʱ�ȭ
				_pBullet[i] = NULL;
				
			}

		}
	}
	

}


void BulletRender(Object* _pBullet[])
{


	for (int i = 0; i < BULLET_MAX; i++)
	{
		//** ���� �Ѿ��� �ִٸ�
		if (_pBullet[i])
		{
			//** �Ѿ��� �������
			SetCursorPosition(_pBullet[i]->TransPos.Position.x,
				_pBullet[i]->TransPos.Position.y,
				_pBullet[i]->pName);

		}
	}

}

//**�Ѿ� ����
void CreateBullet(Object* _pBullet[], Object* _pPlayer)
{
	//**��� �Ѿ� ����Ʈ Ȯ��
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//**���࿡ �Ѿ��� ���ٸ�
		if (!_pBullet[i])
		{
			//**�Ѿ��� ����
			_pBullet[i] = CreateObject();
			
			//** ������ �Ѿ��� �ʱ�ȭ
			InitBullet(_pBullet[i]);
			
			//**�Ѿ��� ��ġ�� �÷��̾��� ��ǥ�� ����
			_pBullet[i]->TransPos.Position = _pPlayer->TransPos.Position;
			
			//**����۾� ������� ���� Ż��.
			break;
		}
	}
}

//** �Էµ� (x,y)��ǥ�� ���ڿ� ��� 
void SetCursorPosition(int _ix, int _iy, char* _str)
{
	//** ��ǥ�� ����.
	COORD pos = {_ix, _iy};

	//**���õ� ��ǥ�� �ܼ� Ŀ���� �̵���Ŵ.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	
	//�̵��� ��ġ�� ���ڿ� ���.
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

