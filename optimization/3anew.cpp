#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
#include <vector>
#include <sys/stat.h>
#include <streambuf>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/time.h>

using namespace std;

void Remove(string FILETODELETE) {
    if(remove(FILETODELETE.c_str()) != 0) {
    } else {
        cout << "Previous " << FILETODELETE << " deleted." << endl;
    }
};

double get_current_time() {
    struct timeval tval;
    gettimeofday(&tval, NULL);
    return (tval.tv_sec + 1e-6 * tval.tv_usec);
}

struct membuf : streambuf {
    membuf(char* start, size_t size) {
        this->setg(start, start, start + size);
    }
};

int main ( int argc, char *argv[] ) {
    
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
    //Filename creator
    
    vector <string> fn(12);   //filename
    
    string FILENAME;
    string FILENAME_PREFIX = "trj_", FILENAME_SUFFIX=".xyz";
    
    for( int i = 0; i < fn.size(); i++ ) {
        fn[i] = FILENAME_PREFIX + to_string(i+1) + FILENAME_SUFFIX;
    }
    
//----------------------------------------------------------------------------------------------
    //Write trajectories to files
    
    int fd;         //input file descriptor
    int out[12];    //output file descriptor
    struct stat mystat;
    void *pmap;
    //off_t filesize;
    
    //Creating input files
    fd = open ("trj.xyz", O_RDONLY);
    
    //Creating output files
    vector<ofstream> ofs(12);
    for (int i = 0; i < 12; ++i)
    {
        fn[i] = FILENAME_PREFIX + to_string(i+1) + FILENAME_SUFFIX;
        ofs[i].open(fn[i], ios::app);
    }
    
    //Input file open failure
    if(fd == -1) {
        perror("open");
        exit(1);
    }
    
    if(fstat(fd, &mystat) < 0) {
        perror("fstat");
        close(fd);
        exit(1);
    }
    
    //mmap input file
    pmap = mmap(0, mystat.st_size, PROT_READ, MAP_SHARED, fd, 0);
    
    //Input file mapping failure check
    if(pmap == MAP_FAILED) {
        perror("pmap");
        close(fd);
        exit(1);
    }
    
    //Output file mapping failure check
    for( int i = 0; i < fn.size(); i++) {
        if(outmap == MAP_FAILED) {
            perror("outmap");
            close(out[i]);
            exit(1);
        }
    }
    
    double current = get_current_time(); //Gettime
    
    char start[100];
    string headline = "     232      12";
    int cnt = -1;
    
    membuf sbuf((char*)pmap, mystat.st_size);
    istream in(&sbuf);
    
    cout << "Writing trajectories to files." << endl;
    
    for (string line; getline(in, line); ) {
        if(line == headline) cnt = (cnt + 1) % 12;
        ofs[cnt] << line << endl;
    }
    
    cout << "Done" << endl;
    cout << "Finished time: " << get_current_time() - current << endl;
    
//----------------------------------------------------------------------------------------------
    //Closing files
    
    close(fd);
    
    //Close outout files
    for (int i = 0; i < 12; ++i) {
        ofs[i].close();
    }

    return 0;
}
