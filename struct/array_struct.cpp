#include <iostream>
#include <string>

#define N 2

using namespace std;

typedef struct seiseki {
    int num;
    string name;
    string sub;
    int ten;
} seiseki_t;

int main() {
    seiseki_t p[4];
    
    p[1].num = 1;
    p[1].name = "Teruya Minamito";
    p[1].sub = "Programming";
    p[1].ten = 60;
    
    p[2].num = 2;
    p[2].name = "Hanako Saga";
    p[2].sub = "Sage";
    p[2].ten = 61;
    
    cout << p[1].num << "  " << p[1].name << "  " << p[1].sub << "  " << p[1].ten << endl;
    cout << p[2].num << "  " << p[2].name << "  " << p[2].sub << "  " << p[2].ten << endl;
    
    p[3] = p[2];
    cout << p[3].num << "  " << p[3].name << "  " << p[3].sub << "  " << p[3].ten << endl;
    
    return 0;
}
