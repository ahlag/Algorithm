#include <stdio.h>
#include <omp.h>

int main() {

    /*
    int i,j=0;
    printf("before loop i=%3d\n",i);
    
    #pragma omp parallel for lastprivate(j)
    for(i=0;i<10;i++){
        printf("for loop's j=%d\n",j);
        j=10;
    }
    printf("After loop j =%d\n",j);
    
  */
    
    int i,j=0;
    printf("before loop i=%3d\n",i);
    
    #pragma omp parallel for firstprivate(j) lastprivate(j) num_threads(2)
    for(i=0;i<10;i++){
        printf("for loop's j=%d\n",j);
        j=10;
    }
    printf("After loop j =%d\n",j);

    return 0;
    
}
