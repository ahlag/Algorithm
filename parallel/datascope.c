#include <stdio.h>
#include <omp.h>

int static_data = 0;

int main () {
    
    int i;
    int dynamic_data = 0;
    
    #pragma omp parallel firstprivate(dynamic_data)
    { //start parallel
        int local = 0;
        int temp_static = 0;
        for( i = 0; i <= 1000; i++ ) {
            local++;
            dynamic_data++;
            temp_static++;
            //printf("in local= %d\n", local);
            //printf("in static_data = %d\n", static_data);
            printf("i = %d\n", i);
            printf("temp_static = %d\n", temp_static);
        } //end for
        static_data += temp_static;
        printf("in static data = %d\n", static_data);
    } //end parallel
    
    //printf("final static_data = %d\n", static_data);
    printf("final static_data = %d\n", static_data);
    
    
    return 0;
}
