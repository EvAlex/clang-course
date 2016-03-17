#include <stdio.h>
#include <conio.h>

#include "List.h"

void runLinkedListDemos();

int main()
{
	runLinkedListDemos();

	printf("Press <Enter> to exit");
	getch();

	return 0;
}

void runLinkedListDemos()
{
	List list = initList();

	push(list, 1);
	push(list, 2);
	push(list, 3);

	double d;
	bool res = pop(d, list);
	res = pop(d, list);
	res = pop(d, list);
	res = pop(d, list);

	push(list, 1);
	push(list, 2);
	push(list, 3);

	clear(list);

	res = get(d, list);
	push(list, 7);
	res = get(d, list);

	push(list, 8);
	push(list, 9);
	push(list, 10);
	push(list, 11);
	push(list, 12);

	Iterator i = begin(list);
}