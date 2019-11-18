#include "header.h"

void displayBoard()
{
}

void roll()
{
	printf("Press r to roll\n");
	time_t tt;
	time(&tt);
	int tnum = (int)tt;
	srand(tnum);
	int rnum = rand();
	int num = rnum%6 +1;
	printf("%d\n",num);
}
