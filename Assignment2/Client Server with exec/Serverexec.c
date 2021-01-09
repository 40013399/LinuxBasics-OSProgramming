#include "clientserverexec.h"

int main()
{
	int ret;
	mqd_t mqid;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	// Open a Message Queue in Server Process 
	mqid=mq_open("/mque1",O_WRONLY|O_CREAT,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char value[]="2020";
	int len=strlen(value);
	ret=mq_send(mqid,value,len+1,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(mqid);
	return 0;
}
