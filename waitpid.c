#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>



int main(int argc,char *argv[])
{

    int id1 = fork();

    if (id1 == -1) {printf("Error in forking ...!!!\n");}

    if (id1 == 0)
    {
        sleep(4);
        printf("Finished execution %d\n",getpid());
    }

    int id2 = fork();

    if (id2 == -1) {printf("Error in forking ...!!!\n");}

    if (id2 == 0)
    {
        sleep(1);
        printf("Finished execution %d\n",getpid());
    }

    wait(NULL);
    wait(NULL);


    return 0;
}
