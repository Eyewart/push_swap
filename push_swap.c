#include <stdlib.h>
#include <stdio.h>

/*
STILL TO DO:
ft_is_duplicate
*/

typedef struct list
{
	int val;
	struct list *next;
} list;

void addfront ()

void	fill_list(list **pile, int *p, int N)
{
	list* element = malloc (sizeof(list));
	if(!element)
		return (0);
	element->
}

void	init_list (list **pile, int nb0)
{
	*pile = malloc (sizeof(list));
	(*pile)->val = nb0;
	(*pile)->next = NULL;
}

int* ft_make_tab(int N, char **arg)
{
	int* tab;
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < N)
	{
		while (arg[i][j] != 0 )
		{
			
		}
		i++;
	}
}

int	main (int argc, char **argv)
{
	list* pile;
	int* pile;
	pile = ft_make_tab(argv, argc);
	ft_init_list(&pile, argv[0][0]);
	ft_fill_list(&pile, argv[0], argc);
}

