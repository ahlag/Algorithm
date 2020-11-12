#include <stdio.h>
#include <omp.h>

int main() {
    
    int i, j;
    j = 0;
#pragma omp parallel for shared(j)
    for(i = 0; i < 100; i++) {
        j++;
    }
    printf("\nj\n=3%d",j);
    
    return 0;
}
