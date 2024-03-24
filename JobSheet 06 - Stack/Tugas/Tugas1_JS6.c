/*
	Nama  : Ridho Hamdani Putra
	Nim   : 23343052
	Prodi : Informatika
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Mahasiswa {
    char nim[20];
    char nama[50];
    float nilai;
};

struct Stack {
    int top;
    struct Mahasiswa data[MAX_SIZE];
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

void push(struct Stack *s, struct Mahasiswa mhs) {
    if (isFull(s)) {
        printf("Tumpukan penuh, tidak dapat menambahkan data.\n");
        return;
    }
    s->data[++s->top] = mhs;
    printf("Data mahasiswa berhasil ditambahkan ke dalam tumpukan.\n");
}

struct Mahasiswa pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Tumpukan kosong, tidak ada data yang dapat diambil.\n");
        exit(1);
    }
    return s->data[s->top--];
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Tumpukan kosong, tidak ada data yang ditampilkan.\n");
        return;
    }
    printf("Data mahasiswa dalam tumpukan:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("NIM: %s, Nama: %s, Nilai: %.2f\n", s->data[i].nim, s->data[i].nama, s->data[i].nilai);
    }
}

void swap(struct Mahasiswa *a, struct Mahasiswa *b) {
    struct Mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct Stack *s) {
    for (int i = 0; i <= s->top; i++) {
        for (int j = 0; j <= s->top - i - 1; j++) {
            if (strcmp(s->data[j].nim, s->data[j + 1].nim) > 0) {
                swap(&s->data[j], &s->data[j + 1]);
            }
        }
    }
    printf("Data mahasiswa berhasil diurutkan berdasarkan NIM secara ascending.\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);

    int pilihan;
    struct Mahasiswa mhs;
    char buffer[100];

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Hapus Data Mahasiswa Teratas\n");
        printf("3. Tampilkan Data Mahasiswa\n");
        printf("4. Urutkan Data Mahasiswa berdasarkan NIM\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        fflush(stdin); // Membersihkan buffer input

        switch (pilihan) {
            case 1:
                printf("Masukkan NIM: ");
                fgets(mhs.nim, sizeof(mhs.nim), stdin);
                mhs.nim[strcspn(mhs.nim, "\n")] = '\0'; // Menghilangkan newline karakter
                printf("Masukkan Nama: ");
                fgets(mhs.nama, sizeof(mhs.nama), stdin);
                mhs.nama[strcspn(mhs.nama, "\n")] = '\0'; // Menghilangkan newline karakter
                printf("Masukkan Nilai: ");
                fgets(buffer, sizeof(buffer), stdin);
                sscanf(buffer, "%f", &mhs.nilai); // Mengonversi string ke float
                push(&stack, mhs);
                break;
            case 2:
                mhs = pop(&stack);
                printf("Data mahasiswa yang diambil:\n");
                printf("NIM: %s, Nama: %s, Nilai: %.2f\n", mhs.nim, mhs.nama, mhs.nilai);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                bubbleSort(&stack);
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);

    return 0;
}
