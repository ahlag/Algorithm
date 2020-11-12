#include <stdio.h>
#include <omp.h>

int main() {
    
    int a = 0, i = 0;
    
#pragma omp parallel num_threads(4)
    {
        #pragma omp for
        for(i=0;i<10;i++) {
            // printf("no order, i = %2d  \n",i);
            printf("no order, i = %2d  Thread no. = %d,\n",i,omp_get_thread_num());
        }
        
        printf("\n\n");
        
        #pragma omp for ordered
        for(i=0;i<10;i++) {
            #pragma omp ordered
            printf(" ordered, i = %2d  Thread no. = %d,\n",i,omp_get_thread_num());
        }


 
    }
    return 0;
}
