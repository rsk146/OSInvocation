#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv){
    struct timeval preTime;
    struct timeval postTime;
    gettimeofday(&preTime, NULL);
    int i = 0;
    pid_t cpid;
    for(i; i < 5000; i++){
        if(fork()){
            cpid = wait(NULL);
        }
        else{
            exit(0);
        }
    }
    gettimeofday(&postTime, NULL);
    printf("Forks Performed: 2\n");
    printf("Total Elapsed Time: %ld microseconds\n", postTime.tv_usec-preTime.tv_usec);
    printf("Average Time Per Fork: %f microseconds\n", (postTime.tv_usec-preTime.tv_usec)/100000.);
}