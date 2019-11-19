#include "header.h"

List** multilist;
int winner = 0;

char board();
int createMultiList();
void start();
void endgame();

void endgame()
{
	for(int i=0;i<100;i++)
	{
		if(!multilist[i]) free(multilist[i]);
	}
	free(multilist);
}

void start()
{
	createMultiList();
	winner = 0;
	p1 = 0;
	p2 = 0;
	moves1 = 0;
	moves2 = 0;
	ff = 0;
}
	
int createMultiList() 
{ 	
	multilist = (List**)calloc(40,sizeof(List*));
	for(int i=0;i<100;i++) multilist[i] = NULL;
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
		multilist[i]->p1 = 0;
		multilist[i]->p2 = 0;
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
	startgame();
	system("clear");
	int ch;
	//system("eog snake-and-ladders.jpg");
	while(1) 
	{
		ch = board();
		if(ch == 'e' || ch == 'q')
		{
			endgame();
			break;
		}
		if(ch == 's')
		{
			endgame();
			startgame();
		}
	}
}
