#include <stdlib.h>
#include <stdio.h>

typedef struct list
{
	int val;
	int index;
	struct list *next;
} list;

void	addfront(list **pile, int *val, int index)
{
	list* element = malloc (sizeof(list));
	if(!element)
		return (0);
	element->
}

void	init_list (list **pile, int nb0)
{
	*pile = malloc (sizeof(list));
	(*pile)->index = 0;
	(*pile)->val = nb0;
	(*pile)->next = NULL;
}

int	main (int argc, char **argv)
{
	int i;
	list* pile;

	init_list(&pile, argv[0][0]);

	while (i < (argc - 1))
	{
		addfront(&pile, argv[argc - 1 - i], i);
		i++;
	}
}

