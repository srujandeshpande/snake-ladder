#include "header.h"

int count = 0;

void fullcounter()
{
	while(ff!=100)
	
}


int pboard(int p)
{
	int playerch = 0;
	system("clear");
	dispboard();
	printf("~~~~~~~~~~~~~~~~~~~\n");
	printf("Player %d's turn\n",p);
	if(!ff) scanf("%d",&playerch);
	if(playerch == 9 || playerch == 8) return playerch;
	if(playerch == 2) ff = 1;
	int num = roll();
	if(p==1)
	{
		moves1++;
		p1 = move(p1,num);
		if(p1 == 999) 
		{
			winner = 1;
			return 0;
		}
	}
	return 1;
}
