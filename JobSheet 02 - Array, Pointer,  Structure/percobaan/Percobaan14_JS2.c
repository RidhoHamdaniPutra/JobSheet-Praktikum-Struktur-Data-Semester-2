/*
	Nama  : Ridho Hamdani Putra
	Nim   : 23343052
	Prodi : Informatika
*/
#include <stdio.h>
#include <conio.h>

int main(){
	int usia1 = 50;
	int usia2 = 18;
	//menciptakan sebuah printer
	int *ptr;
	//menugaskan pointer tersebut kepada usia1
	ptr = &usia1; // & adalah operator alamat
	
	printf("\nUsia saya (usia1): %d", usia1); // menampilkan 50
	printf("\nUsia saya (*ptr): %d", *ptr); // menampilkan 50
	// *ptr merupakan nilai yang disimpan ptr, yaitu 50
	printf("\n(&usia1) %x (ptr) %x", &usia1, ptr);
	// ptr adalah alamat dari usia1 jadi merupakan &usia1. Keduanya sama.
	// Sekarang Anda akan menugaskanyya kepada usia2
	ptr = &usia2;
	
	printf("\nUsia Anda (*ptr): %d", *ptr); //menampilkan 18
	// *ptr merupakan nilai yang disimpan dalam ptr, yaitu 18
	
	printf("\n(&usia2) %x (ptr) %x", &usia2, ptr);
	// ptr merupakan alamat dari usia2 jadi juga merupakan &usia2. Keduanya sama
	
	//menampilkan alamat dari variabel ptr. Anda tidak memerlukan
	//alamat ini
	printf("\n(&ptr) %x", &ptr);
	
	getch();
	
}//akhir main
