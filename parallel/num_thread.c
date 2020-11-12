#include <stdio.h>
#include <omp.h>

int main() {
    
    #pragma omp parallel num_threads(10)
    {
        printf("Hello World!\n");
    }

}
