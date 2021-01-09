#include "Solution8.h"

void* maxmin(void* sub_array)
{
    int* partarray = (int*)sub_array;
    int maxs=0;
    int mins=0;
    for(int i=0;i<10;i++)
    {
    	if(partarray[i]>maxs)
    	     maxs=partarray[i];
    	if(partarray[i]<mins)
             mins=partarray[i];
    }
    pthread_exit((void*)maxs);
    pthread_exit((void*)mins);

}
int main()
{
    int array[100];
    int maxvalue=0;
    int minvalue=0;
    void* maxs;
    void* mins;
    for(int i=0;i<=100;i++)
    {
        array[i]=i;
    }
    pthread_t threads[10];
    for(int i=0;i<10;i++)
    {
        int* sub_array=array + (i*10);
        pthread_create(&threads[i],NULL,maxmin,(void*) sub_array);
    }
    for(int i=0;i<10;i++)
    {
        pthread_join(threads[i],&maxs);
        pthread_join(threads[i],&mins);
        maxvalue=(int)maxs;
        minvalue=(int)mins;
    }
    printf("maxvalue is  = %d\n",maxvalue);
    printf("minvalue is  = %d\n",minvalue);
    return 0;
}




