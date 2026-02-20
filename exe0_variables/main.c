#include "stdio.h"



void foo(int *ptr_a) {
    *ptr_a = *ptr_a + 1; 
}

void main(void) {
    int a = 0; 
    int b = 0;
    while (1) {
        foo(&a);
        
        if (a > 5) {
            b = 1;
        }
        printf("Valor de a: %d | Valor de b: %d\n", a, b);

        if (a < 10){
            break;
        }
    }
}
