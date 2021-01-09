#include "circularbuffer.h"

#define buffersize 5
#define maxitems 5

sem_t empty;
sem_t full;
int into=0;
int out=0;
int buffer[buffersize];

void* producer(void* pro)
{
   int i;
   sem_wait(&empty);
   for (i = 0; i <= maxitems; i++) 
   {
   	while (((into + 1) % buffersize) == out);
     	buffer[into] = i;
     	printf("producer inserted item %d at %d\n",buffer[into],into);
     	into = (into + 1) % buffersize;  
     	sem_post(&full);   
    }
    return NULL;
}
void* consumer(void* con)
{	
	for (;;)
	 {
	 	sem_wait(&full);
     		while (out == into);
     		int tmp;
     		tmp = buffer[out];
     		printf("consumer removed item %d from %d\n",buffer[out],out);
     		out = (out + 1) % buffersize;     	
	}
	sem_post(&empty);
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

