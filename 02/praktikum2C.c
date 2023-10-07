#include <stdio.h> 
 
void pifloat() { 
   float pi = 22.0/7.0; 
   printf("=== FLOAT ===\n"); 
   printf("%.15lf\n", pi); 
   printf("%lf\n", pi); 
} 
 
void pidouble() { 
   double pi = 22.0/7.0; 
   printf("=== DOUBLE ===\n"); 
   printf("%.15lf\n", pi); 
   printf("%lf\n", pi); 
} 
 
int main() { 
   pifloat(); 
   printf("\n"); 
   pidouble(); 
 
   return 0; 
}