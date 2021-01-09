#include "stackeoperationswithmutex.h"

#define buffersize 5
#define maxitems 5
pthread_mutex_t mutex;

int into=0;
int out=0;
int buffer[buffersize];


void* producer(void* pro)
{
	if (into == buffersize - 1) {
    printf("Producer Stack is full \n");
  } 
  else 
  {
		 pthread_mutex_lock(&mutex);
		for(into=0;into<maxitems;into++)
		{
			int item=rand();
			buffer[into]=item;
			printf("producer inserted item %d at %d\n",buffer[into],into);
		}
			
		into=(into+1)%buffersize;
		 pthread_mutex_unlock(&mutex);
		
	}
}
void* consumer(void* con)
{
	if (out == buffersize - 1) {
    printf("Consumer Stack is full\n");
  } 
  else {
		pthread_mutex_lock(&mutex);
		int item;
		for(int out=0;out<maxitems;out++)
		{
			item=buffer[out];
			printf("consumer removed item %d from %d\n",buffer[out],out);
		}	
		out=(out+1)%buffersize;
		 pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_t pro,con;
	pthread_mutex_init(&mutex, NULL);
	
	pthread_create(&pro,NULL,producer,NULL);
	pthread_create(&con,NULL,consumer,NULL);
	
	pthread_join(pro,NULL);
	pthread_join(con,NULL);
	pthread_mutex_destroy(&mutex);
	
	return 0;
	
}		
