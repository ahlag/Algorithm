#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>

double get_current_time() {
    struct timeval tval;
    gettimeofday(&tval, NULL);
    return (tval.tv_sec + 1e-6 * tval.tv_usec);
}

int main(int argc, char *argv[]) {
#pragma omp parallel
    {
        printf("The parallel region is executed by thread %d\n",
               omp_get_thread_num());
        if ( omp_get_thread_num() == 2 ) {
            printf(" Thread %d does things differently\n",
                   omp_get_thread_num());
        }
    } /*-- End of parallel region --*/
    
    int i, n = 10;
#pragma omp parallel shared(n) private(i)
    {
#pragma omp for
        for (i=0; i<n; i++)
            printf("Thread %d executes loop iteration %d\n",
                   omp_get_thread_num(),i);
    } /*-- End of parallel region --*/
    
    
    return(0);
}
