// Program penghitung matriks otomatis dengan penyesuaian baris dan kolom yang fleksibel 
#include <stdio.h>
#include <stdbool.h>

int main() {
    int m, n, p, q;

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("-=- Program Penghitung Matriks -=-\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

    // Meminta pengguna untuk ukuran matriks pertama
    printf("\nMasukkan jumlah baris matriks pertama: ");
    while (true) {
        if (scanf("%d", &m) == 1) {
            break;
        } else {
            printf("Input tidak valid. Masukkan angka: ");
            while (getchar() != '\n'); // Menghapus karakter yang tersisa di buffer
        }
    }

    printf("Masukkan jumlah kolom matriks pertama: ");
    while (true) {
        if (scanf("%d", &n) == 1) {
            break;
        } else {
            printf("Input tidak valid. Masukkan angka: ");
            while (getchar() != '\n'); // Menghapus karakter yang tersisa di buffer
        }
    }

    // Meminta pengguna untuk ukuran matriks kedua
    printf("Masukkan jumlah baris matriks kedua: ");
    while (true) {
        if (scanf("%d", &p) == 1) {
            break;
        } else {
            printf("Input tidak valid. Masukkan angka: ");
            while (getchar() != '\n'); // Menghapus karakter yang tersisa di buffer
        }
    }

    printf("Masukkan jumlah kolom matriks kedua: ");
    while (true) {
        if (scanf("%d", &q) == 1) {
            break;
        } else {
            printf("Input tidak valid. Masukkan angka: ");
            while (getchar() != '\n'); // Menghapus karakter yang tersisa di buffer
        }
    }

    // Periksa apakah perkalian matriks dapat dilakukan
    if (n != p) {
        printf("Perkalian matriks tidak dapat dilakukan. Kolom matriks pertama harus sama dengan baris matriks kedua.\n");
        return 1; // Keluar dengan kode kesalahan
    }

      // Inisialisasi matriks pertama dan matriks kedua
    int mat1[m][n], mat2[p][q];

    // Memasukkan elemen-elemen matriks pertama
    printf("Masukkan elemen-elemen matriks pertama:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Memasukkan elemen-elemen matriks kedua
    printf("Masukkan elemen-elemen matriks kedua:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Matriks hasil perkalian
    int hasil[m][q];

    // Menghitung perkalian matriks
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < n; k++) {
                hasil[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Menampilkan hasil perkalian matriks
    printf("Hasil perkalian matriks:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", hasil[i][j]);
        }
        printf("\n");
    }
     printf("\nTerimakasih.");
    
    return 0;
}

