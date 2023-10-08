#include <stdio.h>

// Menggunakan typedef untuk memberi alias pada struct
typedef struct {
    int x;
    int y;
} Point;

int main() {
    // Membuat objek titik
    Point p1;
    
    // Mengisi nilai koordinat
    p1.x = 5;
    p1.y = 10;
    
    // Menampilkan koordinat titik
    printf("Koordinat Titik: (%d, %d)\n", p1.x, p1.y);
    
    return 0;
}
