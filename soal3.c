#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

int flag=0,lohan=100,kepiting=100,input=0,inpstatus=0;
pthread_t tid1,tid2,tid3,tid4;

void* fungsilohan(void *arg)
{
    while (lohan>0&&lohan<=100)
    {
	printf("Status lohan: %d\n",lohan);
	sleep(10);
	lohan-=15;
    }
    if (lohan<=0) printf("Lohan mati\n");
    flag=1;
    return NULL;
}

void* fungsikepiting(void *arg)
{
    while (kepiting>0&&kepiting<=100)
    {
	printf("Status kepiting: %d\n",kepiting);
	sleep(20);
	kepiting-=10;
    }
    if (kepiting<=0) printf("Kepiting mati\n");
    flag=1;
}

void* fungsiinput(void *arg)
{
    printf("Ketik 1 = beri makan lohan\n");
    printf("Ketik 2 = beri makan kepiting\n");

    while (flag!=1)
    {
	scanf("%d",&input);
    }
}

void* fungsioutput(void *arg)
{
    while (flag!=1)
    {
	while (input==1)
	{
	    lohan+=10;
	    if (lohan>100)
	    {
		printf("Status lohan di atas 100\n");
		flag=1; break;
	    }
	    printf("Status lohan: %d\n",lohan);
	    input=0;
	}
	while (input==2)
	{
	    kepiting+=10;
	    if (kepiting>100)
	    {
		printf("Status kepiting di atas 100\n");
		flag=1; break;
	    }
	    printf("Status kepiting: %d\n",kepiting);
	    input=0;
	}
    }
}

int main()
{
    pthread_create(&(tid1),NULL,&fungsilohan,NULL);
    pthread_create(&(tid2),NULL,&fungsikepiting,NULL);
    pthread_create(&(tid3),NULL,&fungsiinput,NULL);
    pthread_create(&(tid4),NULL,&fungsioutput,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);

}
