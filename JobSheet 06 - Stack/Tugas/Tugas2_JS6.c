/*
	Nama  : Ridho Hamdani Putra
	Nim   : 23343052
	Prodi : Informatika
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char data[MAX_SIZE];
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char c) {
    if (isFull(s)) {
        printf("Tumpukan penuh, tidak dapat menambahkan karakter.\n");
        return;
    }
    s->data[++s->top] = c;
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Tumpukan kosong, tidak ada karakter yang dapat diambil.\n");
        exit(1);
    }
    return s->data[s->top--];
}

void reverseString(char *str) {
    struct Stack stack;
    initStack(&stack);

    // Push setiap karakter ke dalam stack
    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }

    // Pop setiap karakter dari stack untuk membalikkan string
    for (int i = 0; i < strlen(str); i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char kata[MAX_SIZE];
    int pilihan;

    do {
        printf("\nMenu:\n");
        printf("1. Input Kata\n");
        printf("2. Balik Kata\n");
        printf("3. Exit\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        fflush(stdin); // Membersihkan buffer input

        switch (pilihan) {
            case 1:
                printf("Masukkan kata: ");
                scanf("%s", kata);
                break;
            case 2:
                printf("Kata sebelum dibalik: %s\n", kata);
                reverseString(kata);
                printf("Kata setelah dibalik: %s\n", kata);
                break;
            case 3:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 3);

    return 0;
}
