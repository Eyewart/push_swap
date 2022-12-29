/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:00:30 by hrifi-la          #+#    #+#             */
/*   Updated: 2022/12/29 16:47:14 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				val;
	struct s_list	*next;
}	t_list;

int				ft_atoi(const char *str);
void			ft_push(t_list **pileA, t_list **pileB, char c);
void			ft_rotate(t_list **pile);
void			ft_swap(t_list **pile);
void			ft_reverse_rotate(t_list **pile);
void			ft_display_list(t_list *ptr);
int				ft_is_sorted(t_list *pile);
int				ft_size_list(t_list **pile);
void			ft_shortsort(t_list **pileA, t_list **pileB);
void			ft_algo_23(t_list **pile);
void			ft_radix(t_list **pileA, t_list **pileB, int nb_elements,
					int nb_bits);
int				ft_get_min(t_list **pile);
int				ft_get_max(t_list **pile);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *c);
void			ft_exit(void);
int				ft_atoi(const char *str);
int				*ft_make_tab(int N, char **arg);
void			ft_bubblesort(int **list_int, int size);
int				*ft_copy_tab(int *list_int, int size);
void			ft_fill_list(t_list **pile, int *p_int, int N);
void			ft_init_list(t_list **pile);
void			ft_addfront(t_list **pile, int value);
int				ft_is_duplicate(int *list_int, int size);
unsigned int	ft_count_bits(int n);
int				*ft_sort_indexes(int *sorted_tab, int *saved_tab, int size);
void			ft_decision_3(t_list **pileA, t_list **pileB, int nb_elements);
int				ft_printf(const char *c, ...);
void			ft_free_list(t_list **pile);
void			ft_free_lists(t_list **pile1, t_list **pile2);

#endif
