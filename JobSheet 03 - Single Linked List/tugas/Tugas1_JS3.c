/*
	Nama  : Ridho Hamdani Putra
	Nim   : 23343052
	Prodi : Informatika
	Tugas : Job Sheet 3 Fibonanci
*/
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menghitung deret Fibonacci ke-n
int *fibonacci(int n) {
    int *fib = (int *)malloc(n * sizeof(int));
	int i;
    if (fib == NULL) {
        printf("Pengalokasian memori gagal.\n");
        exit(1);
    }

    fib[0] = 0;
    fib[1] = 1;
	
	
    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib;
}

int main() {
    int i,n;

    printf("Masukkan nilai n untuk deret Fibonacci: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Nilai n harus lebih besar dari 0.\n");
        return 1;
    }

    int *fib = fibonacci(n);

    printf("Deret Fibonacci pertama %d:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    // Menggunakan free untuk membebaskan memori yang dialokasikan
    free(fib);

    return 0;
}

