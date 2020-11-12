#include <stdio.h>
#include <stdlib.h>

double **malloc_matrix(int nrow, int ncol);
void free_matrix(double **a, int nrow);

int main() {
    double **a;
    int i, j, nrow = 2, ncol = 3;
    
    a = malloc_matrix(nrow,ncol);
    
    for(i=1;i<=nrow;i++) {
        for(j=1;j<=ncol;j++) {
            a[i][j] = (i+j)/2.0;
            printf("a[%d][%d]=%f \n",i,j,a[i][j]);
        }
    }
    
    free_matrix(a,nrow);
    
    return 0;
}

double **malloc_matrix(int nrow, int ncol) {
    double **a;
    int i;
    
    if( (a = malloc(nrow*sizeof(double*) )) == NULL ) {     //行の確保
        printf("メモリが確保できません（malloc_matrix内)\n");
        exit(1);
    }
    a = a - 1;
    
    for(i=1;i<=nrow;i++) a[i] = malloc(ncol*sizeof(double));   //列の確保
    for(i=1;i<=nrow;i++) a[i] = a[i] - 1;                   /* 列を1つづずらす */
    
    return a;
}

void free_matrix(double **a, int nrow) {
    int i;
    for(i = 1; i <= nrow; i++) {
        free((void*)(a[i]+1));
    }
    free((void*)(a+1));
}
