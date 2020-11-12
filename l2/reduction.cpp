#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <omp.h>

int main() {
    
    int n=400000,  m=1000;
    double x=0,y=0;
    double s=0;
    vector<double> shifts(n);

#pragma omp parallel for reduction(+:x,y)
for (int j=0; j<n; j++) {
    
    double r=0.0;
    for (int i=0; i < m; i++){
        
        double rand_g1 = cos(i/double(m));
        double rand_g2 = sin(i/double(m));
        
        x += rand_g1;
        y += rand_g2;
        r += sqrt(rand_g1*rand_g1 + rand_g2*rand_g2);
    }
    shifts[j] = r / m;
}
    return 0;
}
