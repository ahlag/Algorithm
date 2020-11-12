#include <stdio.h>
#include <omp.h>

int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10] = {0,0,0,0,0,0,0,0,0,0};
    int i;
    
    #pragma omp parallel num_threads(2)
    {
        #pragma omp for
        for( i = 0; i < 10; i++ ) {
            b[i] = a[i];
            
            printf("i=%d, Thread no. = %d, No. of Threads = %d\n", i, omp_get_thread_num(), omp_get_num_threads());
        }
    }
    
    for( i = 0; i < 10; i++ ) {
        printf("b[%d] = %2d \n", i, b[i] );
    }
    
}
