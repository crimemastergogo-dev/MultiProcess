#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

#define MAX_SIZE  512
typedef struct
{
    long int  text_size;  // must start with long int
    char some_text[MAX_SIZE]; 
}My_msg;

int main()
{
    My_msg message;
    void *shared_region = NULL;

    key_t key = ftok("file",69);


    int shm_id = shmget(key,sizeof(message),0666);

    if (-1 == shm_id)
    {
        fprintf(stderr,"Shared Memory Creation failed ...!!!\n");
        return 1;
    }


    shared_region = shmat(shm_id,NULL,0);

    if (NULL != shared_region)
    {
        fprintf(stderr,"Shared region Attached at: %p \n");


        memcpy(&message,shared_region,sizeof(message));

        fprintf(stderr,"Message Rcvd\n Message Type  :[%d]\n",message.text_size);
        fprintf(stderr,"Message Sent :[%s]\n",message.some_text);
    }

    return 0;
}
