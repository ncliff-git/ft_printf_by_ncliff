SRC		=	ft_printf_list_utils.c	\
			ft_printf_pars.c		\
			main.c

NAME	=	libftprintf.a

OBJ		=	${SRC:.c=.o}

HEADER	=	ft_printf_list.h

FLAG	=	-Wall -Werror -Wextra

OPTION	=	-c -I $(HEADER)

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
