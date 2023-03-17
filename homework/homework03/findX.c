#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    if(argc != 2) {
        printf("please include file name.");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1],"r");
    if(!file) {
        printf("file %s does not exist",argv[1]);
        EXIT_FAILURE;
    }

    fclose(file);
}