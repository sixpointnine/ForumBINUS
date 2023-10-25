#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[10][20], int n) {
    int i, j;
    char temp[20];

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
}

int main() {
    char nama[10][20] = {"Fahmi Harahap", "Icha Nurlisa", "Agus Gumilang", "Zelda Zuraida", "Felix Halim", "Deddy Corbuizer", "Hassan Makmur", "Makmun Sukur", "Bella Christie", "Chelshe Love"};
    int n = 10;
    int i;
    printf("Sorting menggunakan metode Bubbleshort\n");
    printf("Sebelum pengurutan:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", nama[i]);
    }

    bubbleSort(nama, n);

    printf("\nSetelah pengurutan:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", nama[i]);
    }

    return 0;
}
