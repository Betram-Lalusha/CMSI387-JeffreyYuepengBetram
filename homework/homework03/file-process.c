#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int returnedValue = fork();
    if(returnedValue < 0) {
        printf("error forking");
        return EXIT_FAILURE;
    } else if(returnedValue == 0) {
        printf("\nopen password file and print out everything in caps\n");
        return EXIT_SUCCESS;
    } else {
        printf("\nNote the parent still has the old standard output.\n");
        return EXIT_FAILURE;
    }
}