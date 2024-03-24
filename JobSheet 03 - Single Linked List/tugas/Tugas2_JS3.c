/*
	Nama  : Ridho Hamdani Putra
	Nim   : 23343052
	Prodi : Informatika
	Tugas : Job Sheet 3 Fibonanci
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fungsi untuk mengecek apakah sebuah bilangan adalah bilangan prima
bool isPrime(int num) {
	int i;
    if (num <= 1) 
        return false;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) 
            return false;
    }
    return true;
}

int main() {
    int n, i, m;
    
    printf("Masukkan nilai n untuk bilangan prima: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Nilai n harus lebih besar dari 0.\n");
        return 1;
    }

    printf("Masukkan ukuran awal memori (m): ");
    scanf("%d", &m);

    if (m <= 0) {
        printf("Ukuran awal memori harus lebih besar dari 0.\n");
        return 1;
    }

    int *primes = (int *)malloc(m * sizeof(int));

    if (primes == NULL) {
        printf("Pengalokasian memori gagal.\n");
        return 1;
    }

    int count = 0; // Jumlah bilangan prima yang telah ditemukan
    int num = 2;   // Bilangan yang akan diperiksa apakah prima
    while (count < n) {
        if (isPrime(num)) {
            primes[count] = num;
            count++;
            if (count == m) { // Jika array primes sudah penuh, alokasikan lebih banyak memori
                m *= 2;
                primes = (int *)realloc(primes, m * sizeof(int));
                if (primes == NULL) {
                    printf("Pengalokasian memori gagal.\n");
                    return 1;
                }
            }
        }
        num++;
    }

    printf("Bilangan prima pertama %d:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Membebaskan memori yang dialokasikan
    free(primes);

    return 0;
}

