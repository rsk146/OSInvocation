#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char** argv){
    struct timeval preTime;
    struct timeval postTime;
    gettimeofday(&preTime, NULL);
    int i =0;
    //int pid = 0;
    for(i = 0; i < 100000; i++){
        getpid();
    }
    gettimeofday(&postTime, NULL);
    long diff = (postTime.tv_sec - preTime.tv_sec)*100000 + (postTime.tv_usec - preTime.tv_usec);
    printf("Syscalls Performed: 100000\n");
    printf("Total Elapsed Time: %ld microseconds\n", diff);
    printf("Average Time Per Syscall: %f microseconds\n", diff/100000.);

}

