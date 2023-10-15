#include <stdio.h>
#include <stdlib.h>

// KODE A (Static Memory Allocation)
int main_static() {
    int SIZE = 9;
    int data[SIZE]; // Alokasi memori statis
    printf("KODE A (Static Memory Allocation):\n");

    // Mengisi data ke dalam array
    for (int i = 0; i < SIZE; i++) {
        data[i] = i * 2;
    }

    // Menampilkan data
    printf("Data: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Memori statis tidak perlu di-"free"

    return 0;
}

// KODE B (Dynamic Memory Allocation)
int main_dynamic() {
    int SIZE = 9;
    int *data = (int *)malloc(SIZE * sizeof(int)); // Alokasi memori dinamis
    printf("KODE B (Dynamic Memory Allocation):\n");

    // Mengisi data ke dalam array
    for (int i = 0; i < SIZE; i++) {
        data[i] = i * 2;
    }

    // Menampilkan data
    printf("Data: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Menggunakan "free" untuk melepaskan memori yang dialokasikan di heap
    free(data);

    return 0;
}

int main() {
    main_static(); // Jalankan KODE A
    main_dynamic(); // Jalankan KODE B

    return 0;
}
