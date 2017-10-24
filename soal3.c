#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

int flag=0;
int lohan=100,kepiting=100;
pthread_t tid[2];

void* hewan(void *arg)
{
    if(pthread_equal(id,tid[0]))
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


}
