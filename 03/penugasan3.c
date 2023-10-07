#include <stdio.h>

typedef struct {
    char name[30];
    char nim[10];
    int age;
    char class[4];
} student;


void main() {
    student mhs;
    student *mhsp=&mhs;

    printf("Nama\t: ");
    scanf(" %[^\n]s", &mhsp->name);
    printf("NIM\t: ");
    scanf("%s", &mhsp->nim);
    printf("Umur\t: ");
    scanf("%d", &mhsp->age);
    printf("Kelas\t: ");
    scanf("%s", &mhsp->class);

    printf("\nData Mahasiswa\n");
    printf("Nama\t: %s\n", mhsp->name);
    printf("NIM\t: %s\n", mhsp->nim);
    printf("Umur\t: %d\n", mhsp->age);
    printf("Kelas\t: %s", mhsp->class);
}