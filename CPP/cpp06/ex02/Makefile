SRCS = main.cpp A.cpp B.cpp C.cpp Base.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Identify
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY : clean all fclean re

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(OBJS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< 
	
clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)

re :
	make fclean
	make all
