FILES = Account.cpp tests.cpp
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:.cpp=.o)
NAME = Account
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++
INCLUDES = -Iincludes
.PHONY : clean all fclean re

all : $(NAME)

$(NAME): $(OBJS) 
	$(CPP) -o $(NAME) $(CPPFLAGS) $(OBJS)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $< $(INCLUDES)
	
clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)

re :
	make fclean
	make all
