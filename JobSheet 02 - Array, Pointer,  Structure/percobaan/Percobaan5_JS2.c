/*
	Nama  : Ridho Hamdani Putra
	Nim   : 23343052
	Prodi : Informatika
*/
#include <stdio.h>
#include <string.h>

struct Mahasiswa{
	char nama[50];
	char jurusan[50];
	int nilai;
};

int main(void){
	struct Mahasiswa mhs01;
	
	strcpy(mhs01.nama, "Ridho Hamdani Putra");
	strcpy(mhs01.jurusan, "Teknik Elektronika");
	mhs01.nilai = 100;
	
	printf("%s adalah mahasiswa jurusan %s ", mhs01.nama, mhs01.jurusan);
	printf("memperoleh nilai UAS %i \n", mhs01.nilai);
	
	return 0;
}
