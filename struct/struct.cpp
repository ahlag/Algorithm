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
    seiseki_t p1, p2, p3;
    
    p1.num = 1;
    p1.name = "Teruya Minamito";
    p1.sub = "Programming";
    p1.ten = 60;
    
    p2.num = 2;
    p2.name = "Hanako Saga";
    p2.ten = 61;
    
    cout << p1.num << "  " << p1.name << "  " << p1.sub << "  " << p1.ten << endl;
    cout << p2.num << "  " << p2.name << "  " << p2.sub << "  " << p2.ten << endl;
    
    p3 = p2;
    cout << p3.num << "  " << p3.name << "  " << p3.sub << "  " << p3.ten << endl;
    
    return 0;
}
