#include "header.h"

List* multilist[40];

void createMultiList() 
{
	for(int i=0;i<40;i++) 
	{
		if(!multilist[i] = (List*)malloc(sizeof(List))) return 1);
		multilist[i]->visited = 0;
		multilist[i]->node1 = 0;
		multilist[i]->node2 = 0;
		multilist[i]->link1 = NULL;
		multilist[i]->link2 = NULL;
	}
} 

void populateMultiList()
{


}

int main() 
{
	if(createMultiList()) return 1;
	populateMultiList();
}
