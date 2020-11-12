#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main ( int argc, char *argv[] ) {
    
    int fd, out; //file descriptor
    struct stat mystat;
    void *pmap, *outmap;
    off_t filesize;
    
    fd = open ("text.txt", O_RDONLY);
    out = open ("output.txt",  O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
    
    if(fd == -1) {
        perror("open");
        exit(1);
    }
    
    if(fstat(fd, &mystat) < 0) {
        perror("fstat");
        close(fd);
        exit(1);
    }
    
    filesize = mystat.st_size;
    
    if (write (out, "", filesize) != filesize) {
        printf ("write error");
        return 0;
    }
    
    //lseek (out, mystat.st_size, SEEK_SET);
    
    pmap = mmap(0, mystat.st_size, PROT_READ, MAP_SHARED, fd, 0);
    outmap = mmap(0, mystat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, out, 0);
    
    if(pmap == MAP_FAILED) {
        perror("pmap");
        close(fd);
        exit(1);
    }
    
    if(outmap == MAP_FAILED) {
        perror("outmap");
        close(out);
        exit(1);
    }
    
    memcpy (outmap, pmap, mystat.st_size);
    
  //  strncpy(pmap, "That", 4);
    close(fd);
    close(out);
    
    return 0;
}
