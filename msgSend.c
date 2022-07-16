#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>

#define MAX_SIZE  512
typedef struct
{
    long int  text_size;  // must start with long int
    char some_text[MAX_SIZE]; 
}My_msg;

int main()
{
    My_msg message;

    key_t key = ftok("file",69);

    int running = 1;

    int msg_id = msgget(key,0666 | IPC_CREAT);

    if (-1 == msg_id)
    {
        printf("Message Queue craetion failed ...!!!\n");
        return 1;
    }

    do 
    {
        printf("Enter Message Type :");
        scanf("%ld ",&message.text_size);


        printf("Enter Message :");
        fgets(message.some_text,MAX_SIZE,stdin);


        if (-1 != msgsnd(msg_id, &message, sizeof(message), 0))
            printf("Message Sent :[%s]\n",message.some_text);
        else
            printf("Message sent Failed...!!!\n");

        if(0 == message.text_size)
            break;
    }while(running);

    return 0;
}
