#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    
    int i, vlen = 10;
    int a[10];
    int n = 1;
    int TID;
    
    for(i = 0; i<vlen; i++) a[i] = -i-1;
    
    int indx = 4;
#pragma omp parallel default(none) firstprivate(indx) \
                     private(i,TID) shared(n,a)
    {
        TID = omp_get_thread_num();
        
        indx += n*TID;
        for(i=indx; i<indx+n; i++)
            a[i] = TID + 1;
        printf("Thread %d has a value of a[%d] = %d for i = %d\n", omp_get_thread_num(),i,a[i],i);
    }/*-- End of parallel region --*/
    
    cout << "After parallel region" << endl;
    
    for(i=0;i<vlen;i++)
        printf("a[%d] = %d\n",i,a[i]);
    
    return 0;
}
