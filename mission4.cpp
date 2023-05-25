#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_key(unsigned char* key, int length) {
    srand(time(NULL));  // seed를 현재 시간으로 설정

    for (int i = 0; i < length; i++) {
        key[i] = rand() % 256;  // 0부터 255 사이의 임의의 값
    }
}

int main() {
    unsigned char key[8];  // 8바이트 키를 저장할 배열

    generate_random_key(key, sizeof(key));

    printf("랜덤 8바이트 키: ");
    for (int i = 0; i < sizeof(key); i++) {
        printf("%02X ", key[i]);
    }
    printf("\n");

    return 0;
}