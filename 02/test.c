#include <stdio.h>

// membuat struct dengan typedef 
typedef struct Distance { 
    int feet; 
    float inch; 
} distances; 
 
void main() { 
    // menggunakan struct 
    distances dist1={5,3}, dist2={3,7}, sum;
    sum.feet=dist1.feet+dist2.feet;
    sum.inch=dist1.inch+dist2.inch;

    printf("Distance-1\n");
    printf("  feet: %d\n", dist1.feet);
    printf("  inch: %.2f\n", dist1.inch);
    printf("Distance-2\n");
    printf("  feet: %d\n", dist2.feet);
    printf("  inch: %.2f\n", dist2.inch);
    printf("SUM\n");
    printf("  feet: %d\n", sum.feet);
    printf("  inch: %.2f\n", sum.inch);
}