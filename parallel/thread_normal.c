#include <stdio.h>
#include <MacTypes.h>

#define NUM_OF_THREADS 3

int i, j, k;

void slave(void) {
    i = j + k;
}

void master(void) {
    HANDLE hThread[NUM_OF_THREADS];
    
    i = 0;
    j = 10;
    k = 20;
    
    for( int t = 0; t < NUM_OF_THREADS; t++ ) {
        hThread[t] = CreateThread(0, 0, (LP_THREAD_START_ROUTINE)slave, NULL, 0, NULL);
        
        i = j + k;
        
        WaitForMultipleObjects(NUM_OF_THREADS, hThread, TRUE, INFINITE);
    }
}

int main () {
    
    master();
    
    printf("i=%d, j=%d, k=%d\n", i, j, k);
    
    return 0;
}
