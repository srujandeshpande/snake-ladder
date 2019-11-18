#include "header.h"

List* multilist[40];

void roll();

int createMultiList() 
{
	for(int i=0;i<40;i++) 
	{
		multilist[i] = (List*)malloc(sizeof(List));
		multilist[i]->visited = 0;
		multilist[i]->node1 = 0;
		multilist[i]->node2 = 0;
		multilist[i]->link1 = NULL;
		multilist[i]->link2 = NULL;
	}
} 

void populateMultiList()
{
	(multilist[1])->node1 = 1;
	multilist[1]->node2 = 2;
	multilist[1]->link2 = multilist[2];
	multilist[2]->node1 = 2;
	multilist[2]->node2 = 3;
	multilist[2]->link1 = multilist[3];
	multilist[2]->link2 = multilist[4];
	//TODO...
}

int main() 
{
	//if(createMultiList()) return 1;
	//populateMultiList();
	roll();
	
}
