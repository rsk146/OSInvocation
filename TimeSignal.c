#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

int counter = 0;
int maxIterations = 2;
int zero = 0;

void signalHandle(int signum){
  counter++;
}

int main(int argc, char** argv){

  signal(SIGFPE, signalHandle);
  struct timeval start, end;

  int i;
  gettimeofday(&start, NULL);
  while(counter < maxIterations) i = 10/zero;
  gettimeofday(&end, NULL);

  printf("Start time: %ld\nEnd time: %ld\n", start.tv_usec, end.tv_usec);
}
