#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>



int main(int argc,char *argv[])
{

    int n = 0;
    int id = fork();
    printf(" PID = %d PPID %d\n",getpid(),getppid());
    if (id == 0)
        n = 3;
    else
        n = 5;

    for (;n > 0;n--)
    {
        printf(" PID = %d \n",getpid());
    }


    //wait(NULL);

    return 0;
}
