#include <stdio.h>

int circumf(int l, int w);
int area(int l, int w);

void main() {
    int width, length;
    
    printf("-Program Persegi Panjang-\n");
    printf("Panjang\t: ");
    scanf("%d", &length);
    printf("Lebar\t: ");
    scanf("%d", &width);
    printf("Keliling: %d\n", circumf(length, width));
    printf("Luas\t: %d", area(length, width));
    getch();
}

int circumf(int l, int w) {
    return 2*(l+w);
}

int area(int l, int w) {
    return l*w;
}