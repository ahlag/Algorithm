#include <iostream>
#include <mpi.h>
#include <stdio.h>

using namespace std;

double ran(void) {
    return (double)rand()/(double)RAND_MAX;
}

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);
    int myid;
    int numprocs;
    
    int rc;
    
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    printf("Hello: rank %d, world: %d\n",myid, numprocs);
    
    rc = MPI_Finalize();
    

    return 0;
}

