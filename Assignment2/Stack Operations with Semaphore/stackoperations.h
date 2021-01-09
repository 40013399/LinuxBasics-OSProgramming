#ifndef __STACKOPERATIONSWITHSEMAPHORE_H__
#define __STACKOPERATIONSWITHSEMAPHORE_H__

#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>

void* producer(void* pro);
void* consumer(void* con);

#endif
