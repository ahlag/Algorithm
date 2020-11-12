#include <iostream>
#include <mpi.h>

int main(int argc, int* argv[]) {
    int ierr, rc;
    ierr = MPI_Init(&argc, &argv);
    int myid;
    ierr = MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    int val = 0;
    if(0 == rank) {
        cin >> val;
    }
    MPI_Bcast();
    
    rc = MPI_Finalize();
    

    return 0;
}
