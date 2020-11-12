#include <stdio.h>
#include <omp.h>

int main() {
    
    #pragma omp parallel
    {
        #pragma omp sections
        {
            printf("section0: Thread No.=%d, No. of Threads=%d\n", omp_get_thread_num(), omp_get_num_threads());
        }
        #pragma omp sections
        {
            printf("section1: Thread No.=%d, No. of Threads=%d\n", omp_get_thread_num(), omp_get_num_threads());
        }
        #pragma omp sections
        {
            printf("section2: Thread No.=%d, No. of Threads=%d\n", omp_get_thread_num(), omp_get_num_threads());
        }
    }
    
    return 0;
    
}
