#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> //library thread

void *faktorial( void *ptr );

int main(int argc, char *argv[])
{
	pthread_t tid[2];
	int i = 0;
	int err;
	int input[2];
	for (i=0;i<2;i++)
	{
	   input[i] = argv[i+1][0]-'0';
	   err=pthread_create(&(tid[i]),NULL,&faktorial,&(input[i]));//membuat thread
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
	   printf("%d\n",input[i]);
	}
}

void *faktorial( void *ptr )
{
     	int i,result;
     	result=i=1;
	int *x = (int *) ptr;
//	printf ("%d",*x);

	while (i<=(*x)) {
		result*=i;
		i++;
	}
	*x = result;

	return NULL;
	//printf ("hasil %d ! = %d",num1,result);
}

