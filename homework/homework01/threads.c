#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
static void *child(void *ignored){
  while(1) {
    sleep(5);
    printf("Child is done sleeping 5 seconds.\n");
  }
  return NULL;
}
int main(int argc, char *argv[]){
  pthread_t child_thread;
  int code;

code = pthread_create(&child_thread, NULL, child, NULL);
if(code){
  fprintf(stderr, "pthread_create failed with code %d\n", code);
}
while(1) {
    if(getchar() == '\n') {
        pthread_cancel(child_thread);
        printf("killed child thread");
        break;
    }
}
return 0;
}