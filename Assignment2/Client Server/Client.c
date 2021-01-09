#include "ClientServer.h"

int main()
{
	int ret, bytes;
	mqd_t mqid;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	// Open a Message Queue in Client Process 
	mqid=mq_open("/mque",O_CREAT | O_RDWR,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}

	char message[40] = "ABCApurvaSamudralaBB";
	//Send a message to Queue 
	ret=mq_send(mqid,message,40,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}

	char buffer[8192];
	int maxlength=256,priority;
	// Receive the message from Server through Queue 
	bytes=mq_receive(mqid,buffer,maxlength,&priority);
	if(bytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buffer[bytes]='\0';
	printf("message received from server is : %s\n",buffer);
	// Close the Queue 
	mq_close(mqid);

	return 0;
}

