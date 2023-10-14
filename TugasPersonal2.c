#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Month {
    char name[20];
};

int countVowels(char *str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'i' || str[i] == 'u' || str[i] == 'e' || str[i] == 'o' || str[i] == 'A' || str[i] == 'I' || str[i] == 'U' || str[i] == 'E' || str[i] == 'O') {
            count++;
        }
    }
    return count;
}

int main() {
    struct Month months[12] = {{"January"}, {"February"}, {"March"}, {"April"}, {"May"}, {"June"}, {"July"}, {"August"}, {"September"}, {"October"}, {"November"}, {"December"}};

    char input;
    int validInput = 0;
    int found = 0;

    printf("=======================================\n");
    printf("===== Program Hitung Huruf V & C ======\n");
    printf("=======================================\n");

    do {
        printf("\nMasukkan huruf (A-Z atau a-z): ");
        scanf(" %c", &input);

        if (!isalpha(input)) {
            printf("Input harus berupa huruf.\n");
        } else {
            validInput = 1;
            input = toupper(input);
            printf("Bulan yang dimulai dengan huruf %c adalah: \n", input);
            for (int i = 0; i < 12; i++) {
                if (months[i].name[0] == input) {
                    printf("%d. %s\n", i + 1, months[i].name);
                    found = 1;
                }
            }

            if (!found) {
                printf("Tidak ada bulan yang dimulai dengan huruf %c.\n", input);
                validInput = 0;
            }
        }
    } while (!validInput);

    int selectedMonthIndex;
    do {
        printf("Masukkan nomor bulan yang dipilih: ");
        scanf("%d", &selectedMonthIndex);

        if (selectedMonthIndex < 1 || selectedMonthIndex > 12) {
            printf("Nomor bulan tidak valid. Silakan coba lagi.\n");
        }

    } while (selectedMonthIndex < 1 || selectedMonthIndex > 12);

    char selectedMonth[20];
    strcpy(selectedMonth, months[selectedMonthIndex - 1].name);

    int vowels = countVowels(selectedMonth);
    int nonVowels = strlen(selectedMonth) - vowels;

    printf("Jumlah vokal: %d\n", vowels);
    printf("Jumlah non-vokal: %d\n", nonVowels);

    return 0;
}
