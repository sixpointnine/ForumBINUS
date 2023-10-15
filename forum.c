#include <stdio.h>

struct Mahasiswa {
    int ID;
    char Nama[50];
    char Prodi[50];
    float GPA;
};

int main() {
    struct Mahasiswa mahasiswa;
    printf("Masukkan ID Mahasiswa : ");
    scanf("%d", &mahasiswa.ID);
    getchar();
    printf("Masukkan Nama Mahasiswa : ");
    scanf("%[^\n]s", mahasiswa.Nama);
    getchar(); 
    printf("Masukkan Prodi Mahasiswa : ");
    scanf("%[^\n]s", mahasiswa.Prodi);
    printf("Masukkan GPA Mahasiswa : ");
    scanf("%f", &mahasiswa.GPA); 
    
    printf("\nID Mahasiswa : %d\n", mahasiswa.ID);
    printf("Nama Mahasiswa : %s\n", mahasiswa.Nama);
    printf("Prodi Mahasiswa : %s\n", mahasiswa.Prodi);
    printf("GPA Mahasiswa : %.2f\n", mahasiswa.GPA);

    return 0;
}
