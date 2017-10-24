#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> //library thread

void *faktorial( void *ptr );

int main()
{
     pthread_t thread1, thread2;//inisialisasi awal
     const char *message1 = "Thread 1";
    // const char *message2 = "Thread 2";
     int  iret1, iret2;

     iret1 = pthread_create( &thread1, NULL, faktorial, (void*) message1);//membuat thread pertama
     if(iret1)//jika eror
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }

    /* iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);//membuat thread kedua
     if(iret2)//jika gagal
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(EXIT_FAILURE);
     }*/

	printf("pthread_create() for thread 1 returns: %d\n",iret1);
    // printf("pthread_create() for thread 2 returns: %d\n",iret2);

     //pthread_join( thread1, NULL);
     //pthread_join( thread2, NULL); 

     exit(EXIT_SUCCESS);
}

void *faktorial( void *ptr )
{
     int num1,num2,num3,result,i;
     result=i=1;
     printf("Faktorial "); scanf ("%d", &num1);

	while (i<=num1) {
		result*=i;
		i++;
	}
	printf ("hasil %d ! = %d",num1,result);
}
