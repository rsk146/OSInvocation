#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

int zero = 0;

int counter = 0;
int maxIters = 100000;

struct timeval* start;
struct timeval* end;

void handle_signalFPE(int signum){
  counter++;
  if(counter >= maxIters){
    gettimeofday(end, NULL);
    
    //printf("Start time: %ld\nEnd time: %ld\n", start->tv_usec, end->tv_usec);
    long elapsedTime = 1000000 * (end->tv_sec - start->tv_sec) + (end->tv_usec - start->tv_usec);
    printf("Exceptions Occurred: %d\n", maxIters);
    printf("Total Elapsed Time: %ld microseconds\n", elapsedTime);
    printf("Average Time Per Exception: %f microseconds\n", (double)elapsedTime/maxIters);

    free(start); free(end);
    exit(0);
  }

}

int main(int argc, char** argv){
  start = malloc(sizeof(struct timeval));
  end = malloc(sizeof(struct timeval));
  signal(SIGFPE, handle_signalFPE);
  
  gettimeofday(start, NULL);
  int i = 1/zero;
}
