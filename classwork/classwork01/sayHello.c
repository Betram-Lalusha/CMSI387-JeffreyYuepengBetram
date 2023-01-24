#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char input[100];
    printf("Hello! \n");
    printf("what is your name?\n");
    scanf("%s",input);
    printf("Hello %s \n", input);
}