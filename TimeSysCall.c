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
    //printf("%ld\n", preTime.tv_usec);
    //printf("%ld\n", postTime.tv_usec);
    printf("Syscalls Performed: 100000\n");
    printf("Total Elapsed Time: %ld microseconds\n", postTime.tv_usec-preTime.tv_usec);
    printf("Average Time Per SysCall: %f microseconds\n", (postTime.tv_usec-preTime.tv_usec)/100000.);

}

