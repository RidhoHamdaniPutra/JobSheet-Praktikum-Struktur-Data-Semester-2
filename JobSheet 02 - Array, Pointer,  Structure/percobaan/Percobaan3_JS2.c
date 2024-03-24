/*
	Nama  : Ridho Hamdani Putra
	Nim   : 23343052
	Prodi : Informatika
*/
#include <stdio.h>

int main(){
	
	int n;
	int angka[n];
	int i;
	
	printf("Masukkan banyaknya bilangan : ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		printf("Masukkan angka ke %d :", i+1);
		scanf("%d", &angka[i]);
	}
	
	for(i=0; i<n; i++){
		printf("Angka ke %d : %d\n", i+1, angka[i]);
	}
	
	getchar();
	return 0;
}
