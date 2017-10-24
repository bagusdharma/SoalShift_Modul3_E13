#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> //library thread

void *faktorial( void *ptr );
struct data {
	int input, result;
};

int main(int argc, char *argv[])
{
	pthread_t tid[2];
	int i = 0;
	int err;
	struct data data1[2];
	for (i=0;i<2;i++)
	{
	   data1[i].input = argv[i+1][0]-'0';
	   err=pthread_create(&(tid[i]),NULL,&faktorial,&(data1[i]));//membuat thread
	    if(err!=0) {
	        printf("\n can't create thread : [%s]",strerror(err));
            }
	    else {
	        //printf("\n create thread success\n");
            }
	    pthread_join(tid[i],NULL);
	}
	for (i=0;i<2;i++)
	{
	   printf("Hasil %d! = %d\n",data1[i].input,data1[i].result);
	}
}

void *faktorial( void *ptr )
{
     	int i,result;
     	result=i=1;
	struct data *x = (struct data *) ptr;
//	printf ("%d",*x);

	while (i<=(*x).input) {
		result*=i;
		i++;
	}
	(*x).result = result;

	return NULL;
	//printf ("hasil %d ! = %d",num1,result);
}

