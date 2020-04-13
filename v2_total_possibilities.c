#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct list {
	int node1;
	int node2;
	int link1;
	int link2;
} List;

List** multilist;
int winner = 0;

int board();
void clean();

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

int pboard(int rolled)
{
	int num = rolled;
	moves1++;
	p1 = move(p1,num);
		if(p1 == 999) 
	{
		winner = 1;
		return 0;
	}
	return 0;
}

/*int board(int iroll[])
{
	pboard(iroll[0]);
	pboard(iroll[1]);
	pboard(iroll[2]);
	pboard(iroll[3]);
}*/

int board(int i, int j, int k, int l, int m, int n)
{
	pboard(i);
	if(winner) return 1;
	pboard(j);
	if(winner) return 2;
	pboard(k);
	if(winner) return 3;
	pboard(l);
	if(winner) return 4;
	pboard(m);
	if(winner) return 5;
	pboard(n);
	if(winner) return 6;
	return 0;
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


void start()
{
	winner = 0;
	clean();
}

int createMultiList() 
{ 	
	multilist = (List**)calloc(40,sizeof(List*));
	char *line = malloc(1024);
	char** r = malloc(1024);
	char *t = malloc(1024);
	int i = 0;
	int temp = 0;
	int ptemp = 0;
	FILE* data = fopen("30board.csv","r");
	while(fgets(line,1024,data))
	{
		t = strtok(line,",");
		i = strtol(t,r,10);
		multilist[i] = (List*)malloc(sizeof(List));
		multilist[i]->node1 = 0;
		multilist[i]->node2 = 0;
		multilist[i]->link1 = 0;
		multilist[i]->link2 = 0;
		if((t = strtok(NULL,",")) != "NULL") multilist[i]->node1 = strtol(t,r,10);
		if((t = strtok(NULL,",")) != "NULL") multilist[i]->node2 = strtol(t,r,10);
		if((t = strtok(NULL,",")) != "NULL") multilist[i]->link1 = strtol(t,r,10);
		if((t = strtok(NULL,",")) != "NULL") multilist[i]->link2 = strtol(t,r,10);
	}
	fclose(data);
	free(line);
	free(r);		
} 

int main() 
{
	int count = 0;
	int num;
	int s = 0;
	createMultiList();
	start();
	system("clear");
	for (int i = 1; i<=6;i++){
	for(int j=1;j<=6;j++){
	for(int k=1;k<=6;k++){
	for (int l=1;l<=6;l++){
	for (int m=1;m<=6;m++) {
	for (int n=1;n<=6;n++) {
	winner = 0;
 	createMultiList();
	start();
	s = board(i,j,k,l,m,n);
	if(winner){
		printf("%d %d %d %d %d %d\n",i,j,k,l,m,n);
		count++;
	}
	}}}}}}
	printf("Total number of possible wins in 6 moves is %d\n",count);
	for(int i=0;i<40;i++)
	{
		if(multilist[i]) free(multilist[i]);
	}
	free(multilist);
}
