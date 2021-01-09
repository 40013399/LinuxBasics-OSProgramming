#include "pipe.h"
void main() 
{
    char message[256]=""; 
    int fifo_write,fifo_read; 
    while(strcmp(message,"end")!=0)   
    {   
        fifo_write= open("FirstPipe",O_WRONLY);   
        if(fifo_write<0)     
            printf("\nError opening the pipe");   
        else     
        {     
            printf("Received message is: \n");     
            scanf("%s",message);     
            write(fifo_write,message,255*sizeof(char));     
            close(fifo_write);     
        }   
        fifo_read=open("SecondPipe",O_RDONLY);   
        if(fifo_read<0)     
            printf("\nError opening write pipe");   
        else     
        {     
            read(fifo_read,message,255*sizeof(char));     
            close(fifo_read);     
            printf("\n%s",message);     
        }   
    }
} 
