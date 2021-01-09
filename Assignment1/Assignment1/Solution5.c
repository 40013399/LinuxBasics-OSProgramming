#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    pid_t ret;
    int status;
    ret=fork();
    if(ret < 0)
    {
        perror("fork");
        exit(1);
    }
    if(ret == 0)
    {
        int execute;                                                                                             
        execute = execl("/usr/bin/gcc","gcc","Solution1.c",NULL);   //to link and compile the code                           
        if(execute<0)
        {
            perror("execv");
            exit(2);
        }
        exit(0);

    }
    else
    {
        waitpid(-1,&status,0); 
        printf("parent--child exit status=%d\n",
			WEXITSTATUS(status));
		
    }
    return 0;

}


