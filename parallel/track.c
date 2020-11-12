#include <stdio.h>
#include <time.h>
#include <omp.h>

int num_steps = 100000000;
double step;

int main( int argc, char* agv[] ) {
    int i;
    double start_time, stop_time;
    double pi, sum = 0.0;
    
    step = 1.0/(double)num_steps;
    start_time = clock();
    
#pragma omp parallel for reduction(+:sum)
    for( i = 0; i < num_steps; i++ ) {
        double x = ( i * 0.5 ) * step;
        sum += 4.0/(1.0 + x*x);
    }
    pi = sum*step;
    stop_time = clock();
    
    printf("Pi's value %10.7f\n",pi);
    printf("Pi's calculation time %lf seconds\n", ((double)(stop_time - start_time )/CLOCKS_PER_SEC));
    
    return 0;
}
