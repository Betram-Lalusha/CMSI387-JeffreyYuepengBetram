#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * prints an error message if the file is not found
 * and creates the file if the user wishes.
*/
void fileNotFound(char filePath[]) {
  char userResponse;
  FILE *newFile;
  printf("\nfile %s does not exist.", filePath);
  printf ("\nDo you want %s to be created in this directory [y/N]?", filePath);
  scanf("%c",&userResponse);
  if(userResponse == 'y') {
    newFile = fopen(filePath,"w");
    fclose(newFile);
    printf("\n %s created.\n",filePath);
  } else if (userResponse != 'N') {
    printf("\n unrecognized command. File not created\n");
    return;
  } 
}
int main(int argc, char *argv[])
{
   FILE *file;
   char filePath[1000];

  if(argc < 2) {
    printf("\n please include file name.");
    printf ("\n Usage: changeExtension [FILENAME]\n\n");
    return EXIT_FAILURE;
  } else if (argc > 2) {
    printf("\n Too many arguments.");
    printf ("\n Usage: changeExtension [FILENAME]\n\n");
    return EXIT_FAILURE;
  }

  strcpy(filePath,argv[1]);

  file = fopen(filePath,"r");
  if(file == NULL) {
    fileNotFound(filePath);
    fclose(file);
    return EXIT_FAILURE;
  }
  fclose(file);
  return EXIT_SUCCESS;
}