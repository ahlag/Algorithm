#include <iostream>
#include <cmath>

using namespace std;

double func(double a) {
    const double pi = 3.14159265358979;
    const double deg_rad = pi/180.0;
    return(sin(a*deg_rad));
}

