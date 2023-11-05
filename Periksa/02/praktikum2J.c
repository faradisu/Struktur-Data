#include <stdio.h>

//membuat struct dengan typedef
typedef struct Distance{
    int feet;
    float inch;
}distances;

void main () {
    //menggunakan struct
    distances dist1, dist2, sum;
    dist1.feet = 25;
    dist1.inch = 6.12;
    dist2.feet = 12;
    dist2.inch = 9.47;

    //total distance
    sum.feet = dist1.feet + dist2.feet;
    sum.inch = dist1.inch + dist2.inch;

    //karena 1 feet = 12 inch, maka setiap 12 inch akan dikonversi menjadi 1 feet
    while (sum.inch >= 12.0)
    {
        sum.inch -=12.0;
        sum.feet++;
    }

    //display
    printf("Menggunakan Typedef dalam Structure\n");
    printf("-----------------------------------\n");
    printf("Distance 1\t: %d feet %.2f inch\n", dist1.feet, dist1.inch);
    printf("Distance 2\t: %d feet %.2f inch\n", dist2.feet, dist2.inch);
    printf("Total Distance\t: %d feet %.2f inch\n", sum.feet, sum.inch);

}
