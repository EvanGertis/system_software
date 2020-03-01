//demonstrates using struct and pointer to achieve linked lists
#include <stdio.h>

struct list { int data; struct list *pnext;};

void printlist(struct list *pl)
{
	while(pl!=NULL)
	{
		printf("%d\n",pl->data);
		pl=pl->pnext;
	}
}

int main() {
	struct list a,b;
	a.data=5; b.data=7;
	a.pnext=&b;
	b.pnext=NULL;
	
	printlist(&a);//now a is head of a list containing two elements
	return 0;
}
