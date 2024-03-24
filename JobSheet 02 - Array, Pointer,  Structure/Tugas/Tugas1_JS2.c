/*
	Nama  : Ridho Hamdani Putra
	Nim   : 23343052
	Prodi : Informatika
	Tugas : Job Sheet 2
*/
#include <stdio.h>

struct Mahasiswa {
    int NIM;
    char nama[50];
    char tanggal_lahir[20]; 
    float ipk;
};

void input(struct Mahasiswa *mhs) { 
    printf("Menginputkan data mahasiswa\n");
    printf("Inputkan nama mahasiswa: ");
    scanf(" %[^\n]s", mhs->nama); 
    printf("Inputkan NIM mahasiswa: ");
    scanf("%d", &mhs->NIM);
    printf("Inputkan tanggal lahir mahasiswa (dd/mm/yyyy): ");
    scanf(" %[^\n]s", mhs->tanggal_lahir); 
    printf("Inputkan IPK mahasiswa: ");
    scanf("%f", &mhs->ipk);
}

void tampil(struct Mahasiswa mhs) { 
    printf("\nMenampilkan data mahasiswa\n");
    printf("Nama          : %s\n", mhs.nama);
    printf("NIM           : %d\n", mhs.NIM);
    printf("Tanggal Lahir : %s\n", mhs.tanggal_lahir);
    printf("IPK           : %.2f\n", mhs.ipk); 
}

int main() {
    struct Mahasiswa mhs;
    input(&mhs); 
    tampil(mhs); 
    return 0;
}

