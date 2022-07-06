#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>



int main(int argc,char *argv[])
{

    if (mkfifo("NamedFile_fifo",0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("Opening fifo failed....!!!\n");
            return 1;
        }
    }

    int fd = open("NamedFile_fifo",O_WRONLY);

    int x = 97;

    if (write(fd,&x,sizeof(x)) == -1)
    {
        printf("writing on fifo failed....!!!\n");
        return 2;
    }
    close(fd);


    return 0;
}
