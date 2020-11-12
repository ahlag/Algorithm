#include <iostream>

using namespace std;

class Bad_area{};

int area(int a, int b) {
    if(a <= 0 || b <= 0 ) throw Bad_area{};
    return a*b;
}

int main() {
    try{
        int x = -1;
        int y= 2;
        int z = 4;
        
        int area1 = area(x,y);
    //    int area2 = framed_area(1,z);
    //    int area3 = framed_area(y,x);
    //    double ratio = area1/area3;
    }
    
    catch(Bad_area) {
        cout << "Oops! bad arguments to area()" << endl;
    }
}
