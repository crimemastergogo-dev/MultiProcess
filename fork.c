#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>



int main(int argc,char *argv[])
{

    int id = fork();
     id = fork();
    if (id == 0)
    {
        printf("child Proces says hello !!! id =%d \n",id);
        while(1);
    }
    else
    {
        printf("parent Proces says hello !!! id =%d \n",id);
        while(1);
    }


    return 0;
}
