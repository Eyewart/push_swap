/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:00:30 by hrifi-la          #+#    #+#             */
/*   Updated: 2022/12/29 13:41:32 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct list
{
	int val;
	struct list *next;
} list;

int	ft_atoi(const char *str);
void	ft_push(list **pileA, list **pileB, char c);
void	ft_rotate(list **pile);
void	ft_swap(list **pile);
void	ft_reverse_rotate(list **pile);
void	ft_display_list(list *ptr);
int	ft_is_sorted(list* pile);
int	ft_size_list(list** pile);
void	ft_shortsort(list** pileA, list** pileB);
void	ft_algo_23(list** pile);
void	ft_radix(list **pileA, list** pileB, int nb_elements, int nb_bits);
int		ft_get_min(list **pile);
int		ft_get_max(list **pile);
int	ft_isdigit(int c);
size_t	ft_strlen(const char *c);
void ft_exit();
int	ft_atoi(const char *str);
int*	ft_make_tab(int N, char **arg);
void	ft_bubblesort(int** list_int, int size);
int*	ft_copy_tab(int* list_int, int size);
void	ft_fill_list(list **pile, int *p_int, int N);
void	ft_init_list (list** pile);
void	ft_addfront(list **pile, int value);
int	ft_is_duplicate(int* list_int, int size);
unsigned int ft_count_bits (int n);
int*	ft_sort_indexes(int* sorted_tab, int* saved_tab, int size);
void	ft_decision_3(list** pileA, list** pileB, int nb_elements);
int	ft_printf(const char *c, ...);