#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float *inchp;
    float *cmp;
} unit;


void main() {
    unit length;

    length.inchp=malloc(sizeof(float));
    length.cmp=malloc(sizeof(float));
    
    printf("KONVERSI INCH KE CM\n");
    printf("inch\t: ");
    scanf("%f", &length.inchp);
    *length.cmp=(*length.inchp)*2.54;
    printf("cm\t: %.2f", length.cmp);
}