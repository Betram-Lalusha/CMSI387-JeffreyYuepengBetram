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
  printf ("\nDo you want %s to be created in this directory [y/N]?\n", filePath);
  scanf("%c",&userResponse);
  if(userResponse == 'y') {
    newFile = fopen(filePath,"w");
    fclose(newFile);
    printf("\n %s created.\n\n",filePath);
  } else if (userResponse != 'N') {
    printf("\n unrecognized command. File not created\n");
    return;
  } 
}

/**
 * prints the the usage message to help the user
 * learn how to use the command.
*/
void printUsageMessage() {
  printf("\n Improper usage. See below for help.\n");
  printf ("\n Usage: changeExtension [FILENAME] [NEW EXTENSION]");
  printf ("\n Example: changeExtension myFile.js .java");
  printf ("\n This will change your myFile.js to myFile.java\n\n");
}

/**
 * renames a given  file with the new extension
*/
void renameFile(char oldName[],char fileName[], char newExtension[]) {
  strcat(fileName,newExtension);
  if(rename(oldName,fileName) == 0) {
    printf("\nFile renamed successfully\n\n");
  } else {
    printf("\nError renaming file. Try again.\n\n");
  }
}
int main(int argc, char *argv[])
{
  FILE *file;
  int currentChar;
  char filePath[1000];
  char fileName[100] = "";

  if(argc < 3) {
    printUsageMessage();
    return EXIT_FAILURE;
  } else if (argc > 3) {
    printUsageMessage();
    return EXIT_FAILURE;
  }

  strcpy(filePath,argv[1]);

  file = fopen(filePath,"r");
  if(file == NULL) {
    fileNotFound(filePath);
    fclose(file);
    return EXIT_FAILURE;
  }

  for(int i = 0; i < strlen(argv[1]);i++) {
    currentChar = argv[1][i];
    if(currentChar == '.') {
      break;
    } else {
      strncat(fileName,&currentChar,1);
    }
  }
  renameFile(argv[1],fileName,argv[2]);
  fclose(file);
  return EXIT_SUCCESS;
}