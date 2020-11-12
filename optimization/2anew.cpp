#include <iostream>
#include <cstring>
#include <vector>
#include <sys/stat.h>
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
    void *outmap[12];
    //off_t filesize;
    
    //Creating input files
    fd = open ("trj.xyz", O_RDONLY);
    
    //Creating output files
    for(int i = 0; i < fn.size(); i++) {
        out[i] = open (fn[i].c_str(),  O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
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
    
    
    //filesize = 1;
    
    //filesize = mystat.st_size; ////
    
    //cout << filesize << endl;
    
    for(int i = 0; i < fn.size(); i++ ) {
        write (out[i], "", mystat.st_size);
    }
   
    /*
    if (write (out[1], "", mystat.st_size) !=  mystat.st_size) {
        printf ("write error");
        return 0;
    }
    */
    
    //lseek (out, mystat.st_size, SEEK_SET);
    
    pmap = mmap(0, mystat.st_size, PROT_READ, MAP_SHARED, fd, 0);
    
    for(int i = 0; i < fn.size(); i++) {
        outmap[i] = mmap(0, mystat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, out[i], 0);
    }
    
    //Input file mapping failure check
    for( int i = 0; i < fn.size(); i++) {
        if(pmap == MAP_FAILED) {
            perror("pmap");
            close(fd);
            exit(1);
        }
    }
    
    //Output file mapping failure check
    for( int i = 0; i < fn.size(); i++) {
        if(outmap == MAP_FAILED) {
            perror("outmap");
            close(out[i]);
            exit(1);
        }
    }
    
    for( int i = 0; i < fn.size(); i++) {
        memcpy (outmap[i], pmap, mystat.st_size);// <- Possible error
    }
    
  //  strncpy(pmap, "That", 4);
    
//----------------------------------------------------------------------------------------------
    //Closing files
    
    close(fd);
    
    //Close outout files
    for(int i = 0; i < fn.size(); i++) {
        close(out[i]);
    }

    
    return 0;
}
