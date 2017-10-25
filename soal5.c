#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void baca();

char str[5000];
int length;

int main(int argc,char *argv[]) {
	baca();
	printf ("%s",str);
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


