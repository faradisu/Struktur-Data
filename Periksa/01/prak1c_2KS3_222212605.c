#include <stdio.h>

int main() 
{
    int umur;
    printf("Masukkan Umur: "); scanf("%d", &umur);
    printf("\n");

    int lilin[umur];
    printf("Masukkan tinggi setiap lilin  \n");
    for (int i = 0; i < umur; i++) {
        printf("Tinggi Lilin ke-%d: ", i + 1); scanf("%d", &lilin[i]);
     
    }

    int lilin_tertinggi = 0;
    int jumlah_dipadamkan = 0;

    for (int i = 0; i < umur; i++) {
        if (lilin[i] > lilin_tertinggi) {
            lilin_tertinggi = lilin[i];
            jumlah_dipadamkan = 1;
        } else if (lilin[i] == lilin_tertinggi) {
            jumlah_dipadamkan++;
        }
    }
        printf("\n");
    printf("Jumlah lilin yang dapat dipadamkan: %d\n", jumlah_dipadamkan);

    return 0;
}