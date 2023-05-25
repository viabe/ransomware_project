#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include<locale.h>

WIN32_FIND_DATA FindData;

//구조체 선언
typedef struct _FileDivision
{
	const wchar_t *kind[4] = {L"Desktop", L"Documents", L"Downloads"}; //txt파일명을 저장할 배열
	const wchar_t *list[3] = {L"\\*.txt", L"\\*.docx"}; //docx 파일명을 저장할 배열
	
}FileDivision; //구조체 별칭

void FindExtension(wchar_t path[255]) {
	
	HANDLE hFind = FindFirstFile(path, &FindData);

	do {
		//만약 함수 수행이 실패시 강제 종료
		if (hFind == INVALID_HANDLE_VALUE) {
			printf("FindFirstFile 실패");
			printf("\n");
			break;
		}
		//입력받은 FindData의 파일이름을 가져오는 것/wide 문자로 출력한다
		printf("File name: ");
		wprintf(L"[+] % s\n", FindData.cFileName);

		/*if(wcsstr(FindData.cFileName,L"txt") != NULL || wcsstr(FindData.cFileName,L"docx"))
				wprintf(L"[+] %s\n", FindData.cFileName);*/
			
			
				
	} while (FindNextFile(hFind, &FindData));

	FindClose(hFind);

}

int main() {

	_FileDivision data;

	setlocale(LC_ALL, "Korean");
	_wsetlocale(LC_ALL, L"Korean");

	for (int i = 0; i < 3; i++) {

		wchar_t path1[255] = L"C:\\Users\\user\\";; //txt 파일 넣기
		wchar_t path2[255] = L"C:\\Users\\user\\";; //docx 파일 넣기

		//path에 kind 추가
		wcscat(path1, data.kind[i]);
		wcscat(path2, data.kind[i]);
		//file이 들어오는 저장공간 출력
		wprintf(L"File list of %s\n", data.kind[i]);
		int j = 0;
		wcscat(path1, data.list[j]);
		wcscat(path2, data.list[j + 1]);

		FindExtension(path1);
		FindExtension(path2);
	}
}