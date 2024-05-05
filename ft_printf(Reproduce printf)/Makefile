FILES = check_files.c ft_printf.c print_dux.c print_pcs.c tools.c tools2.c pack_n_ship.c
OBJS = $(FILES:.c=.o)
BONUSFILES = ./check_files_bonus.c ./ft_printf_bonus.c ./pack_n_ship_bonus.c 			\
./print_dux_bonus.c ./print_pcs_bonus.c ./tools2_bonus.c ./tools_bonus.c
BONUSOBJS = $(BONUSFILES:.c=.o)
NAME = libftprintf.a
LIBFT = ./libft/libft.a
CCFLAGS = -Wall -Wextra -Werror

ifdef BONUS
	OBJECTS = $(BONUSOBJS)
else
	OBJECTS = $(OBJS)
endif

.phony : all clean re fclean

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJECTS)
	cp $(LIBFT) $(NAME)
	ar -cr $@ $(OBJECTS)

$(LIBFT) : 
	make -C ./libft

%.o : %.c
	$(CC) $(CCFLAGS) -c -o $@ $< 

bonus :	
	make BONUS=1 $(NAME)

clean :
	make -C ./libft clean
	rm -f $(OBJS)
	rm -f $(BONUSOBJS)

fclean : clean
	make -C ./libft fclean
	rm -f $(NAME)

re : fclean
	make all
