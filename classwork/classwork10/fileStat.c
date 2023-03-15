#include <unistd.h>
   #include <time.h>
   #include <sys/stat.h>
   #include <stdio.h>

   int main( int argc, char * argv[] ){
      struct stat info;
      if( fstat( STDIN_FILENO, &info ) < 0 ) {
         perror( "   Error getting info about standard input" );
         return -1;
      }
      printf( "\n\n   Standard input is owned by user number %d\n", info.st_uid );
      printf( "   and was last modified %s\n", ctime( &info.st_mtime ) );
      printf("  it has file size %d.\n", info.st_size);
      printf("  the owner of the file belongs to group of id %d.\n",info.st_gid);
      if(S_ISREG(info.st_mode)){
         printf( "   It is a %d-byte file.", info.st_size );
      } else {
         printf( "   It is not a regular file.\n\n" );
      }
      return 0;
   }
   