#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

// 8 bytes random generator
void generateRandomBytes(BYTE* data, size_t length) {
    srand(time(0));
    for (size_t i = 0; i < length; ++i) {
        data[i] = rand() % 256; // Generates a random byte
    }
}

void SetRegistryKey() {
    HKEY hKey;
    LPCSTR subKey = "SOFTWARE\\YourKey";
    BYTE randomBytes[8];

    generateRandomBytes(randomBytes, sizeof(randomBytes));

    LONG createStatus = RegCreateKeyEx(HKEY_CURRENT_USER, subKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

    if (createStatus == ERROR_SUCCESS) {
        printf("Success creating the key.\n");
    }
    else {
        printf("Error creating the key.\n");
        return;
    }

    LPCSTR valueName = "YourValueName";
    DWORD dwType = REG_BINARY;
    DWORD dwSize = sizeof(randomBytes);

    LONG setStatus = RegSetValueEx(hKey, valueName, 0, dwType, randomBytes, dwSize);

    if (setStatus == ERROR_SUCCESS) {
        printf("Success setting the value.\n");
    }
    else {
        printf("Error setting the value.\n");
    }

    RegCloseKey(hKey);
}

int main() {
    SetRegistryKey();
    return 0;
}