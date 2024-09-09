SRC = ft_printf.c print_hex.c print_nbr.c print_str.c print_chr.c

LIBFTPATH = ./../libft/

LIBFT = $(LIBFTPATH)libft.a

CFLAGS = -Werror -Wall -Wextra

OBJ = $(SRC:.c=.o)

NAME = printf.a

$(NAME) : $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -rsc $(NAME) $(OBJ)

$(LIBFT) :
	make -C $(LIBFTPATH) all

all: $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFTPATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTPATH) fclean

re: fclean all

.PHONY:
	all clean fclean re
