#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Reading {
    int hour;
    double temperature;
};

int main() {
    string iname = "temp.txt";
    ifstream ist {iname};
    
    string oname = "output.txt";
    ofstream ost {oname};
    if(!ost) cerr << "can't open output!" << endl;
    
    vector<Reading> temps;
    int hour;
    double temperature;
    while(ist >> hour >> temperature) {
        if ( hour < 0 || 23 < hour ) cerr << "hour out of range!";
        temps.push_back(Reading{hour,temperature});
    }
    
    for( int i = 0; i < temps.size(); i++ ) {
        cout << '(' << temps[i].hour << ','
             << temps[i].temperature << ")\n";
    }
    
    return 0;
}
