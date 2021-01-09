#ifndef __CIRCULARBUFFEROPERATIONSWITHSEMAPHORE_H__
#define __CIRCULARBUFFEROPERATIONSWITHSEMAPHORE_H__

#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>

void* producer(void* pro);
void* consumer(void* con);

#endif
