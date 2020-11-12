#include <stdio.h>
#include <omp.h>

int main() {
    //int i = 0, j = 10, k = 20;
    
    /*
    #pragma omp parallel private(i)
    {
        i = j + k;
        printf("i=%d j=%d k=%d\n", i, j, k);
    }
    
    printf("i=%d j=%d k=%d\n", i, j, k);
     */
    
    
    
    int i, j;
    j = 0;
#pragma omp parallel for private(j)
    for(i=0;i<10;i++){
        printf("for loop's j=3%d\n",j);
        j++;
    }
    printf("j=3%d\n",j);
    
    return 0;
    
}
