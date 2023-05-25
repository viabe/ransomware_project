#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_key(unsigned char* key, int length) {
    srand(time(NULL));  // seed�� ���� �ð����� ����

    for (int i = 0; i < length; i++) {
        key[i] = rand() % 256;  // 0���� 255 ������ ������ ��
    }
}

int main() {
    unsigned char key[8];  // 8����Ʈ Ű�� ������ �迭

    generate_random_key(key, sizeof(key));

    printf("���� 8����Ʈ Ű: ");
    for (int i = 0; i < sizeof(key); i++) {
        printf("%02X ", key[i]);
    }
    printf("\n");

    return 0;
}