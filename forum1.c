#include <stdio.h>
#include <string.h>

int main() {
    //declare i/o
    char jenisBensin[10];
    double konsumsiBahanBakar = 0.0;
    double bensinAwal, bensinAkhir, jarakTempuh;
    char modeMenyupir[20];
    
    //Tampilan awal
    printf("\nPenghitung Efisiensi Bahan Bakar Pertamax dan Pertalite");
    printf("\n-------------------------------------------------------\n\n");
    printf("Pilih jenis Bahan Bakar  (Pertamax/Pertalite): ");
    scanf("%s", jenisBensin);

    if (strcmp(jenisBensin, "Pertamax") == 0 || strcmp(jenisBensin,"pertamax")==0) {
        printf("Pilih cara berkendara (konstan/stop&go): ");
        scanf("%s", modeMenyupir);

        if (strcmp(modeMenyupir, "konstan") == 0) {
            konsumsiBahanBakar = 15.0;
        } else if (strcmp(modeMenyupir, "stop&go") == 0) {
            konsumsiBahanBakar = 10.0;
        } else {
            printf("Cara berkendara tidak valid.\n");
            return 1;
        }
    } else if (strcmp(jenisBensin, "Pertalite") == 0 || strcmp(jenisBensin,"pertalite")==0) {
        printf("Pilih cara berkendara  (konstan/stop&go): ");
        scanf("%s", modeMenyupir);

        if (strcmp(modeMenyupir, "konstan") == 0) {
            konsumsiBahanBakar = 12.0;
        } else if (strcmp(modeMenyupir, "stop&go") == 0) {
            konsumsiBahanBakar = 8.0;
        } else {
            printf("Cara berkendara tidak valid.\n");
            return 1;
        }
    } else {
        printf("Jenis bahan bakar tidak valid.\n");
        return 1;
    }

    printf("Masukkan jumlah awal bahan bakar (liter): ");
    scanf("%lf", &bensinAwal);

    printf("Masukkan jarak yang ditempuh (km): \n");
    scanf("%lf", &jarakTempuh);

    double bensinDibutuhkan = jarakTempuh / konsumsiBahanBakar;
    bensinAkhir = bensinAwal - bensinDibutuhkan;

    if (bensinAkhir <= 0) {
        printf("Anda kehabisan bensin di tengah perjalanan!\n");
    } else {
        printf("Jumlah bahan bakar yang dibutuhkan: %.2lf liter\n", bensinDibutuhkan);
        printf("Jumlah bahan bakar akhir: %.2lf liter\n", bensinAkhir);
    }

    return 0;
}

