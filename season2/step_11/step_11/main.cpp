#include "Headers.h"


//** �Լ� ���漱��
char* SetName();
Student* CreateStudent();
void Initialize(Student* _pStudent);
void Render(Student* _pStudent);


int main(void)
{
	//** ���� �Ҵ�
	Student* ptStudent1 = (Student*)malloc(sizeof(Student));
	
	*ptStudent1 = tagStudent(10, 20, 30);
	printf_s("���� ���� : %d\n", ptStudent1->iKor);
	printf_s("���� ���� : %d\n", ptStudent1->iEng);
	printf_s("���� ���� : %d\n", ptStudent1->iMath);

	/*printf_s("%d \n", tStudent.iKor);
	printf_s("%d \n", tStudent.iEng);
	printf_s("%d \n", tStudent.iMath);*/
	//Render(pStudent1);
	

	system("pause");
	return 0;
}



char* SetName()
{
	//** ���ڿ� �Է�
	char str[128] = "";

	printf_s("�̸� �Է� : ");
	scanf_s("%s", str, 128);


	//** ���ڿ� ����
	char* pName = (char*)malloc(strlen(str));
	strcpy(pName, str);

	return pName;
}


Student* CreateStudent()
{
	Student* pStudent = (Student*)malloc(sizeof(Student));
	Initialize(pStudent);

	return pStudent;
}


void Initialize(Student* _pStudent)
{
	//�̸� �Է�
	_pStudent->pName = SetName();

	//** �� ���� �Է�
	printf_s("���� ���� �Է� : ");
	scanf_s("%d", &_pStudent->iKor);

	printf_s("���� ���� �Է� : ");
	scanf_s("%d", &_pStudent->iEng);

	printf_s("���� ���� �Է� : ");
	scanf_s("%d", &_pStudent->iMath);
}

void Render(Student* _pStudent)
{
	//** ���
	printf_s("\n\n** ���� ��� **\n");
	printf_s("�л� �̸� : %s\n", _pStudent->pName);
	printf_s("���� ���� : %d\n", _pStudent->iKor);
	printf_s("���� ���� : %d\n", _pStudent->iEng);
	printf_s("���� ���� : %d\n", _pStudent->iMath);
}