#include <stdio.h>
#include <stdlib.h>

void main() {
    int row, column, *matrix;

    printf("Baris: ");
    scanf("%d", &row);
    printf("Kolom: ");
    scanf("%d", &column);

    matrix=malloc(row*column*sizeof(int));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("[%d, %d]: ", i+1, j+1);
            scanf("%d", matrix+(i*column+j));
        }
    }

    printf("\nTampilkan matriks:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", *(matrix+(i*column+j)));
        }
        printf("\n");
    }
}
