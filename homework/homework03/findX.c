#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>

int main(int argc, char *argv[]) {
    int c;
    FILE *file;
    int offset;
    int pageSize;
    void *fileAddress;
    if(argc != 2) {
        printf("please include file name.");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1],"r");
    if(!file) {
        printf("file %s does not exist",argv[1]);
        return EXIT_FAILURE;
    }

    pageSize = (int)sysconf(_SC_PAGESIZE);
      if ( pageSize < 0) {
        perror("sysconf() error");
        return EXIT_FAILURE;
      }
    offset = 0;
    int fd = open(argv[1],O_CREAT);
    if ( fd < 0 ) {
        perror("error opening file. \n");
        return EXIT_FAILURE;
    }
    fileAddress = mmap(NULL,
                      pageSize,
                      PROT_READ,
                      MAP_SHARED,
                      fd,
                      offset );
    if(fileAddress == MAP_FIXED) {
        printf("error mapping file");
        return EXIT_FAILURE;
    }

    printf("file data: %s \n",fileAddress);

    fclose(file);
    return EXIT_SUCCESS;
}