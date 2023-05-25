#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include<locale.h>

WIN32_FIND_DATA FindData;

//����ü ����
typedef struct _FileDivision
{
	const wchar_t *kind[4] = {L"Desktop", L"Documents", L"Downloads"}; //txt���ϸ��� ������ �迭
	const wchar_t *list[3] = {L"\\*.txt", L"\\*.docx"}; //docx ���ϸ��� ������ �迭
	
}FileDivision; //����ü ��Ī

void FindExtension(wchar_t path[255]) {
	
	HANDLE hFind = FindFirstFile(path, &FindData);

	do {
		//���� �Լ� ������ ���н� ���� ����
		if (hFind == INVALID_HANDLE_VALUE) {
			printf("FindFirstFile ����");
			printf("\n");
			break;
		}
		//�Է¹��� FindData�� �����̸��� �������� ��/wide ���ڷ� ����Ѵ�
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

		wchar_t path1[255] = L"C:\\Users\\user\\";; //txt ���� �ֱ�
		wchar_t path2[255] = L"C:\\Users\\user\\";; //docx ���� �ֱ�

		//path�� kind �߰�
		wcscat(path1, data.kind[i]);
		wcscat(path2, data.kind[i]);
		//file�� ������ ������� ���
		wprintf(L"File list of %s\n", data.kind[i]);
		int j = 0;
		wcscat(path1, data.list[j]);
		wcscat(path2, data.list[j + 1]);

		FindExtension(path1);
		FindExtension(path2);
	}
}