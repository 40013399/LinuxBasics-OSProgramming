#include "clientserverexec.h"

int main()
{
	int ret,bytes;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqid;
	// Open a Message Queue in Client Process 
	mqid=mq_open("/mque1",O_RDONLY|O_CREAT,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char bufferval[8192];
	int maxlength=256,priority;
	bytes=mq_receive(mqid,bufferval,maxlength,&priority);
	if(bytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	bufferval[bytes]='\0';
	int k;
        printf("%s",bufferval);
	k=execlp("/usr/bin/cal","cal",bufferval,0);
               if(k<0)
		{
			perror("execlp");
			exit(1);
		}
		exit(5);
		
	printf("receive msg:%s,nbytes=%d,prio=%d\n",bufferval,bytes,priority);
	mq_close(mqid);
	return 0;
}

