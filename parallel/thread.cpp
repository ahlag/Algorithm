#include <iostream>
#include <omp.h>

using namespace std;

int main() {
#pragma omp parallel
    {
#ifdef _OPENMP
        cout << "Hello World!!" << omp_get_thread_num()+1 << endl;
#else
        cout << "Hello World!!" << endl;
#endif
    }
}
