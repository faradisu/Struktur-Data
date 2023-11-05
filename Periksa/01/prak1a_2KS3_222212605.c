#include <stdio.h>

float nilai(float kuis, float uts, float uas);
int main()
{
    int nim;
    float kuis,uts,uas,akhir;
    char nama[25];
    printf("NIM : ");scanf("%d", &nim);
    printf("Nama : ");scanf(" %[^\n]s", &nama);
    printf("Nilai Kuis : ");scanf("%f", &kuis);
    printf("Nilai UTS : ");scanf("%f", &uts);
    printf("Nilai UAS : ");scanf("%f", &uas);
    printf("\n");

    akhir = nilai(kuis,uts,uas);

    printf("NIM = %d \n", nim);
    printf("Nama = %s \n", nama); 
    printf("Nilai Kuis = %.2f \n", kuis);
    printf("Nilai UTS = %.2f \n", uts);
    printf("Nilai UAS = %.2f \n", uas);
    printf("\n");
    printf("Nilai Akhir = %.2f \n", akhir);
    printf("\n");
    return 0;
}   

    float nilai(float kuis, float uts, float uas)
{
    float nilai_akhir;
    nilai_akhir = (0.2*kuis) + (0.3*uts) + (0.5*uas);
    return nilai_akhir;

}