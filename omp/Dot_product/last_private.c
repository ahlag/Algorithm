#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define n 6

int main() {
    
    int i;
    int a;
    
#pragma omp parallel for private(i) lastprivate(a)
    for (i=0; i<n; i++)
    {
        a = i+1;
        printf("Thread %d has a value of a = %d for i = %d\n",
               omp_get_thread_num(),a,i);
    } /*-- End of parallel for --*/
    printf("Value of a after parallel for: a = %d\n",a);
    
    int a_shared;
    
#pragma omp parallel for private(i) private(a) shared(a_shared)
    for (i=0; i<n; i++)
    {
        a = i+1;
        printf("Thread %d has a value of a = %d for i = %d\n",
               omp_get_thread_num(),a,i);
        if ( i == n-1 ) a_shared = a;
    } /*-- End of parallel for --*/
    printf("Value of a after parallel for: a = %d\n",a);
    
    return 0;
}
