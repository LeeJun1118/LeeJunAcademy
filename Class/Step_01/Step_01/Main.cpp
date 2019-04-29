#include <stdio.h> //** stdio.h = 입·출력 함수가 포함.
//** include = 1. 포함하다   2. ~을 (~에) 포함시키다

 
//** main = '함수' 라고 하고, 1개의 프로젝트 당 1개씩만 존재 할 수 있다.
int main(void)
{
	//** printf_s() = 출력 명령.
	printf_s("Hello World !! \n");

	//** [\n] = 줄바꿈
	//** [%d] = 정수 출력
	//** [%f] = 실수 출력


	//** () = 소괄호
	//** {} = 중괄호
	//** [] = 대괄호


	//** [;] = 세미콜론 (명령줄의 마지막을 컴파일러에게 알려줌.)
	//** [:] = 콜론 (C++ 때 많이 사용.)


	//** [&] = AND 연산자
	//** [|] = OR  연산자
	//** [^] = XOR 연산자
	//** [!] = NOT 연산자


	//** '' = 작은 따옴표 ( 문자  표현)
	//** "" =  큰  따옴표 (문자열 표현)


	//** [,] = 콤마
	//** [.] =  닷


	//** [&] = (엠퍼센트)
	//** [*] = (에스터리스크)


	/**************************************************
		*콘솔 창 유지 방법*

		1. 솔루션 탐색기 [프로젝트] 매뉴에서 [우클릭] 후
			가장 아래쪽에 [속성] 클릭.

		2. 새로운 윈도우 창에서 [링커] 매뉴 옆 [삼각형] 클릭.
		
		3. [링커] 매뉴 아래로 나오는 추가 매뉴 중 [시스템] 클릭.

		4. 우측에 새로운 창이 활성화 되고, 상단에 [하위 시스템] 클릭.

		5. 가장 우측에 아래쪽 화살표 클릭 후 콘솔 매뉴 선택.

		6. 확인. (설정 완료)



		* 프로그램 빌드: <Ctrl + Shift + B> 또는 [빌드] > [솔루션 빌드] 메뉴
		* 프로그램 빌드 후 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴

		* 중단점: <F9> 키
		* 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

	***************************************************/



	/****************************************************
	
		* 프로그램 설치 참고 *
		https://indevgame.tistory.com/7?category=831189

	*****************************************************/


	return 0;
}

/***********************************************************************************************************************************************
	[시작을 위한 팁]

	* 1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
	* 2. [팀 탐색기] 창을 사용하여 소스코드를 관리 합니다.
	* 3. [출력] 창을 사용하여 빌드 출력 내용 및 기타 오류 메시지를 확인합니다.
	* 4. [오류 목록] 창을 사용하여 오류를 확인 합니다.
	* 5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
	* 6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

************************************************************************************************************************************************/
	