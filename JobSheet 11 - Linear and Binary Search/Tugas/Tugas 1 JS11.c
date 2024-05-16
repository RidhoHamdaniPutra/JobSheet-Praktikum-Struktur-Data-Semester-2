/*
	Nama  : Ridho Hamdani Putra
	NIM   : 23343052
	Prodi : Informatika (NK)
*/

#include <stdio.h>
#include <string.h>

// Struktur data untuk mahasiswa
struct Mahasiswa {
    int NIM;
    char Nama[50];
    char TTL[50];
    float IPK;
};

// Fungsi sequential search
int sequentialSearch(struct Mahasiswa arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i].NIM == key) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}

// Fungsi binary search (mengharapkan array terurut)
int binarySearch(struct Mahasiswa arr[], int l, int r, int key) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m].NIM == key) {
            return m; // Mengembalikan indeks jika ditemukan
        }
        if (arr[m].NIM < key) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}

int main() {
    // Inisialisasi data mahasiswa
    struct Mahasiswa data[100];
    int n, i;

    printf("Masukkan jumlah data mahasiswa: ");
    scanf("%d", &n);

    // Memasukkan data mahasiswa
    for (i = 0; i < n; i++) {
        printf("\nData Mahasiswa ke-%d:\n", i + 1);
        printf("NIM: ");
        scanf("%d", &data[i].NIM);
        printf("Nama: ");
        scanf("%s", data[i].Nama);
        printf("TTL (format: tempat/tanggal-bulan-tahun): ");
        scanf("%s", data[i].TTL);
        printf("IPK: ");
        scanf("%f", &data[i].IPK);
    }

    // Pencarian data berdasarkan NIM
    int key;
    printf("\nMasukkan NIM yang ingin dicari: ");
    scanf("%d", &key);

    // Pencarian menggunakan sequential search
    int seqResult = sequentialSearch(data, n, key);
    if (seqResult != -1) {
        printf("\nSequential Search: Data ditemukan pada indeks %d\n", seqResult);
        printf("Nama: %s\n", data[seqResult].Nama);
        printf("TTL: %s\n", data[seqResult].TTL);
        printf("IPK: %.2f\n", data[seqResult].IPK);
    } else {
        printf("\nSequential Search: Data tidak ditemukan\n");
    }

    // Pencarian menggunakan binary search (data harus terurut berdasarkan NIM)
    int binaryResult = binarySearch(data, 0, n - 1, key);
    if (binaryResult != -1) {
        printf("\nBinary Search: Data ditemukan pada indeks %d\n", binaryResult);
        printf("Nama: %s\n", data[binaryResult].Nama);
        printf("TTL: %s\n", data[binaryResult].TTL);
        printf("IPK: %.2f\n", data[binaryResult].IPK);
    } else {
        printf("\nBinary Search: Data tidak ditemukan\n");
    }

    return 0;
}
