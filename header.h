#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list {
	int visited;
	int node1;
	int node2;
	struct list* link1;
	struct list* link2;
} List;
