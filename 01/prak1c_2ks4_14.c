#include <stdio.h>

void main() {
    int age, max, candle, count;

    printf("Umur: ");
    scanf("%d", &age);

    for (int i = 0; i < age; i++) {
        printf("Lilin-%d: ", i+1);
        scanf("%d", &candle);

        if (i==0 || candle>max) {
            max = candle;
            count=1;
        } else if (candle==max) {
            count++;
        }
    }
    
    printf("Jumlah lilin yang dapat dipadamkan %d", count);
    getch();
}