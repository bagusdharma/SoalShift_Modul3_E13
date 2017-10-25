#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

struct tes {
	char input[50];
	int len,result;
};

void *cari (void *a);
void baca();

char str[5000];
int length;

int main(int argc,char *argv[]) {
	baca();
	if (argc > 1) {
		pthread_t tid[argc-1];
		struct tes tes1[argc-1];
		int err,i=0;
		while(i+1 < argc) {
	    		strcpy((tes1[i]).input,argv[i+1]);
			tes1[i].len=strlen(argv[i+1]);
			err=pthread_create(&(tid[i]),NULL,&cari,&(tes1[i]));//membuat thread
			if(err!=0) {
				printf("\n can't create thread : [%s]",strerror(err));
		        }
		        else {
			        //printf("\n create thread success\n");
	                }
		        pthread_join(tid[i],NULL);
			i++;
		}
		for(i=0;i<argc-1;i++) {
		       	printf("%s : %d\n",(tes1[i]).input,(tes1[i]).result);
		}
	}

	return 0;
}

void baca()
{
	FILE* bebas;
	bebas = fopen("Novel.txt","r");
	int i=0;
	char x;
	while(fscanf(bebas,"%c",&x) != EOF) {
		str[i] = x;
		i++;
	}
	length = i;
	fclose(bebas);
}


void *cari (void *a) {
	int i,result,j=0,count=0;
	result=i=0;
	struct tes *tes1 = (struct tes *)a;
	for (i=0;i<=length;i++) {
		if(str[i] == ((*tes1).input)[j]) {
			if(j == (*tes1).len-1) {
				count++;
				j=0;
			}
			else {
				j++;
			}
		}
	}
	(*tes1).result=count;

	return NULL;
}
