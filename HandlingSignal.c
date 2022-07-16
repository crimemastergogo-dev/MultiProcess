#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>


void handler_tstp(int sig)
{
    printf("Stopped Not allowed : \n");
}
void handler_cont(int sig)
{
    printf("Input number : \n");
    fflush(stdout);
}
int main(int argc,char *argv[])
{
    struct sigaction sa;

    sa.sa_handler = &handler_tstp;
    sa.sa_flags = SA_RESTART;

//    sigaction(SIGTSTP,&sa,NULL);

//    signal(SIGTSTP,&handler);  ---> portability reasons
     struct sigaction sa1;

    sa1.sa_handler = &handler_cont;
    sa1.sa_flags = SA_RESTART;

    sigaction(SIGCONT,&sa1,NULL);

    int x = 0;
    printf("Input number : \n");
    scanf("%d",&x);

    printf("Result %d * 5 = %d\n",x, x*5);

    return 0;
}
