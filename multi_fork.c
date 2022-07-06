#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>



int main(int argc,char *argv[])
{

#if 0
    int id1 = fork();
    int id2 = fork();

    if ((id1 == 0 ) &&(id2 != 0))
        printf("process Y id1[%d] & id2[%d]\n",id1,id2);

    if ((id1 != 0 ) &&(id2 != 0))
        printf("process X id1[%d] & id2[%d]\n",id1,id2);

    if ((id1 != 0 ) &&(id2 == 0))
        printf("process A id1[%d] & id2[%d]\n",id1,id2);

    if ((id1 == 0 ) &&(id2 == 0))
        printf("process B id1[%d] & id2[%d]\n",id1,id2);

    while(wait(NULL) != -1 || errno != ECHILD)
    {
        printf("Process with id1[%d] & id2[%d] waiting for it's child to finish\n",id1,id2);
    }
#else
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    while(1);
#endif

    return 0;
}
