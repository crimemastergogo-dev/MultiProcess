#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#define SIZE 50

struct array
{
    int arr[SIZE];
    int len;
};


int main(int argc,char *argv[])
{
    struct array Arr;
    printf("Enter size of array:");
    scanf("%d",&Arr.len);

    int start,end;
    int sum = 0;

    for(int i =0 ; i< Arr.len;i++)
    {
        printf("Enter element[%d]:",i);
        scanf("%d",&Arr.arr[i]);
    }

    int fd[2];

    if (pipe(fd)== -1)
    {
        printf("Error in openeing pipe");
    }

    int id = fork();
    if(id == -1)
    {
        printf("Error in forking");
        return 0;
    }
    if (id == 0)
    {
        start = 0;
        end = Arr.len/2; 
    }
    else
    {
        start = Arr.len/2;
        end = Arr.len;
    }

    for(int i = start;i< end;i++)
    {
        sum +=Arr.arr[i];
    }
    printf("Sum of for id[%d] : %d \n",id,sum);

    if (id == 0)
    {
        close(fd[0]);
        if (-1 == write(fd[1],&sum,sizeof(int)))
        {
            printf("Error in writing to the pipe");
        }
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int SumFromChild =  0;
        if (-1 == read(fd[0],&SumFromChild,sizeof(int)))
        {
            printf("Error in reading from the pipe");
        }

        printf("Total sum =  %d\n",sum+SumFromChild);
        close(fd[0]);
    }
    wait(NULL);
    return 0;
}
