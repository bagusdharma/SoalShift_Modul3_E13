#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

int flag=0;
int lohan=100;
int kepiting=100;
pthread_t tid1,tid2;

void* fungsilohan(void *arg)
{
    while (lohan>0&&lohan<=100)
    {
	printf("Status lohan: %d\n",lohan);
	sleep(10);
	lohan-=15;
    }
    printf("Lohan mati\n");
    flag=1;
}

void* fungsikepiting(void *arg)
{
    while (kepiting>0&&kepiting<=100)
    {
	printf("Status kepiting: %d\n",kepiting);
	sleep(20);
	kepiting-=10;
    }
    printf("Kepiting mati\n");
    flag=1;
}

int main()
{
    pthread_create(&(tid1),NULL,&fungsilohan,NULL);
    pthread_create(&(tid2),NULL,&fungsikepiting,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
}
