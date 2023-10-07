#include <stdio.h> 

int main(void) { 
    int numbers[10]; 
    int count = 10; 
    long sum = 0L; 
    float average = 0.0f;

    printf("\n Masukkanlah 10 Angka:\n"); 
    for(int i = 0; i < count; i ++) 
    { 
        printf("%2d> ",i+1); 
        scanf("%d", &numbers[i]); /* Read a number */ 
        sum += numbers[i]; /* Jumlahkan setiap elemen */ 
    }

    average = (float)sum/count; /* Hitung rata-rata */ 
    printf("\n Rata-rata dari sepuluh Angka yang dimasukkan: %f\n", average); 
    return 0; 
}