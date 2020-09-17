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
    int i;
    int cpid;
    for(i = 0; i < 5000; i++){
        cpid = fork();
        if(cpid){
            wait(&cpid);
        }
        else{
            exit(0);
        }
    }
    gettimeofday(&postTime, NULL);
    long diff = (postTime.tv_sec - preTime.tv_sec)*1000000 + (postTime.tv_usec - preTime.tv_usec);
    printf("Forks Performed: 5000\n");
    printf("Total Elapsed Time: %ld microseconds\n", diff);
    printf("Average Time Per Fork: %f microseconds\n", diff/100000.);
}