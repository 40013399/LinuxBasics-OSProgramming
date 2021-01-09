#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//OPEN A FILE FOR READING
	int fd1,nbytes;
	fd1=open("exfile1.txt",O_RDONLY);
	printf("\nRet value of open = %d\n",fd1);
	if(fd1<0)
	{
		perror("open");
		exit(1);
	}
	int length=128;
	char buffer[length];
	nbytes=read(fd1,buffer,length);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
	printf("nbytes=%d\n,buffer=%s\n",nbytes,buffer);
	
	//OPEN A FILE FOR WRITING
	int fd,numofbytes;
	fd=open("exfile.txt",O_WRONLY|O_CREAT, 0666);//filedescriptor
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	numofbytes=write(fd, buffer, length);//number of bytes
	if(numofbytes<0)
	{
		perror("write");
		exit(2);
	}
	printf("written successfully,numofbytes=%d\n",numofbytes);
	
	
	
	close(fd);
	close(fd1);
	
	return 0;	//exit(0);
}

