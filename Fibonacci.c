#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Fungsi untuk membersihkan layar konsol
void clearScreen() {
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(_unix_) || defined(__unix) || \
    (defined(_APPLE) && defined(__MACH_))
    system("clear");
#else
#error "OS not supported."
#endif
}

// Fungsi iteratif untuk menghitung bilangan Fibonacci ke-n
unsigned long long int fibonacciIteratif(int n) {
    if (n <= 1) {
        return n;
    }
    unsigned long long int angkaSebelumnya = 0;
    unsigned long long int angkaSekarang = 1;

    for (int i = 2; i <= n; i++) {
        unsigned long long int angkaSelanjutnya = angkaSebelumnya + angkaSekarang;
        angkaSebelumnya = angkaSekarang;
        angkaSekarang = angkaSelanjutnya;
    }
    return angkaSekarang;
}

// Fungsi rekursif untuk menghitung bilangan Fibonacci ke-n
unsigned long long int fibonacciRekursif(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRekursif(n - 1) + fibonacciRekursif(n - 2);
}

// Fungsi untuk memeriksa apakah input adalah angka yang valid
int cekAngka(char *nilai) {
    size_t panjang = strlen(nilai);
    for (int i = 0; i < panjang; i++) {
        if (!isdigit(nilai[i]) && !isspace(nilai[i])) {
            return 0;
        }
    }
    return 1;
}

// Fungsi untuk mengambil pilihan menu dari user
int getPilihanMenu() {
    int pilihan;
    char inputSementara[100];

    do {
        printf("Masukkan pilihan menu: ");
        if (fgets(inputSementara, sizeof(inputSementara), stdin) != NULL) {
            if (cekAngka(inputSementara) && sscanf(inputSementara, "%d", &pilihan) == 1) {
                if (pilihan >= 1 && pilihan <= 2) {
                    break;
                } else {
                    printf("----------------------------------------------\n");
                    printf("     MASUKKAN PILIHAN MENU YANG VALID\n");
                    printf("----------------------------------------------\n");
                }
            } else {
                printf("----------------------------------------------\n");
                printf("     MASUKKAN PILIHAN MENU YANG VALID\n");
                printf("----------------------------------------------\n");
            }
        }
    } while (1);

    return pilihan;
}

// Fungsi untuk meminta input angka dengan pesan error jika bukan angka
int getInputAngka() {
    char inputSementara[100];
    int n;

    while (1) {
        printf("\nIngin mencari bilangan fibonacci ke berapa? ");
        if (fgets(inputSementara, sizeof(inputSementara), stdin) != NULL) {
            if (cekAngka(inputSementara) && sscanf(inputSementara, "%d", &n) == 1) {
                return n;
            } else {
                printf("-----------------------------------------------\n");
                printf("             INPUT HARUS BERUPA ANGKA \n");
                printf("-----------------------------------------------\n");
            }
        } else {
            return 1;
        }
    }
}
int main() {
    int pilihanMenu;
    int n;
    clock_t mulai, berakhir;
    double waktuEksekusi;

    do {
        clearScreen();
      
        // Header
        printf("=============================================\n");
        printf("        PROGRAM MENCARI BIL. FIBONACCI KE N      \n");
        printf("=============================================\n");
      
        // Menu
        printf("Menu:\n");
        printf("1. Mulai program\n");
        printf("2. Keluar\n");

        pilihanMenu = getPilihanMenu(); // Mengambil pilihan menu dari user

        switch (pilihanMenu) {
            case 1:
                n = getInputAngka(); // Mengambil input angka Fibonacci
                
                // Mengukur waktu eksekusi untuk fungsi iteratif
                mulai = clock();
                printf("\nBilangan Fibonacci ke %d (iteratif): %llu\n", n, fibonacciIteratif(n));
                berakhir = clock();
                waktuEksekusi = ((double) (berakhir - mulai)) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan (iteratif): %f detik\n", waktuEksekusi);

                // Mengukur waktu eksekusi untuk fungsi rekursif
                mulai = clock();
                printf("\nBilangan Fibonacci ke %d (rekursif): %llu\n", n, fibonacciRekursif(n));
                berakhir = clock();
                waktuEksekusi = ((double) (berakhir - mulai)) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan (rekursif): %f detik\n", waktuEksekusi);

                printf("\nTekan 'Enter' untuk melanjutkan...");
                while (getchar() != '\n');
                break;

            case 2:
                printf("Sampai jumpa pada program selanjutnya!\n");
                break;

            default:
                printf("----------------------------------------------\n");
                printf("      PILIHAN MENU TIDAK VALID \n");
                printf("----------------------------------------------\n");
                break;
        }
        
    } while (pilihanMenu != 2);

    return 0;
}
