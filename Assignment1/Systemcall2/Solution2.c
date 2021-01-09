#include "Solution2.h"

int main()
{
    //OPEN A FILE FOR READING
    FILE* fd1;
    int lines=0,charecters=0,words=0;
    char c;
    fd1=fopen("exfile1.txt","r");
    printf("\nRet value of open = %d\n",fd1);
    if(fd1<0)
    {
        perror("open");
        exit(1);
    }
    while((c=fgetc(fd1))!=EOF)
    {
        charecters++;
        if(c=='\n'||c=='\0')
        {
            lines++;
        }
        if(c==' '||c=='\t'||c=='\n'||c=='\0')
        {
            words++;
        }
        
    }
    printf(" no of charecters is %d",charecters);
    printf(" no of words is %d",words);
    printf(" no of lines is %d",lines);
    fclose(fd1);
    return 0;
}


