#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include<locale.h>

//HANDLE은 32비트 운영체제에서 unsinged int 자료형과 동일하다.
	//Win32프로그램에서 핸들값을 저장할때 HANDLE 자료형을 사용한다.
//HANDLE hFind;

//windows.h에 정의되어있는 구조체이다. FindFirstFile과 같이 파일 정보를 넘겨주는 함수와 호환. A를 더 붙이면 아스키 코드로 변환해 쓰겠다는 뜻
WIN32_FIND_DATA FindData;

void FindExtension(wchar_t path[255]) {
	//FindFirstFile이 반환한 파일 검색 핸들을 넘겨준다.
	HANDLE hFind = FindFirstFile(path, &FindData);
	//만약 함수 수행이 실패시 강제 종료
	if (hFind == INVALID_HANDLE_VALUE) {
		printf("FindFirstFile 실패");
		printf("\n");
		exit(0);
	}

	do {
		//입력받은 FindData의 파일 이름을 가져오는 것, wide 문자로 출력한다.
		//wcsstr() 함수는 wcs1에서 wcs2의 첫 번째 표시 시작 위치에 대한 포인터를 리턴합니다.
		//wchar_t *wcsstr(const wchar_t *wcs1, const wchar_t *wcs2);
		//txt나 dock라는 단어가 있으면 그 값을 출력하기 
		if (wcsstr(FindData.cFileName, L"txt") != NULL || wcsstr(FindData.cFileName, L"docx"))
			wprintf(L"[+] %s\n", FindData.cFileName);



	} while (FindNextFile(hFind, &FindData));

	FindClose(hFind);

}

int main() {

	//wide character. 1바이트인 char로는 표현의 한계가 있으니
	//ISO에서 각 지역에 맞는 언어를 쓸 수 있도록 만든 것. 이 코드를 표현할 떄에는 L을 사용한다.
	wchar_t path[255]; //2바이트

	//wprintf 한글이 ?로 나오는 오류를 고침
	//밑의 코드는 컴퓨터 시스템 지역을 설정하는 코드다. 즉 Korean을 따르도록 하는 코드
	setlocale(LC_ALL, "Korean");
	//지역화 설정을 전역으로 변경? 전체적으로 한글을 적용하기
	_wsetlocale(LC_ALL, L"Korean");

	//wchar_t이므로 L을 사용한다. wchar_t인 path에다가 const char*인 경로를 넣어준다.
	//Documents에서 찾아본다
	wcscpy(path, L"C:\\Users\\user\\Documents\\*");
	printf("Document에서 찾은 txt와 docx : \n");
	FindExtension(path);

	wcscpy(path, L"C:\\Users\\user\\Downloads\\*");
	printf("Downloads에서 찾은 txt와 docx : \n");
	FindExtension(path);

	wcscpy(path, L"C:\\Users\\user\\Desktop\\*");
	printf("Desktop에서 찾은 txt와 docx : \n");
	FindExtension(path);


}