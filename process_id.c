#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>



int main(int argc,char *argv[])
{

    int id = fork();
    printf(" PID = %d PPID %d\n",getpid(),getppid());


    return 0;
}
