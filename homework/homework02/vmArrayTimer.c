#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int size;
    int* array;
    if(argc < 2) {
        printf("please state size of array \n");
    } else {
        printf("\n");
        size = atoi(argv[1]);
        array = (int*) malloc(size * sizeof(int));
        printf("OK. Using array of size %d. \n", size);
        printf("\n");
        for(int i = 0; i < size; i++) {
            array[i] = (rand() %(100 - 1 + 1)) + 1;
        }
        printf("\n");
        printf("OK. Array has been filled.");
        printf("\n \n");
        printf("Starting acccess.");
        printf("\n \n");

        for(int j = 0; j < 10; j++) {
            for(int i = 0; i < size; i++) {
                if(i % 4096 == 0 && i >= 4096) printf("\n%dth element: %d\n",i,array[i]);
            }   
        }
        free(array);
    }
    return 0;
}