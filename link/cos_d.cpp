#include <iostream>
#include <cmath>

double cos_degree(double x) {
    const double pi = 3.14159265358979;
    const double deg_rad = pi/180.0;
    return(cos(x*deg_rad));
}
