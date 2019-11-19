#include "header.h"

extern List** multilist;
extern int winner;

int p1 = 1;
int p2 = 1;

int moves1 = 0;
int moves2 = 0;

int ff = 0;

int move(int,int);
void dispboard();

void dispboard()
{
	printf("Roll:r, Quit:q, Fast-Forward:f, Restart:s\n");
	printf("+-----------------+\n");
	printf("|25|26|27|28|29|30|\n");
	printf("|24|23|22|21|20|19|\n");
	printf("|13|14|15|16|17|18|\n");
	printf("|12|11|10|09|08|07|\n");
	printf("|01|02|03|04|05|06|\n");
	printf("+-----------------+\n");
	printf("Player 1 is on: %d after %d moves\n",multilist[p1]->node1, moves1);
	printf("Player 2 is on: %d after %d moves\n",multilist[p2]->node1, moves2);
}

int roll(int ch)
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

char board()
{
	system("clear");
	dispboard();
	printf("~~~~~~~~~~~~~~~~~~~");
	printf("Player 1's turn\n");
	if(!ch) char ch = getchar();
	getchar();
	if(ch == 'q' or ch == 's') return ch;
	int num = roll();
	moves1++;
	p1 = move(p1,num);
	if(p1 == 999) 
	{
		winner = 1;
		printf("Player 1 wins!\n",winner);
		return 'e';
	} 
	system("clear");
	dispboard();
	printf("~~~~~~~~~~~~~~~~~~~");
	printf("Player 2's turn\n");
	if(!ch) char ch = getchar();
	getchar();
	if(ch == 'q' or ch == 's') return ch;
	num = roll();
	moves2++;
	p2 = move(p2,num);
	if(p2 == 999) 
	{
		winner = 2;
		printf("Player 2 wins!\n",winner);
		return 'e';
	}
}

int move(int p, int num) 
{
	if(multilist[p]->node2 == 0)
	{
		return 999;
	}
	if(num > (30 - multilist[p]->node1)) return p; 
	if(num == 1 && multilist[p]->link1 != 0)
	{
		p = multilist[p]->link1;
		p = multilist[p]->link2;
		return p;
	}
	if(num == 1)
	{
		p = multilist[p]->link2;
		return p;
	}
	while(num!=0)
	{
		p = multilist[p]->link2;
		num--;
		return move(p,num);
	}
}
