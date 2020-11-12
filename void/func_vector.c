#include <stdio.h>
#include <stdlib.h>

double *malloc_vector(int n);
void free_vector(double *a);

int main() {
    
    double *a;
    int i, n = 5;
    
    a = malloc_vector(n);
    
    printf("ベクトルaの内容は次の通りです\n");
    for(i=1;i<=n;i++) {
        a[i] = 2.0*i;
        printf("a[%d]=%f\n",i,a[i]);
    }
    
    free_vector(a);
    
    return 0;
}

double *malloc_vector(int n)
/*a[1], a[2], ..., a[n]のベクトル作成*/
{
    double *a;
    
    if( (a=malloc(sizeof(double)*n)) == NULL ) {
        printf("メモリが確保できません（malloc_vector内)\n");
        exit(1);
    }
    
    return (a-1);
}

void free_vector(double *a)
/*malloc_vector関数で確保した領域をh解放*/
{
    free(a+1);
}
