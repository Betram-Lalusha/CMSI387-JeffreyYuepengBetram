#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

   int mutex = 1;
   int full  = 0;
   int empty = 7;          // maximum of seven messages in buffer
   int x     = 0;

   int myWait( int s ) {
      return( --s );
   }

   int mySignal( int s ) {
      return( ++s );
   }
      void *producer(void *ignored) {
        while(1) {
          if(mutex && empty) {continue;}
           mutex = myWait( mutex );
           full  = mySignal( full );
           empty = myWait( empty );
           x++;
           printf( "\n  Producer produces the item %d", x );
           mutex = mySignal( mutex );
           usleep(5000);
        }
   }

   void *consumer(void *ignored)
   {
      while(1) {
        if(mutex && full) {continue;}
        mutex = myWait( mutex );
        full  = myWait( full );
        empty = mySignal( empty );
        printf( "\n  Consumer consumes item %d", x );
        x--;
        mutex = mySignal( mutex );
        usleep(9000);
      }

   }

   int main()
   {
      int n;
      int code1;
      int code2;
      pthread_t child_thread;
      pthread_t child_thread2;
      code1 = pthread_create(&child_thread, NULL, producer, NULL);
      if(code1){
        fprintf(stderr, "pthread_create failed with code %d\n", code1);
      }
      code2 = pthread_create(&child_thread, NULL, consumer, NULL);
      if(code2){
        fprintf(stderr, "pthread_create failed with code %d\n", code1);
      }

      sleep(5);
    //   while( 1 ) {
    //      printf( "\n\n   1.Producer\n   2.Consumer\n   3.Exit" );
    //      printf("\n      Enter your choice: ");
    //      scanf("%d",&n);
    //      switch( n ) {
    //         case 1:  if( (mutex == 1) && (empty != 0) ) {
    //                     producer();
    //                  } else {
    //                     printf( "\nBuffer is full!!" );
    //                  }
    //                  break;
    //         case 2:  if( (mutex == 1) && (full != 0) ) {
    //                     consumer();
    //                  } else {
    //                     printf("\nBuffer is empty!!");
    //                  }
    //                  break;
    //         case 3:
    //         default: exit( 0 );
    //                  break;
    //      }
    //   }
    pthread_cancel(child_thread);
    pthread_cancel(child_thread2);
    return 0;
   }

