#include <iostream>
#include <cmath>

using namespace std;

double newton(double *,double *,int,double);

int main(int argc, char* argv[]) {
    
    double x[]={0.0,1.0,3.0,6.0,7.0},
           y[]={0.8,3.1,4.5,3.9,2.8};
    
    double t;
    
    printf("      x      y\n");
    for (t=0.0;t<=7.0;t=t+0.5)
        printf("%7.2f%7.2f\n",t,newton(x,y,5,t));
    
    return 0;
}

double newton(double x[],double y[],int n,double t) {
    static int flag=1;
    static double a[100];
    double        w[100],
                  s;
    int i,j;
    
    if (flag ==1) {
        for( i=0; i < n; i++ ) {
            w[i]=y[i];
            for( j=i-1;j>=0;j--) {
                
            }
            a[i]=w[0];
        }
        
    }
    
    
    
    return s;
}
