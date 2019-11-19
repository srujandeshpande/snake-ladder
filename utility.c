#include "header.h"

extern List** multilist;
extern int winner;

int p1 = 1;
int p2 = 1;

int move(int,int);

int roll()
{
	printf("Press r to roll\n");
	getchar();
	getchar();
	time_t tt;
	time(&tt);
	int tnum = (int)tt;
	srand(tnum);
	int rnum = rand();
	int num = rnum%6 +1;
	printf("You rolled a %d\n",num);
	return num;
}

void board()
{
	printf("---------------------------------------------------------------\n");
	printf("Player 1 is on place %d\n",multilist[p1]->node1);
	printf("Player 2 is on place %d\n",multilist[p2]->node1);
	printf("Player 1's turn\n");
	int num = roll();
	p1 = move(p1,num);
	if(p1 == 999) 
	{
		winner = 1;
		return;
	} 
	printf("Player 2's turn\n");
	num = roll();
	p2 = move(p2,num);
	if(p2 == 999) winner = 2;
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
