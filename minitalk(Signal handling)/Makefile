# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 14:49:58 by jukim2            #+#    #+#              #
#    Updated: 2023/02/03 15:58:13 by jukim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = client.c server.c			
BONUSFILES = client_bonus.c server_bonus.c		
BONUSOBJS = $(BONUSFILES:.c=.o)
OBJS = $(FILES:.c=.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror
NAME = minitalk
LIBFT = libft.a
SERVER = server
CLIENT = client
CLIOBJ := client.o
SEROBJ := server.o
CLIOBJBONUS := client.o
SEROBJBONUS := server.o

ifdef WITH_BONUS
	OBJECTS = $(BONUSOBJS) 
	CLIOBJ := client_bonus.o
	SEROBJ := server_bonus.o
else
	OBJECTS = $(OBJS)
endif

.PHONY : clean bonus all fclean re

all : $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER) : $(LIBFT) $(SEROBJ)
	$(CC) -o $(SERVER) $(SEROBJ) $(LIBFT)

$(CLIENT) : $(LIBFT) $(CLIOBJ)
	$(CC) -o $(CLIENT) $(CLIOBJ) $(LIBFT)
	
$(LIBFT) : 
	make bonus -C ./libft
	mv ./libft/libft.a ./

bonus : 
	make WITH_BONUS=1 all
	
%.o : %.c
	$(CC) $(CCFLAGS) -c  -o $@ $<

clean :
	make -C ./libft fclean
	rm -f $(OBJS) $(BONUSOBJS) $(LIBFT)

fclean : clean
	rm -f $(CLIENT)
	rm -f $(SERVER)

re : 
	make fclean 
	make all
