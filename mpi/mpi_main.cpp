#include <iostream>
#include <mpi.h>

using namespace std;

double ran(void) {
    return (double)rand()/(double)RAND_MAX;
}

double calc_pi(int seed, int trial) {
    srand(seed);
    int n = 0;
    for( int i = 0; i < trial ; i++ ) {
        double x = ran();
        double y = ran();
        if( x*x + y*y < 1.0) {
            n++;
        }
    }
    return 4.0*(double)n/(double)trial;
}

int main(int argc, char* argv[]) {
    
    int ierr, rc;
    int myid, numprocs;
    
    ierr = MPI_Init(&argc,&argv);
    ierr = MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    
    double pi = calc_pi(myid,1000000);
    cout << "rank: " << myid <<  " size : " << numprocs << " pi : " << pi << endl;
    
    //Blocks until all processes in the communicator have reached this routine.
    MPI_Barrier(MPI_COMM_WORLD);
    
    double sum = 0.0;
    
    MPI_Reduce(&pi, &sum, 1, MPI_DOUBLE, MPI_SUM, 1, MPI_COMM_WORLD);
    
    sum = sum/(double)numprocs;

    if(myid == 1) {
        cout << "average = " << sum << endl;
    }
    
    rc = MPI_Finalize();

    return 0;
}

