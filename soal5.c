#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

struct tes {
	char input[50];
	int len,result;
};

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


