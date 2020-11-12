#include <iostream>
#include <cmath>

double sin_degree(double x) {
    const double pi = 3.14159265358979;
    const double deg_rad = pi/180.0;
    return(sin(x*deg_rad));
}
