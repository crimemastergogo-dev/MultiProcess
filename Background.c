#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>



int main(int argc,char *argv[])
{
    int x = 0;
    printf("Input number : ");
    scanf("%d",&x);

    printf("Result %d * 5 = %d\n",x, x*5);

#if 0
    int id = fork();
    if (id == 0)
    {
    }
    else
    {
    }
#endif

    return 0;
}
