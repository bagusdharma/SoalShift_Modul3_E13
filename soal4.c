#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> //library thread

void *faktorial( void *ptr );

int main()
{
	pthread_t tid[2];
	int i = 0;
	int err;
	int input[2]={3,2};
	for (i=0;i<2;i++)
	{
	   err=pthread_create(&(tid[i]),NULL,&faktorial,&(input[i]));//membuat thread
	    if(err!=0) {
	        printf("\n can't create thread : [%s]",strerror(err));
            }
	    else {
	        //printf("\n create thread success\n");
            }
	    pthread_join(tid[i],NULL);
	}
}

void *faktorial( void *ptr )
{
     int i,result;
     result=i=1;
     int *x = (int *) ptr;
	printf ("%d",*x);

	while (i<=(*x)) {
		result*=i;
		i++;
	}
	return NULL;
	//printf ("hasil %d ! = %d",num1,result);
}

