FILES = Utility.cpp main.cpp Harl.cpp
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:.cpp=.o)
NAME = harlFilter
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -Iincludes

.PHONY : clean all fclean re

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(OBJS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(INCLUDES)
	
clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all
