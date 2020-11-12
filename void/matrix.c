#include <stdio.h>
#include <stdlib.h>

#define M 4
#define N 3

int main(void) {
    
    double **a;
    int i, j;
    
    if( (a = malloc(M*sizeof(double) )) == NULL ) {     //行の確保
        printf("メモリが確保できません（行列a)\n");
        exit(1);
    }
    for(i=0;i<M;i++) a[i] = malloc(N*sizeof(double));   //列の確保
    
    for(i=0;i<M;i++) {
        for(j=0;j<N;j++) {
            a[i][j] = (i+j)/2.0;
            printf("a[%d][%d]=%f \n",i,j,a[i][j]);
        }
    }
    
    /*メモリの解放*/
    for(i=0;i<M;i++)
        free((void *)a[i]);
    free((void *)a);

    return 0;
}
