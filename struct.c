#include <stdio.h>

// Mendefinisikan struct untuk representasi titik dalam koordinat
struct Point {
    int x;
    int y;
};

int main() {
    // Membuat objek titik
    struct Point p1;
    
    // Mengisi nilai koordinat
    p1.x = 5;
    p1.y = 10;
    
    // Menampilkan koordinat titik
    printf("Koordinat Titik: (%d, %d)\n", p1.x, p1.y);
    
    return 0;
}
