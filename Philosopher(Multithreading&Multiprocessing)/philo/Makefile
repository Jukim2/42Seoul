# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 18:10:56 by jukim2            #+#    #+#              #
#    Updated: 2023/08/22 11:43:43 by jukim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main/main.c main/setting.c utils/utils.c monitoring/monitor.c		\
mutex/grab_fork.c philosopher/make_philosopher.c philosopher/philo_action.c	\
mutex/init_mutex.c mutex/is_one_fork.c philosopher/philo_routine.c			\
mutex/destroy_mutex.c clean/clean.c
OBJS = $(SRCS:.c=.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror
NAME = philo
INCLUDES = -I./includes

.PHONY : clean bonus all fclean re

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CCFLAGS) -c  -o $@ $< $(INCLUDES)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
