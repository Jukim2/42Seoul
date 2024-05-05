# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 18:10:56 by jukim2            #+#    #+#              #
#    Updated: 2023/02/13 12:05:43 by jukim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = commands/push.c commands/reverse.c commands/rotate.c commands/swap.c 	\
stack/stack.c main/main.c main/utils.c main/split_expand.c algorithm/mini_sort.c\
algorithm/sort.c algorithm/move_to_b.c algorithm/move_to_a.c algorithm/pick_r.c \
algorithm/pick_rr.c argument/get_argument.c argument/num_lst.c 					\
argument/convt_argument.c
BONUS_FILES = commands/push_bonus.c commands/reverse_bonus.c 					\
commands/rotate_bonus.c commands/swap_bonus.c stack/stack_bonus.c 				\
checker/checker_bonus.c checker/utils_bonus.c checker/split_expand_bonus.c 		\
argument/get_argument_bonus.c argument/num_lst_bonus.c 	checker/main_bonus.c 	\
argument/convt_argument_bonus.c
SRCS = $(addprefix srcs/, $(FILES))
B_SRCS = $(addprefix bonus/, $(BONUS_FILES))
OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror
NAME = push_swap
CHECK = checker
LIBFT = libft.a
LIB = ./libft/libft.a

.PHONY : clean bonus all fclean re

all : $(NAME)

bonus : $(CHECK)

$(NAME): $(LIBFT) $(OBJS) 
	cp $(LIB) $(LIBFT)
	$(CC) -o $(NAME) $(CCFLAGS) $(OBJS) $(LIBFT)

$(CHECK): $(LIBFT) $(B_OBJS)
	cp $(LIB) $(LIBFT)
	$(CC) -o $(CHECK) $(CCFLAGS) $^ $(LIBFT)

$(LIBFT) : 
	make bonus -C ./libft

%.o : %.c
	$(CC) $(CCFLAGS) -c  -o $@ $<

clean :
	make -C ./libft fclean
	rm -f $(OBJS) $(B_OBJS) $(LIBFT)

fclean : clean
	rm -f $(NAME) $(CHECK)

re : fclean all
