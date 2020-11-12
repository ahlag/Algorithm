#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define n 6

int main() {
    
    int i;
    int a, b[n];
    
#pragma omp parallel shared(a,b) private(i)
{
    #pragma omp single
    {
        a = 10;
        printf("Single construct executed by thread %d\n",omp_get_thread_num());
    }
    /* A barrier is automatically inserted here */
    
    #pragma omp for
    for (i=0; i<n; i++) {
        b[i] = a;
        printf("b[%d] = %d & substituted by thread %d\n",i,b[i],omp_get_thread_num());
    }
        
}/*-- End of parallel region --*/
    
    printf("After the parallel region:\n");
    for (i=0; i<n; i++)
        printf("b[%d] = %d\n",i,b[i]);
    
    return 0;
}
