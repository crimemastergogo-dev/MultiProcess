#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>

int x = 0;

void handler_user1(int sig)
{
    //These should be atomic
    if (x == 0)
        printf("HINT: multiplication is repitative addition \n");
}
int main(int argc,char *argv[])
{
    int pid = fork();
    if (pid == -1)
    {
        printf("Fork Failed...!!!\n");
    }


    if (pid == 0)
    {
        sleep(5);
        kill(getppid(),SIGUSR1);
    }
    else
    {
        struct sigaction sa = {0};

        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handler_user1;

        sigaction(SIGUSR1,&sa,NULL);

        printf("What is the result of 3 X 5 : \n");
        scanf("%d",&x);

        if (15 == x)
        {
            printf("RIGHT...!!!\n");
        }
        else
        {
            printf("WRONG...!!!\n");
        }
    }
    return 0;
}
