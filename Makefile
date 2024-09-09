SRC = src/pipex.c src/tools.c src/get_path.c

LIBFTPATH = ./utils/libft/
LIBFT = $(LIBFTPATH)libft.a

PRINTFPATH = ./utils/printf/
PRINTF = $(PRINTFPATH)printf.a

GNLPATH = ./utils/gnl/
GNL = $(GNLPATH)gnl.a

NAME = pipex

CFLAGS = -Werror -Wall -Wextra #-fsanitize=address

$(NAME) : $(SRC)
	make -C $(LIBFTPATH) all
	make -C $(PRINTFPATH) all
	make -C $(GNLPATH) all
	cc $(CFLAGS) $(SRC) $(LIBFT) $(PRINTF) $(GNL) -o $(NAME)

all : $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFTPATH) clean
	make -C $(PRINTFPATH) clean
	make -C $(GNLPATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTPATH) fclean
	make -C $(PRINTFPATH) fclean
	make -C $(GNLPATH) fclean

re: fclean all

.PHONY:
	all clean fclean re