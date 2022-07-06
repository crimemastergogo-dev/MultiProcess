#include <stdio.h>
#include <string.h>


int main()
{

    FILE *writePoniter = NULL;


    char data[100] = "New File Created via c program and now entering data in it";

    writePoniter = fopen("newFile.txt","w");

    if (writePoniter == NULL)
    {
        printf("Text file opening failed in writing mode ...!!!");
    }
    else
    {
        printf("Text file opened ...!!!\n");

        if (strlen(data)> 0 )
        {
            fputs(data,writePoniter);
        }
    }

    fclose(writePoniter);

    FILE *readPoniter = NULL;
    readPoniter = fopen("newFile.txt","r");

    char data1[100]; 
    if (readPoniter == NULL)
    {
        printf("Text file opening failed in reading mode...!!!");
    }
    while( fgets(data1,100,readPoniter) !=NULL)
    {
        printf("Data in the file = %s",data1);

    }

    fclose(readPoniter);

    return 0;
}
