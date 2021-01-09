#include "Solution7.h"


void* sumfn(void* sub_array)
{
    int* partarray = (int*)sub_array;
    int sum=0;
    for(int i=1;i<=10;i++)
    {
    
        sum+=partarray[i];
    }
    pthread_exit((void*)sum);

}
int main()
{
    int array[100]={};
    int finalsum=0;
    void* sum;
    for(int i=0;i<=100;i++)
    {
        array[i]=i;
    }
    pthread_t threads[10];
    for(int i=0;i<10;i++)
    {
        int* sub_array=array + (i*10);
        pthread_create(&threads[i],NULL,sumfn,(void*) sub_array);
    }
    for(int i=0;i<10;i++)
    {
        pthread_join(threads[i],&sum);
        finalsum+=(int)sum;
    }
    printf("total = %d\n",finalsum);
    return 0;
}
