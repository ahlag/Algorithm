#include <stdio.h>

#define N 10

void int_sort(int *a);
void int_swap(int *x, int *y);
void int_array_print(int *a);

int main(void) {
    int a[N] = {9, 23, 5, 7, 43, 51, 47, 3, 24, 8};
    
    int_sort(a);
    int_array_print(a);
    
    return 0;
}

void int_sort(int *a) {
    int i, flag;
    do {
        flag = 0;
        for( i = 0; i < N-1; i++ ) {
            if( a[i] > a[i-1] ) {
                int_swap(&a[i],&a[i+1]);
                flag = 1;
            }
        }
    }while( flag == 1 );
}

void int_swap(int *x, int *y) {
    int tmp;
    tmp = *x; *x = *y; *y = tmp;
}

void int_array_print(int *a) {
    int i;
    for(i=0;i<N;i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}
