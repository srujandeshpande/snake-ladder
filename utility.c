#include "header.h"

extern List** multilist;
extern int winner;

int p1 = 1;
int p2 = 1;

int ff = 0;

int move(int,int);
void dispboard();

void dispboard()
{
	printf("Roll:1, Fast-Forward:2, Quit:9\n");
	printf("+-----------------+\n");
	printf("|25|26|27|28|29|30|\n");
	printf("|24|23|22|21|20|19|\n");
	printf("|13|14|15|16|17|18|\n");
	printf("|12|11|10|09|08|07|\n");
	printf("|01|02|03|04|05|06|\n");
	printf("+-----------------+\n");
}

int roll()
{
	time_t tt;
	time(&tt);
	int tnum = (int)tt;
	srand(tnum);
	int rnum = rand();
	int num = rnum%6 +1;
	printf("You rolled a %d\n",num);
	return num;
}

int board()
{
	int playerch = 0;
	//system("clear");
	dispboard();
	printf("Player 1 is on: %d\n",multilist[p1]->node1);
	printf("Player 2 is on: %d\n",multilist[p2]->node1);
	printf("~~~~~~~~~~~~~~~~~~~");
	printf("Player 1's turn\n");
	if(!ff) scanf("%d",&playerch);
	if(playerch == 9) return playerch;
	if(playerch == 2) ff = 1;
	int num = roll();
	p1 = move(p1,num);
	if(p1 == 999) 
	{
		winner = 1;
		return 0;
	} 
	printf("Player 2's turn\n");
	num = roll();
	p2 = move(p2,num);
	if(p2 == 999) winner = 2;
	return playerch;
}

int move(int p, int num) 
{
	if(num > (30 - multilist[p]->node1)) return p; 
	if(num == 1 && multilist[p]->link1 != 0)
	{
		p = multilist[p]->link1;
		p = multilist[p]->link2;
		if(multilist[p]->node2 == 0) return 999;
		return p;
	}
	if(num == 1)
	{
		p = multilist[p]->link2;
		num--;
		if(multilist[p]->node2 == 0) return 999;
		return p;
	}
	while(num!=0)
	{
		p = multilist[p]->link2;
		num--;
		if(multilist[p]->node2 == 0) return 999;
		return move(p,num);
	}
	return p;
}
