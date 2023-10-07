#include <stdio.h>

int main() {
    struct complex { 
        int imag; 
        float real; 
    }; 
    
    struct number { 
        struct complex comp; 
        int integers; 
    } num1, num2;

    num1.integers = 12; 
    num1.comp.real = 44.12; 
    num2.comp.imag = 11;

    printf("%d\n", num1.integers);
    printf("%.2f\n", num1.comp.real);
    printf("%d", num2.comp.imag);

    return 0;
}