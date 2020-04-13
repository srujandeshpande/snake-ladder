#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void start();
int createMultiList();
void clean();
void dispboard();
int roll();
int pboard(int);
int board();
int move(int,int);

typedef struct list {
	int node1;
	int node2;
	int link1;
	int link2;
} List;
