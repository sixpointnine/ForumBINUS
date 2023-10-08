#include <stdio.h>
#include <string.h>

enum Kategori
{
    Fiksi,
    Teks,
    Sejarah,
    Novel,
};

enum Penerbit
{
    Gramedia,
    Elexmedia,
    Andi_Offset,
    Pustaka,
};

struct Buku
{
    char ISBN[20];
    char judul[100];
    char pengarang[50];
    int tahun_terbit;
    enum Penerbit penerbit;
    enum Kategori kategori;
    int jumlah_tersedia;
};

void tampilkanBuku(struct Buku buku)
{
    printf("ISBN: %s\n", buku.ISBN);
    printf("Judul: %s\n", buku.judul);
    printf("Pengarang: %s\n", buku.pengarang);
    printf("Tahun Terbit: %d\n", buku.tahun_terbit);
    printf("Jumlah Tersedia: %d\n", buku.jumlah_tersedia);

    switch (buku.penerbit)
    {
    case Gramedia:
        printf("Penerbit: Gramedia\n");
        break;
    case Elexmedia:
        printf("Penerbit: Elexmedia\n");
        break;
    case Andi_Offset:
        printf("Penerbit: Andi Offset\n");
        break;
    case Pustaka:
        printf("Penerbit: Pustaka\n");
        break;
    }

    switch (buku.kategori)
    {
    case Fiksi:
        printf("Kategori: Fiksi\n");
        break;
    case Teks:
        printf("Kategori: Teks\n");
        break;
    case Sejarah:
        printf("Kategori: Sejarah\n");
        break;
    case Novel:
        printf("Kategori: Novel\n");
        break;
    }

    printf("\n");
}

void tambahBuku(struct Buku *perpustakaan, int *jumlah_buku)
{
    if (*jumlah_buku < 100)
    {
        struct Buku buku;

        printf("Masukkan ISBN: ");
        scanf("%s", buku.ISBN);
        printf("Masukkan judul: ");
        scanf("%s", buku.judul);
        printf("Masukkan pengarang: ");
        scanf("%s", buku.pengarang);
        printf("Masukkan tahun terbit: ");
        scanf("%d", &buku.tahun_terbit);
        printf("Masukkan jumlah buku yang tersedia: ");
        scanf("%d", &buku.jumlah_tersedia);

        printf("Pilih penerbit:\n");
        printf("1. Gramedia\n");
        printf("2. Elexmedia\n");
        printf("3. Andi Offset\n");
        printf("4. Pustaka\n");
        printf("Pilihan (1/2/3/4): ");
        int penerbit;
        scanf("%d", &penerbit);
        buku.penerbit = penerbit - 1;

        printf("Pilih kategori:\n");
        printf("1. Fiksi\n");
        printf("2. Teks\n");
        printf("3. Sejarah\n");
        printf("4. Novel\n");
        printf("Pilihan (1/2/3/4): ");
        int kategori;
        scanf("%d", &kategori);
        buku.kategori = kategori - 1;

        perpustakaan[*jumlah_buku] = buku;
        (*jumlah_buku)++;
        printf("Buku berhasil ditambahkan.\n");
    }
    else
    {
        printf("Perpustakaan sudah penuh.\n");
    }
}

void hapusBuku(struct Buku *perpustakaan, int *jumlah_buku)
{
    if (*jumlah_buku == 0)
    {
        printf("Perpustakaan kosong.\n");
        return;
    }

    char ISBN_hapus[20];
    printf("Masukkan ISBN buku yang akan dihapus: ");
    scanf("%s", ISBN_hapus);

    int indeks_hapus = -1;
    for (int i = 0; i < *jumlah_buku; i++)
    {
        if (strcmp(perpustakaan[i].ISBN, ISBN_hapus) == 0)
        {
            indeks_hapus = i;
            break;
        }
    }

    if (indeks_hapus != -1)
    {
        for (int i = indeks_hapus; i < *jumlah_buku - 1; i++)
        {
            perpustakaan[i] = perpustakaan[i + 1];
        }
        (*jumlah_buku)--;
        printf("Buku dengan ISBN %s telah dihapus.\n", ISBN_hapus);
    }
    else
    {
        printf("Buku dengan ISBN %s tidak ditemukan.\n", ISBN_hapus);
    }
}

void transaksiBuku(struct Buku *perpustakaan, int jumlah_buku)
{
    if (jumlah_buku == 0)
    {
        printf("Perpustakaan kosong.\n");
        return;
    }

    char ISBN_transaksi[20];
    printf("Masukkan ISBN buku yang akan dipinjam/mengembalikan: ");
    scanf("%s", ISBN_transaksi);

    int indeks_transaksi = -1;
    for (int i = 0; i < jumlah_buku; i++)
    {
        if (strcmp(perpustakaan[i].ISBN, ISBN_transaksi) == 0)
        {
            indeks_transaksi = i;
            break;
        }
    }

    if (indeks_transaksi != -1)
    {
        int pilihan;
        printf("Pilih tindakan:\n");
        printf("1. Pinjam buku\n");
        printf("2. Kembalikan buku\n");
        printf("Pilihan (1/2): ");
        scanf("%d", &pilihan);

        if (pilihan == 1)
        {
            if (perpustakaan[indeks_transaksi].jumlah_tersedia > 0)
            {
                perpustakaan[indeks_transaksi].jumlah_tersedia--;
                printf("Buku dengan ISBN %s berhasil dipinjam.\n", ISBN_transaksi);
            }
            else
            {
                printf("Maaf, buku tidak tersedia saat ini.\n");
            }
        }
        else if (pilihan == 2)
        {
            perpustakaan[indeks_transaksi].jumlah_tersedia++;
            printf("Buku dengan ISBN %s berhasil dikembalikan.\n", ISBN_transaksi);
        }
        else
        {
            printf("Pilihan tidak valid.\n");
        }
    }
    else
    {
        printf("Buku dengan ISBN %s tidak ditemukan.\n", ISBN_transaksi);
    }
}

void tampilkanPerpustakaan(struct Buku *perpustakaan, int jumlah_buku)
{
    for (int i = 0; i < jumlah_buku; i++)
    {
        printf("Buku ke-%d:\n", i + 1);
        tampilkanBuku(perpustakaan[i]);
    }
}

int main()
{
    struct Buku perpustakaan[100];
    int jumlah_buku = 0;
    int pilihan;

    do
    {
        printf("Menu:\n");
        printf("1. Tambah Buku\n");
        printf("2. Tampilkan Perpustakaan\n");
        printf("3. Hapus Buku\n");
        printf("4. Transaksi (Meminjam/Mengembalikan)\n");
        printf("5. Keluar\n");
        printf("Pilih menu (1/2/3/4/5): ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            tambahBuku(perpustakaan, &jumlah_buku);
            break;
        case 2:
            tampilkanPerpustakaan(perpustakaan, jumlah_buku);
            break;
        case 3:
            hapusBuku(perpustakaan, &jumlah_buku);
            break;
        case 4:
            transaksiBuku(perpustakaan, jumlah_buku);
            break;
        case 5:
            printf("Terima kasih. Sampai jumpa!\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);

    return 0;
}
