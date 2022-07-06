#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<time.h>

#define size 200


int main(int argc,char *argv[])
{
    int fd[2]; 

    if (pipe(fd)== -1)
    {
        printf("Error in openeing pipe");
    }
    int id = fork();
    if (id == -1){printf("Fork Failed ...!!!");}

    if (id == 0)
    {
        close(fd[0]);
        char str[size];
        printf("Input string :");
        fgets(str,size,stdin);
        str[strlen(str) - 1] = '\0';

        int len = strlen(str)+1;

        if (-1 ==write(fd[1],&len,sizeof(int)))
        {
            printf("Error in writing to the pipe");
        }
        if (-1 ==write(fd[1],str, len * sizeof(char)))
        {
            printf("Error in writing to the pipe");
        }
        printf("child wrote -->%s\n",str);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        char str[size];
        int len = 0;

        if (-1 == read(fd[0],&len,sizeof(int)))
        {
            printf("Error in reading from the pipe");
        }
        if (-1 == read(fd[0],str,len * sizeof(char)))
        {
            printf("Error in reading from the pipe");
        }

        close(fd[0]);

        printf("parent rcvd  strlen = %d string  = %s\n",len,str);
        wait(NULL);

    }
    return 0;
}
