#include <stdio.h>
#include <omp.h>

int main() {
    
    int a,b,c;
    
    a = 1, b = 2, c = 3;
#pragma omp parallel default(none) private(a) shared(b,c)
    {
        printf("a=%2d, b=2%d, c=2%d\n", a,b,c);
    }
    return 0;
}
