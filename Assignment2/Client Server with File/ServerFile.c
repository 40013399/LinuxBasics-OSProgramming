#include "ClientServerwithfile.h"


int main()
{
	int ret,bytes;
	struct mq_attr attr;
	struct stat sb;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqid;
	// Open a Message Queue in Server Process 
	mqid=mq_open("/mque",O_CREAT | O_RDWR,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}

	char bufferval[20];
	int maxlength=256,priority;
	/* Receive a message from Queue */
	printf("Waiting for message from Client .......\n");
	bytes=mq_receive(mqid,bufferval,1024,&priority);
	if(bytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	/* Getting file attributes */
	lstat(bufferval, &sb);
	/* Send back the attributes message to Client through Queue */
	ret = mq_send(mqid,(const char *)&sb,sizeof(sb),100);
	if(ret < 0)
	{
		perror("mq_send");
		exit(2);
	}
	/* Close the Queue */
	mq_close(mqid);
	return 0;
}


