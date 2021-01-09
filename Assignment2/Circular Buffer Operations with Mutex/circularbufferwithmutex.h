#ifndef __CIRCULARBUFFEROPERATIONSWITHMUTEX_H__
#define __CIRCULARBUFFEROPERATIONSWITHMUTEX_H__

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void* producer(void* pro);
void* consumer(void* con);


#endif

