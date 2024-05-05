# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 00:03:26 by kjs               #+#    #+#              #
#    Updated: 2023/08/28 08:32:49 by jukim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = megaphone
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

.PHONY : clean all fclean re

all : $(NAME)

$(NAME): $(OBJS) 
	$(CPP) -o $(NAME) $(CPPFLAGS) $(OBJS)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<
	
clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)

re :
	make fclean
	make all
