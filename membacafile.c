#include <stdio.h>

int main() {
    FILE *file;
    char isi[100]; //array untuk menyimpan karakter di file 
	
	//command untuk membuka file yang ingin dibuka 
	//ganti alamat file sesuai dengan lokasi file disimpan dan ubah '\' menjadi '/'
    file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Tidak dapat membuka file");//error msg jika file tidak ditemukan 
        return 1;
    }

    while (fgets(isi, sizeof(isi), file) != NULL) {
        printf("%s", isi);
    }

    fclose(file);
    return 0;
}
