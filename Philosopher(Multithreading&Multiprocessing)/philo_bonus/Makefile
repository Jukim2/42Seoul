# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 18:10:56 by jukim2            #+#    #+#              #
#    Updated: 2023/08/22 11:22:34 by jukim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main/main_bonus.c main/setting_bonus.c utils/utils_bonus.c 				\
monitoring/monitor_bonus.c philosopher/make_philosopher_bonus.c 				\
philosopher/philo_sleep_bonus.c philosopher/philo_eat_bonus.c					\
philosopher/philo_routine_bonus.c philosopher/philo_think_bonus.c 				\
semaphore/initialize_semaphore_bonus.c semaphore/clear_semaphore_bonus.c		\
utils/utils2_bonus.c	
OBJS = $(SRCS:.c=.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus
INCLUDES = -I./includes

.PHONY : clean bonus all fclean re

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CCFLAGS) $(OBJS)

%.o : %.c
	$(CC) $(CCFLAGS) -c  -o $@ $< $(INCLUDES)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
