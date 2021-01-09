#ifndef __STACKOPERATIONSWITHMUTEX_H__
#define __STACKOPERATIONSWITHMUTEX_H__

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>


void* producer(void* pro);
void* consumer(void* con);

#endif
