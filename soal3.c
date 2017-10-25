#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

int flag=0;
int lohan=100;
int kepiting=100;
pthread_t tid[2];

void* hewan(void *arg)
{
    pthread_t id=pthread_self();
    if (pthread_equal(id,tid[0]))
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

    else if (pthread_equal(id,tid[1]))
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

}

int main(void)
{
    int i=0;
    int err;
    while(i<2)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&hewan,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            printf("\n create thread success");
        }
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
