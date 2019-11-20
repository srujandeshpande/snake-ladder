#include "header.h"

List** multilist;
int winner = 0;

int board();
void clean();

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
	int num;
	createMultiList();
	start();
	system("clear");
	//system("eog snake-and-ladders.jpg");
	while(!winner) 
	{
		num = board();
		if(num == 0) {
			printf("Player %d wins!\n",winner);
		}
		if(num == 8)
		{
			system("clear");
			createMultiList();
			start();
		}
		if(num == 9) break;
	}
	for(int i=0;i<40;i++)
	{
		if(multilist[i]) free(multilist[i]);
	}
	free(multilist);
}
