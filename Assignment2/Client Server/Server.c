#include "ClientServer.h"

int main()
{
	int ret,bytes;
	mqd_t mqid;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	// Open a Message Queue in Server Process 
	mqid=mq_open("/mque",O_CREAT | O_RDWR,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}

	char buffer[8192];
	int maxlength=256,priority;
	// Receive a message from Queue 
	printf("Waiting for message from Client .......\n");
	bytes=mq_receive(mqid,buffer,maxlength,&priority);
	if(bytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buffer[bytes]='\0';
	printf("msg from client : %s\n",buffer);

	// Toogle the message received 
	for (int i=0; buffer[i]!='\0'; i++)
    	{
        	if (buffer[i]>='A' && buffer[i]<='Z')
            		buffer[i] = buffer[i] + 'a' - 'A';
        	else if (buffer[i]>='a' && buffer[i]<='z')
            		buffer[i] = buffer[i] + 'A' - 'a';
    	}

	// Send back the processed message to Client through Queue 
	ret = mq_send(mqid,buffer,100,100);
	if(ret < 0)
	{
		perror("mq_send");
		exit(2);
	}
	// Close the Queue 
	mq_close(mqid);
	return 0;
}

