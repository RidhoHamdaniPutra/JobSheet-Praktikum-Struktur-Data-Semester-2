/*
	Nama  : Ridho Hamdani Putra
	Nim   : 23343052
	Prodi : Informatika
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan informasi buku
struct Buku {
    char judul[100];
    char pengarang[100];
    int tahun;
    struct Buku *prev;
    struct Buku *next;
};

// Fungsi untuk menambahkan buku ke dalam linked list
void tambahBuku(struct Buku **head, char judul[], char pengarang[], int tahun) {
    struct Buku *newBuku = (struct Buku *)malloc(sizeof(struct Buku));
    strcpy(newBuku->judul, judul);
    strcpy(newBuku->pengarang, pengarang);
    newBuku->tahun = tahun;
    newBuku->prev = NULL;
    newBuku->next = NULL;

    if (*head == NULL) {
        *head = newBuku;
        return;
    }

    struct Buku *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newBuku;
    newBuku->prev = temp;
}

// Fungsi untuk menghapus buku dari linked list berdasarkan judul
void hapusBuku(struct Buku **head, char judul[]) {
    if (*head == NULL) {
        printf("Linked list kosong.\n");
        return;
    }

    struct Buku *temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->judul, judul) == 0) {
            if (temp->prev == NULL) {
                *head = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = NULL;
                }
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
            }
            free(temp);
            printf("Buku dengan judul '%s' telah dihapus.\n", judul);
            return;
        }
        temp = temp->next;
    }
    printf("Buku dengan judul '%s' tidak ditemukan.\n", judul);
}

// Fungsi untuk menampilkan semua buku dalam linked list
void tampilkanBuku(struct Buku *head) {
    if (head == NULL) {
        printf("Linked list kosong.\n");
        return;
    }

    printf("Daftar Buku:\n");
    while (head != NULL) {
        printf("Judul: %s, Pengarang: %s, Tahun: %d\n", head->judul, head->pengarang, head->tahun);
        head = head->next;
    }
}

int main() {
    struct Buku *head = NULL;
    int pilihan;
    char judul[100];
    char pengarang[100];
    int tahun;

    do {
        printf("\nMENU:\n");
        printf("1. Tambah Buku\n");
        printf("2. Hapus Buku\n");
        printf("3. Tampilkan Semua Buku\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan judul buku: ");
                scanf("%s", judul);
                printf("Masukkan pengarang buku: ");
                scanf("%s", pengarang);
                printf("Masukkan tahun terbit buku: ");
                scanf("%d", &tahun);
                tambahBuku(&head, judul, pengarang, tahun);
                break;
            case 2:
                printf("Masukkan judul buku yang ingin dihapus: ");
                scanf("%s", judul);
                hapusBuku(&head, judul);
                break;
            case 3:
                tampilkanBuku(head);
                break;
            case 4:
                printf("Terima kasih telah menggunakan program ini.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    } while (pilihan != 4);

    return 0;
}
