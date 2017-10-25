#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

void main()
{
    int siapa;

    printf("Ketik 1 = interface untuk penjual\n");
    printf("Ketik 2 = interface untuk pembeli\n");

    scanf("%d",&siapa);


    if (siapa==1)
    {

	printf("Anda adalah penjual\n");
	key_t key = 1234;
	int *a1,*a2,*a3,*a4,*a5,*a6;

	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
	a1 = shmat(shmid, NULL, 0);
	a2 = shmat(shmid, NULL, 0);
	a3 = shmat(shmid, NULL, 0);
	a4 = shmat(shmid, NULL, 0);
	a5 = shmat(shmid, NULL, 0);
	a6 = shmat(shmid, NULL, 0);

	*a1=0; *a2=0; *a3=0; *a4=0; *a5=0; *a6=0;

	while (1)
	{
	    int buatpenjual=0;
	    printf("Ketik 1 = lihat stock\n");
	    printf("Ketik 2 = tambah stock\n");

	    scanf("%d",&buatpenjual);

	    if (buatpenjual==1)
	    {
		printf("MP4A1 = %d buah\n",*a1);
		printf("PM2-V1 = %d buah\n",*a2);
		printf("SPR-3 = %d buah\n",*a3);
		printf("SS2-V5 = %d buah\n",*a4);
		printf("SPG1-V3 = %d buah\n",*a5);
		printf("MINE = %d buah\n",*a6);
	    }

	    if (buatpenjual==2)
	    {
		char namanya[10];
		int jumlahnya;
		printf("Masukkan senjata yang ingin di-restock: ");
		scanf("%s",namanya);
		scanf("%d",&jumlahnya);
		if (strcmp(namanya,"MP4A1")==0) *a1+=jumlahnya;
		else if (strcmp(namanya,"PM2-V1")==0) *a2+=jumlahnya;
		else if (strcmp(namanya,"SPR-3")==0) *a3+=jumlahnya;
		else if (strcmp(namanya,"SS2-V5")==0) *a4+=jumlahnya;
		else if (strcmp(namanya,"SPG1-V3")==0) *a5+=jumlahnya;
		else if (strcmp(namanya,"MINE")==0) *a6+=jumlahnya;
		else printf("Senjata tidak tersedia\n");
	    }

	}

	shmdt(a1); shmdt(a2); shmdt(a3); shmdt(a4); shmdt(a5); shmdt(a6);
	shmctl(shmid, IPC_RMID, NULL);

    }
}
