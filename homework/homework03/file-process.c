#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>

int main() {
    FILE *file;
    int currentChar;
    int returnedValue = fork();
    if(returnedValue < 0) {
        printf("error forking");
        return EXIT_FAILURE;
    } else if(returnedValue == 0) {
        file = fopen("/etc/passwd","r");
        if(file == NULL) {
            printf("\nFile not found\n");
            fclose(file);
            return EXIT_FAILURE;
        }
        while((currentChar = fgetc(file)) != EOF) {
            printf("%c",toupper(currentChar));
        }
        fclose(file);
        return EXIT_SUCCESS;
    } else {
        printf("\nNote the parent still has the old standard output.\n");
        return EXIT_SUCCESS;
    }
}