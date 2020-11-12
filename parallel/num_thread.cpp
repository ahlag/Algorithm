#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    
    #pragma omp parallel num_threads(10)
    {
        cout << "Hello World" << endl;
    }

    
    #pragma omp parallel num_threads(10)
    {
        cout << "Hello World\n";
    }
    
}

