#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>



int main(int argc,char *argv[])
{

    int id = fork();
//    id = fork();
    if (id == 0)
    {
        while(1)
        {
            printf("Child Running...!!!\n");
            usleep(50000);
        }
    }
    else
    {
        sleep(2);
        kill(id, SIGKILL);
        wait(NULL);
    }

    return 0;
}
