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
        kill(id, SIGSTOP);
        int time = 0;

        do
        {
            printf("Enter Time in sec :");
            scanf("%d",&time);

            if (time > 0)
            {
                kill(id, SIGCONT);
                sleep(time);
                kill(id, SIGSTOP);
            }
            
        }while(time > 0);

        kill(id, SIGKILL);
        wait(NULL);
    }

    return 0;
}
