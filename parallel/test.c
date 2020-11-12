#include <stdio.h>
#include <omp.h>

int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10] = {};
    int i;
    
    #pragma omp parallel for shared(i,a,b)
        for( i = 0; i < 10; i++ ) {
               b[i] = a[i];
                printf("i=%d\n",i);
        }

    printf("i=%d\n",i);
    
    for( i = 0; i < 10; i++ ) {
            printf("b[%d] = %d\n", i, b[i]);
    }

    return 0;
    
}
