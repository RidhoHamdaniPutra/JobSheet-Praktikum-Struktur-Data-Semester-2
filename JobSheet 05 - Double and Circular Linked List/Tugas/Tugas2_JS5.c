/*
	Nama  : Ridho Hamdani Putra
	Nim   : 23343052
	Prodi : Informatika
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan informasi mobil
struct Mobil {
    char no_plat[20];
    char merk[50];
    char nama_pemilik[100];
    struct Mobil *prev;
    struct Mobil *next;
};

// Fungsi untuk menambahkan mobil ke dalam antrian
void tambahMobil(struct Mobil **head, char no_plat[], char merk[], char nama_pemilik[]) {
    struct Mobil *newMobil = (struct Mobil *)malloc(sizeof(struct Mobil));
    strcpy(newMobil->no_plat, no_plat);
    strcpy(newMobil->merk, merk);
    strcpy(newMobil->nama_pemilik, nama_pemilik);
    newMobil->prev = NULL;
    newMobil->next = NULL;

    if (*head == NULL) {
        *head = newMobil;
        return;
    }

    struct Mobil *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newMobil;
    newMobil->prev = temp;
}

// Fungsi untuk menghapus mobil dari antrian berdasarkan nomor plat
void hapusMobil(struct Mobil **head, char no_plat[]) {
    if (*head == NULL) {
        printf("Antrian mobil kosong.\n");
        return;
    }

    struct Mobil *temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->no_plat, no_plat) == 0) {
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
            printf("Mobil dengan nomor plat '%s' telah keluar dari antrian.\n", no_plat);
            return;
        }
        temp = temp->next;
    }
    printf("Mobil dengan nomor plat '%s' tidak ditemukan dalam antrian.\n", no_plat);
}

// Fungsi untuk menampilkan semua mobil dalam antrian
void tampilkanAntrian(struct Mobil *head) {
    if (head == NULL) {
        printf("Antrian mobil kosong.\n");
        return;
    }

    printf("Antrian Mobil:\n");
    while (head != NULL) {
        printf("Nomor Plat: %s, Merk: %s, Nama Pemilik: %s\n", head->no_plat, head->merk, head->nama_pemilik);
        head = head->next;
    }
}

int main() {
    struct Mobil *head = NULL;
    int pilihan;
    char no_plat[20], merk[50], nama_pemilik[100];

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Mobil ke Antrian\n");
        printf("2. Keluarkan Mobil dari Antrian\n");
        printf("3. Tampilkan Antrian Mobil\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan Nomor Plat Mobil: ");
                scanf("%s", no_plat);
                printf("Masukkan Merk Mobil: ");
                scanf("%s", merk);
                printf("Masukkan Nama Pemilik: ");
                scanf("%s", nama_pemilik);
                tambahMobil(&head, no_plat, merk, nama_pemilik);
                break;
            case 2:
                printf("Masukkan Nomor Plat Mobil yang Keluar: ");
                scanf("%s", no_plat);
                hapusMobil(&head, no_plat);
                break;
            case 3:
                tampilkanAntrian(head);
                break;
            case 4:
                printf("Program berakhir.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    } while (pilihan != 4);

    return 0;
}
