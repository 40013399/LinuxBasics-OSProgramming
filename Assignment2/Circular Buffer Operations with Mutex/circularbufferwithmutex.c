#include "circularbufferwithmutex.h"
#define buffersize 5
#define maxitems 5

pthread_mutex_t mutex;
int into=0;
int out=0;
int buffer[buffersize];

void* producer(void* pro)
{
   int i;
   pthread_mutex_lock(&mutex);
   for (i = 0; i <= maxitems; i++) 
   {
   	while (((into + 1) % buffersize) == out);
     	buffer[into] = i;
     	printf("producer inserted item %d at %d\n",buffer[into],into);
     	into = (into + 1) % buffersize;
    }
    return NULL;
   pthread_mutex_unlock(&mutex);
}
void* consumer(void* con)
{
	pthread_mutex_unlock(&mutex);
	for (;;)
	 {
     		while (out == into);
     		int tmp;
     		tmp = buffer[out];
     		printf("consumer removed item %d from %d\n",buffer[out],out);
     		out = (out + 1) % buffersize; 
     	}
     	pthread_mutex_lock(&mutex);
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

