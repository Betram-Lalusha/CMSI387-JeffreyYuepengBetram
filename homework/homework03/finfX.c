#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("include file path.");
        return EXIT_FAILURE;
    }
    
    const char* file_path = argv[1];
    int file_descriptor = open(file_path, O_RDONLY);

    if (file_descriptor == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    struct stat file_stat;
    if (fstat(file_descriptor, &file_stat) == -1) {
        perror("Failed to get file status");
        exit(EXIT_FAILURE);
    }

    char* file_contents = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, file_descriptor, 0);

    if (file_contents == MAP_FAILED) {
        perror("Failed to map file to memory");
        exit(EXIT_FAILURE);
    }

    // Loop through the bytes of the mapped file
    for (off_t i = 0; i < file_stat.st_size; i++) {
        if(file_contents[i] == 'x') {
            printf("\n\nFound x!\n\n");
            munmap(file_contents, file_stat.st_size);
            close(file_descriptor);
            return EXIT_SUCCESS;
        }
       
    }

    munmap(file_contents, file_stat.st_size);
    close(file_descriptor);
    printf("\n\nFailure. x not found \n");
    return EXIT_FAILURE;
}
