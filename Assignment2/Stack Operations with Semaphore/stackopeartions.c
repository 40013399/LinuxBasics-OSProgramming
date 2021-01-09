#include "stackoperations.h"
#define buffersize 5
#define maxitems 5

sem_t empty;
sem_t full;
int into=0;
int out=0;
int buffer[buffersize];


void* producer(void* pro)
{
	if (into == buffersize - 1) {
    printf("buffer is full \n");
  } 
  else {
		sem_wait(&empty);
		for(into=0;into<maxitems;into++)
		{
			int item=rand();
			buffer[into]=item;
			printf("producer inserted item %d at %d\n",buffer[into],into);
		}
			
		into=(into+1)%buffersize;
		sem_post(&full);
		
	}
}
void* consumer(void* con)
{
	if (out == buffersize - 1) {
    printf("buffer is empty\n");
  } 
  else {
		sem_wait(&full);
		int item;
		for(int out=0;out<maxitems;out++)
		{
			item=buffer[out];
			printf("consumer removed item %d from %d\n",buffer[out],out);
		}	
		out=(out+1)%buffersize;
		sem_post(&empty);
	}
}

int main()
{
	pthread_t pro,con;
	sem_init(&empty,0,buffersize);
	sem_init(&full,0,0);
	
	pthread_create(&pro,NULL,producer,NULL);
	pthread_create(&con,NULL,consumer,NULL);
	
	pthread_join(pro,NULL);
	pthread_join(con,NULL);
	
	sem_destroy(&empty);
	sem_destroy(&full);
	
	return 0;
	
}		
