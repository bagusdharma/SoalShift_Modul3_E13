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
	if (argc > 1) {
		pthread_t tid[argc-1];
		int i,err;
		struct data data1[argc-1];
		for (i=0;i<argc-1;i++)
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
		for (i=0;i<argc-1;i++)
		{
	   	   printf("Hasil %d! = %d\n",data1[i].input,data1[i].result);
		}

	}
	else {
		printf ("Input error");
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

