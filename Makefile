# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 12:13:47 by Hassan            #+#    #+#              #
#    Updated: 2022/12/29 17:50:30 by hrifi-la         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	./push_swap_folder/init_list.c \
		./push_swap_folder/action_piles_2.c \
		./push_swap_folder/main.c \
		./push_swap_folder/create_tab_int.c \
		./push_swap_folder/atoi.c \
		./push_swap_folder/action_piles_1.c \
		./push_swap_folder/all_algos.c \
		./ft_printf/actions.c \
		./ft_printf/ft_printf.c \

OBJS = $(SRCS:.c=.o)

RM = rm -f

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all