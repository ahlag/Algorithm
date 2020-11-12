#include <iostream>
#include <mpi.h>

using namespace std;

double ran(void) {
    return (double)rand()/(double)RAND_MAX;
}

double direct(double a[], double b[], int &N) {
    int sum = 0;
    
    for( int i = 0; i < N; i++ ) {
        sum += a[i]*b[i];
    }
    
    return sum;
}

int main(int argc, char* argv[]) {
    
    int ierr, rc;
    int myid, numprocs;
    
    ierr = MPI_Init(&argc,&argv);
    ierr = MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    
    double a[] = {1, 2, 3};
    double b[] = {1, 2, 3};
    
    int N = sizeof(a)/sizeof(a[0]);
    
    int prod = 0;
    
    prod = direct(a, b, N);
    
    cout << "prod : " << prod << endl;
    
    rc = MPI_Finalize();

    
    return 0;
}

