#include <stdio.h>
#include <stdlib.h>

void main() {
    char nim[10], name[20];
    int quiz, mid, final;
    float score;

    printf("NIM  : ");
    scanf("%s", &nim);
    printf("Nama : ");
    scanf(" %[^\n]s", &name);
    printf("Nilai Kuis :");
    scanf("%d", &quiz);
    printf("Nilai UTS  :");
    scanf("%d", &mid);
    printf("Nilai UAS  :");
    scanf("%d", &final);

    score = 0.2*quiz+0.3*mid+0.5*final;
    system("cls");

    printf("NIM\t: %s", nim);
    printf("\nNama\t: %s", name);
    printf("\nNilai");
    printf("\n   Kuis\t: %d", quiz);
    printf("\n   UTS\t: %d", mid);
    printf("\n   UAS\t: %d", final);
    printf("\n   Akhir: %.2f", score);
    getch();
}