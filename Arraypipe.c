#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<time.h>

#define size 100


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
        int arr[size] = {0};
        srand(time(NULL));
        int len  = rand()%11; 
        if (-1 ==write(fd[1],&len,sizeof(int)))
        {
            printf("Error in writing to the pipe");
        }
        for (int idx = 0; idx < len ; idx++)
        {
            arr[idx] = rand()%10; 
        }
        if (-1 ==write(fd[1],arr,len * sizeof(int)))
        {
            printf("Error in writing to the pipe");
        }
        printf("child wrote -->\n");
        for (int idx = 0; idx < len ; idx++)
        {
            printf("arr[%d] = %d \n",idx,arr[idx]) ; 
        }
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int arr[size] = {0};
        int len = 0;
        if (-1 == read(fd[0],&len,sizeof(int)))
        {
            printf("Error in reading from the pipe");
        }
        if (-1 == read(fd[0],arr,len * sizeof(int)))
        {
            printf("Error in reading from the pipe");
        }
        close(fd[0]);
        int sum = 0;
        for (int idx = 0; idx < len ; idx++)
        {
            sum +=arr[idx];
        }

        printf("parent calculates  len = %d sum  = %d\n",len,sum);
        wait(NULL);

    }
    return 0;
}
