/*
	Nama  : Ridho Hamdani Putra
	NIM   : 23343052
	Prodi : Informatika (NK)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur Menu untuk linked list
typedef struct Menu {
    char nama[50];
    double harga;
    struct Menu* berikutnya;
} Menu;

// Fungsi untuk membuat Menu baru
Menu* buatMenu(char* nama, double harga) {
    Menu* MenuBaru = (Menu*)malloc(sizeof(Menu));
    strcpy(MenuBaru->nama, nama);
    MenuBaru->harga = harga;
    MenuBaru->berikutnya = NULL;
    return MenuBaru;
}

// Fungsi untuk menambah menu
void tambahMenu(Menu** awal, char* nama, double harga) {
    Menu* MenuBaru = buatMenu(nama, harga);
    MenuBaru->berikutnya = *awal;
    *awal = MenuBaru;
}

// Fungsi untuk mengedit menu
void editMenu(Menu* awal, char* namaLama, char* namaBaru, double hargaBaru) {
    Menu* sementara = awal;
    while (sementara != NULL) {
        if (strcmp(sementara->nama, namaLama) == 0) {
            strcpy(sementara->nama, namaBaru);
            sementara->harga = hargaBaru;
            return;
        }
        sementara = sementara->berikutnya;
    }
}

// Fungsi untuk menghapus menu
int hapusMenu(Menu** awal, char* nama) {
    Menu* sementara = *awal;
    Menu* prev = NULL;
    if (sementara != NULL && strcmp(sementara->nama, nama) == 0) {
        *awal = sementara->berikutnya;
        free(sementara);
        return 1;
    }
    while (sementara != NULL && strcmp(sementara->nama, nama) != 0) {
        prev = sementara;
        sementara = sementara->berikutnya;
    }
    if (sementara == NULL) return 0;
    prev->berikutnya = sementara->berikutnya;
    free(sementara);
    return 1; 
}

// Fungsi untuk menampilkan semua menu
void tampilkanMenu(Menu* awal) {
    Menu* sementara = awal;
    printf("+----+-------------------------------------------+-------------------+\n");
    printf("| No | %-40s | %-16s |\n", "Nama", "Harga");
    printf("+----+-------------------------------------------+-------------------+\n");
    int nomorUrut = 1;
    while (sementara != NULL) {
        printf("| %-2d | %-40s | Rp. %-12.2f |\n", nomorUrut, sementara->nama, sementara->harga);
        sementara = sementara->berikutnya;
        nomorUrut++;
    }
    printf("+----+-------------------------------------------+-------------------+\n");
}

// Fungsi untuk mengurutkan menu berdasarkan harga
void urutkanMenu(Menu* awal) {
    int tukar;
    Menu* petunjuk;
    Menu* petunjukAwal = NULL;
    if (awal == NULL) return;
    do {
        tukar = 0;
        petunjuk = awal;
        while (petunjuk->berikutnya != petunjukAwal) {
            if (petunjuk->harga > petunjuk->berikutnya->harga) {
                char sementaraNama[50];
                double sementaraHarga;
                strcpy(sementaraNama, petunjuk->nama);
                sementaraHarga = petunjuk->harga;
                strcpy(petunjuk->nama, petunjuk->berikutnya->nama);
                petunjuk->harga = petunjuk->berikutnya->harga;
                strcpy(petunjuk->berikutnya->nama, sementaraNama);
                petunjuk->berikutnya->harga = sementaraHarga;
                tukar = 1;
            }
            petunjuk = petunjuk->berikutnya;
        }
        petunjukAwal = petunjuk;
    } while (tukar);
}

// Fungsi untuk mencari menu
Menu* cariMenu(Menu* awal, char* nama) {
    Menu* sementara = awal;
    while (sementara != NULL) {
        if (strcmp(sementara->nama, nama) == 0) {
            return sementara;
        }
        sementara = sementara->berikutnya;
    }
    return NULL;
}

// Fungsi tampilan judul program
void judul() {
    printf("\n\t\t\t\t\t\t\t============================================\n");
    printf("\t\t\t\t\t\t\t||          Daftar Menu Warung Kopi       ||\n");
    printf("\t\t\t\t\t\t\t============================================\n");
    printf("\t\t\t\t\t\t\t||      Nama  : Ridho Hamdani Putra       ||\n");
    printf("\t\t\t\t\t\t\t||      NIM   : 23343052                  ||\n");
    printf("\t\t\t\t\t\t\t||      Prodi : Informatika (NK)          ||\n");
    printf("\t\t\t\t\t\t\t============================================\n");
}

// Fungsi utama
int main() {
    Menu* awal = NULL;
    int pilihan;
    char nama[50], namaLama[50];
    double harga;
    int hasilScan;

    system("cls");
    judul();
    
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Menu\n");
        printf("2. Edit Menu\n");
        printf("3. Hapus Menu\n");
        printf("4. Cari Menu\n");
        printf("5. Urutkan Menu berdasarkan Harga\n");
        printf("6. Tampilkan Semua Menu\n");
        printf("7. Keluar\n");
        printf("\nPilih (1-7): ");
        hasilScan = scanf("%d", &pilihan);
        while (getchar() != '\n'); // Clear input buffer
        
        if (hasilScan != 1 || pilihan < 1 || pilihan > 7) {
            printf("Pilihan tidak valid!\n");
            continue; // Meminta input ulang jika input tidak valid
        }

        switch (pilihan) {
            case 1:
                printf("Masukkan Nama: ");
                getchar();
                fgets(nama, sizeof(nama), stdin); 
                nama[strcspn(nama, "\n")] = 0;
                
                do {
                    printf("Masukkan Harga: ");
                    hasilScan = scanf("%lf", &harga);
                    while (getchar() != '\n'); // Clear input buffer
                    if (hasilScan != 1) {
                        printf("Input tidak valid. Masukkan angka.\n");
                    }
                } while (hasilScan != 1);
                
                tambahMenu(&awal, nama, harga);
                break;
            case 2:
                printf("Masukkan Nama Menu yang Ingin Diedit: ");
                getchar();
                fgets(namaLama, sizeof(namaLama), stdin);
                namaLama[strcspn(namaLama, "\n")] = 0;
                printf("Masukkan Nama Baru: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;

                do {
                    printf("Masukkan Harga Baru: ");
                    hasilScan = scanf("%lf", &harga);
                    while (getchar() != '\n'); // Clear input buffer
                    if (hasilScan != 1) {
                        printf("Input tidak valid. Masukkan angka.\n");
                    }
                } while (hasilScan != 1);

                editMenu(awal, namaLama, nama, harga);
                break;
            case 3:
                printf("Masukkan Nama Menu yang Ingin Dihapus: ");
                getchar();
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                int berhasil = hapusMenu(&awal, nama);
                if (berhasil) {
                    printf("Menu berhasil dihapus.\n");
                } else {
                    printf("Menu tidak ditemukan.\n");
                }
                break;
            case 4:
                printf("Masukkan Nama yang Dicari: ");
                getchar();
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                Menu* hasil = cariMenu(awal, nama);
                if (hasil != NULL) {
                    printf("Menu Ditemukan \nNama: %s, Harga: Rp. %.2f\n", hasil->nama, hasil->harga);
                } else {
                    printf("Menu Tidak Ditemukan.\n");
                }
                break;
            case 5:
                urutkanMenu(awal);
                printf("Menu berhasil diurutkan berdasarkan harga.\n");
                break;
            case 6:
                tampilkanMenu(awal);
                break;
            case 7:
                exit(0);
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (1);

    return 0;
}
