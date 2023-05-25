#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include<locale.h>

//HANDLE�� 32��Ʈ �ü������ unsinged int �ڷ����� �����ϴ�.
	//Win32���α׷����� �ڵ鰪�� �����Ҷ� HANDLE �ڷ����� ����Ѵ�.
//HANDLE hFind;

//windows.h�� ���ǵǾ��ִ� ����ü�̴�. FindFirstFile�� ���� ���� ������ �Ѱ��ִ� �Լ��� ȣȯ. A�� �� ���̸� �ƽ�Ű �ڵ�� ��ȯ�� ���ڴٴ� ��
WIN32_FIND_DATA FindData;

void FindExtension(wchar_t path[255]) {
	//FindFirstFile�� ��ȯ�� ���� �˻� �ڵ��� �Ѱ��ش�.
	HANDLE hFind = FindFirstFile(path, &FindData);
	//���� �Լ� ������ ���н� ���� ����
	if (hFind == INVALID_HANDLE_VALUE) {
		printf("FindFirstFile ����");
		printf("\n");
		exit(0);
	}

	do {
		//�Է¹��� FindData�� ���� �̸��� �������� ��, wide ���ڷ� ����Ѵ�.
		//wcsstr() �Լ��� wcs1���� wcs2�� ù ��° ǥ�� ���� ��ġ�� ���� �����͸� �����մϴ�.
		//wchar_t *wcsstr(const wchar_t *wcs1, const wchar_t *wcs2);
		//txt�� dock��� �ܾ ������ �� ���� ����ϱ� 
		if (wcsstr(FindData.cFileName, L"txt") != NULL || wcsstr(FindData.cFileName, L"docx"))
			wprintf(L"[+] %s\n", FindData.cFileName);



	} while (FindNextFile(hFind, &FindData));

	FindClose(hFind);

}

int main() {

	//wide character. 1����Ʈ�� char�δ� ǥ���� �Ѱ谡 ������
	//ISO���� �� ������ �´� �� �� �� �ֵ��� ���� ��. �� �ڵ带 ǥ���� ������ L�� ����Ѵ�.
	wchar_t path[255]; //2����Ʈ

	//wprintf �ѱ��� ?�� ������ ������ ��ħ
	//���� �ڵ�� ��ǻ�� �ý��� ������ �����ϴ� �ڵ��. �� Korean�� �������� �ϴ� �ڵ�
	setlocale(LC_ALL, "Korean");
	//����ȭ ������ �������� ����? ��ü������ �ѱ��� �����ϱ�
	_wsetlocale(LC_ALL, L"Korean");

	//wchar_t�̹Ƿ� L�� ����Ѵ�. wchar_t�� path���ٰ� const char*�� ��θ� �־��ش�.
	//Documents���� ã�ƺ���
	wcscpy(path, L"C:\\Users\\user\\Documents\\*");
	printf("Document���� ã�� txt�� docx : \n");
	FindExtension(path);

	wcscpy(path, L"C:\\Users\\user\\Downloads\\*");
	printf("Downloads���� ã�� txt�� docx : \n");
	FindExtension(path);

	wcscpy(path, L"C:\\Users\\user\\Desktop\\*");
	printf("Desktop���� ã�� txt�� docx : \n");
	FindExtension(path);


}