#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <sys/time.h>

using namespace std;

void Remove(string FILETODELETE) {
    if(remove(FILETODELETE.c_str()) != 0) {
        //        cout << "Previous file(s) can't be deleted." << endl;
    } else {
        cout << "Previous " << FILETODELETE << " deleted." << endl;
    }
};

double get_current_time() {
    struct timeval tval;
    gettimeofday(&tval, NULL);
    return (tval.tv_sec + 1e-6 * tval.tv_usec);
}


int main() {
    
//----------------------------------------------------------------------------------------------
    //Remove previous trajectory files in current directory
    
    string s = "Hey!";
    string TRAJECTORY;
    string TRAJECTORY_PREFIX = "trj_", TRAJECTORY_SUFFIX=".xyz";
    
    
    for (int j = 0; j < 12; j++) {
        TRAJECTORY = TRAJECTORY_PREFIX + to_string(j) + TRAJECTORY_SUFFIX; //FILENAME builder
        Remove(TRAJECTORY);
    }
    
//----------------------------------------------------------------------------------------------
    //Write trajectories to files
    
    fstream file;
    
    file.open("trj.xyz", ios::in);
    if(!file.is_open()) {
        return EXIT_FAILURE;
    }
    
    string FILENAME;
    string FILENAME_PREFIX = "trj_", FILENAME_SUFFIX=".xyz";
    
    vector<string> fn(12);
    vector<ofstream> ofs(12);
    
    for (int i = 0; i < 12; ++i)
    {
        fn[i] = FILENAME_PREFIX + to_string(i+1) + FILENAME_SUFFIX;
        ofs[i].open(fn[i], ios::app);
    }
    
    double current = get_current_time();
    
    cout << "Current time: " << current << endl;
    
    string str;
    string headline = "     232      12";
    
    cout << "Writing trajectories to files.\n";
    int cnt = -1;
    while(!file.eof()) {
        getline(file,str);
        if(str == headline) cnt = (cnt + 1) % 12;
        ofs[cnt] << str << endl;
    }
    
    cout << "Finished time: " << get_current_time() - current << endl;
    
    cout << "Done\n";
    file.close();
    for (int i = 0; i < 12; ++i)
    {
        ofs[i].close();
    }
    
    return 0;
}
