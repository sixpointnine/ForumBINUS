#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int NIM,Nilai,Tugas,UTS,UAS;
    char Nama[100];
    int NilaiTugas,NilaiUAS,NilaiUTS,NilaiAkhir;
    char Grade[3];
    printf("*Program Grading Score Mahasiswa*\n");
    printf("Masukan nama: ");
    scanf("%s",Nama);
    printf("Masukan NIM: ");
    scanf("%d",&NIM);
    printf("\n-------------------------\n");
    printf("Masukan nilai tugas: ");
    scanf("%d",&Tugas);
    printf("Masukan nilai UTS: ");
    scanf("%d",&UTS);
    printf("Masukan nilai UAS: ");
    scanf("%d",&UAS);
    printf("\n-------------------------\n");

    NilaiTugas=Tugas*40/100;
    NilaiUTS=UTS*30/100;
    NilaiUAS=UAS*30/100;
    
    NilaiAkhir=NilaiTugas+NilaiUTS+NilaiUAS;
    
    printf("*SUMMARY*");
    printf("Nama Mahasiswa: ");
    printf("%s\n", Nama);
    printf("NIM Mahasiswa: ");
    printf("%d\n", NIM);
    printf("Nilai Akhir Mahasiswa: ");
    printf("%d\n", NilaiAkhir);
    
    if (NilaiAkhir >= 90) {
        strcpy(Grade, "A");
    } 
	else if (NilaiAkhir >= 85) {
        strcpy(Grade, "A-");
    }
	 else if (NilaiAkhir >= 80) {
        strcpy(Grade, "B+");
    }
	 else if (NilaiAkhir >= 75) {
        strcpy(Grade, "B");
    }
	 else if (NilaiAkhir >= 70) {
        strcpy(Grade, "B-");
    }
	 else if (NilaiAkhir >= 65) {
        strcpy(Grade, "C");
    }
	 else if (NilaiAkhir >= 50) {
        strcpy(Grade, "D");
    }
	 else {
        strcpy(Grade, "E");
    }
    printf("Grade: %s\n", Grade);

    
return 0;
}
