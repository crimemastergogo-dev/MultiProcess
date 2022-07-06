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

    int arr[5];
    int fd = open("sum",O_RDONLY);
    if (fd == -1)
    {
        printf("opening on fifo failed....!!!\n");
        return 1;
    }

    if (read(fd,arr,5 *sizeof(int)) == -1)
    {
        printf("reading on fifo failed....!!!\n");
        return 2;
    }

    close(fd);

    int sum = 0;
    for (int i = 0; i < 5;i++)
    {
        sum += arr[i];
    }

    printf("sum = %d\n",sum);
    fd = open("sum",O_WRONLY);

    if (fd == -1)
    {
        printf("opening on fifo failed....!!!\n");
        return 1;
    }
    if (write(fd,&sum,sizeof(int)) == -1)
    {
        printf("writing on fifo failed....!!!\n");
        return 2;
    }
    close(fd);

    return 0;
}
