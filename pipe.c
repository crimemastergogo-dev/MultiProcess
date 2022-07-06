#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>



int main(int argc,char *argv[])
{
    int fd[2];

    if (pipe(fd)== -1)
    {
        printf("Error in openeing pipe");
    }
    int id = fork();

    if (id == 0)
    {
        close(fd[0]);
        int x = 0;
        printf("Enter number : ");
        scanf("%d",&x);
        if (-1 == write(fd[1],&x,sizeof(int)))
        {
            printf("Error in writing to the pipe");
        }
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int y = 0;
        if (-1 == read(fd[0],&y,sizeof(int)))
        {
            printf("Error in reading from the pipe");
        }
        y = y*100 +22;

        printf("value recevied from child process : %d\n",y);
        close(fd[0]);
    }
    return 0;
}
