#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    pid_t c1,c2,c3;
    int exec_code1,exec_code2,exec_code3;
    c1=fork();
    switch(c1)
    {
    	case(-1):
    	{
        	perror("fork");
        	exit(1);
        }
        case(0):
        {
        	exec_code1 = execl("/usr/bin/gcc","gcc","-c","test.c","sumsquare.c",NULL);
        	if(exec_code1<1)
        	{
            		perror("execl");
            		exit(2);
        	}
        	break;
        }
        default:
        {
        	waitpid(-1,0,0);
        	printf("compilation success\n");
        	c2=fork();
        	break;
        }
     }
     
    switch(c2)
    {
    case(-1):
        perror("fork");
        exit(1);
    case(0):
        exec_code3 = execl("/usr/bin/gcc","gcc","test.o","sumsquare.o",NULL);
        if(exec_code3<1)
        {
            perror("execl");
            exit(2);
        }
        break;
    default:
        waitpid(-1,0,0);
        printf("library link success\n");
        c3=fork();
        break;

    }
    switch(c3)
    {
    case(-1):
        perror("fork");
        exit(1);
    case(0):
        
        exec_code2 = execl("./a.out",NULL);
        if(exec_code2<1)
        {
            perror("execl");
            exit(2);
        }
        break;
    default:
        waitpid(-1,0,0);
        printf("execution success\n");
        break;
    }
}
    

