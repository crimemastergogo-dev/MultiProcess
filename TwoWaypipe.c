#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<time.h>



int main(int argc,char *argv[])
{
    int pc[2]; // p -->c
    int cp[2]; // c -->p

    if (pipe(pc)== -1)
    {
        printf("Error in openeing pipe");
    }
    if (pipe(cp)== -1)
    {
        printf("Error in openeing pipe");
    }
    int id = fork();
    if (id == -1){printf("Fork Failed ...!!!");}

    if (id == 0)
    {
        close(cp[0]);
        close(pc[1]);
        int x = 0;
        if (-1 ==read(pc[0],&x,sizeof(int)))
        {
            printf("Error in  reading from  the pipe");
        }
        printf("Child RCVD = %d \n",x);
        x *=4;
        if (-1 ==write(cp[1],&x,sizeof(int)))
        {
            printf("Error in writing to the pipe");
        }
        printf("child wrote = %d\n",x);
        close(cp[1]);
        close(pc[0]);
    }
    else
    {
        close(cp[1]);
        close(pc[0]);

        srand(time(NULL));

        int y = rand()%10;
        if (-1 ==write(pc[1],&y,sizeof(int)))
        {
            printf("Error in writing to the pipe");
        }
//        printf("parent wrote = %d\n",y);

        if (-1 == read(cp[0],&y,sizeof(int)))
        {
            printf("Error in reading from the pipe");
        }
        printf("parent RCVD = %d\n",y);
        close(cp[0]);
        close(pc[1]);
        wait(NULL);

    }
    return 0;
}
