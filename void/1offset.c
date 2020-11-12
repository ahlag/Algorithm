#include <stdio.h>
#include <stdlib.h>

#define N 8

int main(void) {
    
    double *a, *aa;
    int i;
    
    if( (aa = malloc(sizeof(double)*N )) == NULL ) {
        printf("メモリが確保できません（ベクトルaa)\n");
        exit(1);
    }
    
    for(i=0;i<N;i++)
        aa[i] = 2.0*1.0;
    a = aa - 1;         /*aはaaより1つ前の位置を指す*/
    
    printf("ベクトルaとaaの内容は次の通りです\n");
    for(i=0;i<N;i++)
        printf("a[%d]=%f \t aa[%d]=%f\n",i+1,a[i+1],i,aa[i]);
    
    free(aa);
    
    return 0;
}
