#iinclude "pipe.h"

void main() 
{
    int f1;
    f1 = mkfifo("FirstPipe",0666);
    if(f1<0)
        printf("\nFirstPipe was not created");
    else
        printf("\nFirstPipe created");
    int f2;
    f2 = mkfifo("SecondPipe",0666);
    if(f2<0)
        printf("\nSecondPipe was not created");
    else
        printf("\nSecondPipe is created\n");
}
