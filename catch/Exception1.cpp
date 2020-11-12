#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void Open(ifsteam& file, const char* filename) {
    file.open(filename);
    if(! file.is_open()) {
        throw 1;
    }
}

void Getline(ifstream& file, string& line) {
    file.open(file);
    getline(file,line);
    
    if(file.fail()) {
        throw "ファイルは読めませんでした!";
    }
    
}

int main() {

    try {
        ifstream file;
        
        Open(file,"test.txt");
        
        string line;
        Getline(file,line);
        cout << line << endl;
    } catch(const char* error) {
        cerr << error << endl;
        return EXIT_FAILURE;
    } catch(int error) {
        cerr << "ファイルを開けませんでした!" << endl;
        return EXIT_FAILURE;
    }
}


