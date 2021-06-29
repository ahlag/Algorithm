#include <stdio.h>

int main() {
    
    int a = 2, b = 4, c;
    
    asm("   movl    %1, %%eax;" //eax = a
        "   addl    %2, %%eax;" //eax += b
        "   movl    %%eax, %0;" //c = eax
        : "=r" (c)              /* output operands */
        : "r" (a), "r" (b)      /* input operands */
        : "%eax"                /* clobbered operands */
        );
    
    printf("%d + %d = %d \n", a, b, c);
    
    return 0;
}


