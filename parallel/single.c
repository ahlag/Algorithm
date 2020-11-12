#include <stdio.h>
#include <omp.h>

int main( ) {
    
    int a = 0, i;
    
    #pragma omp parallel num_threads(5)
    {

        #pragma omp for ordered
        for( i = 0; i < 10; i++) {
            #pragma omp ordered
            printf(" ordered, i = %d t = %d \n", i, omp_get_thread_num());
        }
        /*
        #pragma omp for
        for( i = 0; i < 10; i++) {
            printf(" no ordered, i = %2d  \n", i);
        }
        */
    }
    
    #pragma omp parallel num_threads(5)
    {
        #pragma omp for
        for( i = 0; i < 10; i++) {
            printf(" no ordered, i = %d t = %d \n", i, omp_get_thread_num());
        }
        
    }

    return 0;
}
