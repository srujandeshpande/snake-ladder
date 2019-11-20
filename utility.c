#include "header.h"
#include <time.h>

extern List** multilist;
extern int winner;

int p1 = 1;
int p2 = 1;

int first  = 1;

int moves1 = 0;
int moves2 = 0;

int ff = 0;
int prevroll = 0;
int prevroller = 0;

int move(int,int);
void dispboard();

void clean()
{
	moves1 = 0;
	moves2 = 0;
	p1 = 1;
	p2 = 1;
	ff = 0;
	prevroll = 0;
	prevroller = 0;
	first = 1;
}

void dispboard()
{
	printf("Roll:1, Fast-Forward:2, Restart: 8, Quit:9\n");
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
	if(first) 
	{
		time_t tt;
		time(&tt);
		unsigned int tnum = tt;
		srand(tnum);
		first = 0;
	}
	int rnum = rand();
	int num = rnum%6 +1;
	printf("You rolled a %d\n",num);
	return num;
}

int pboard(int p)
{
	int playerch = 0;
	system("clear");
	dispboard();
	printf("%d Moves - Player 1 is on: %d\n",moves1,multilist[p1]->node1);
	printf("%d Moves - Player 2 is on: %d\n",moves2,multilist[p2]->node1);
	printf("~~~~~~~~~~~~~~~~~~~\n");
	if(prevroll) printf("Player %d rolled a %d\n",prevroller,prevroll);
	printf("~~~~~~~~~~~~~~~~~~~\n");
	printf("Player %d's turn\n",p);
	if(!ff) scanf("%d",&playerch);
	if(playerch == 9 || playerch == 8) return playerch;
	if(playerch == 2) ff = 1;
	int num = roll();
	prevroll = num;
	prevroller = p;
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
	if(p==2)
	{
		moves2++;
		p2 = move(p2,num);
		if(p2 == 999) 
		{
			winner = 2;
			return 0;
		}
	}
	return 1;
}

int board()
{
	int r = pboard(1);
	if(r == 0 || r==8 || r==9) return r;
	r = pboard(2);
	if(r == 0 || r==8 || r==9) return r;
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
