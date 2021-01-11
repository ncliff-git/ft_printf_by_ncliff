SRC		=	ft_printf_list_utils.c	\
			ft_printf_pars.c		\
			ft_printf_d_utils.c		\
			ft_printf_x_utils.c		\
			ft_printf_u_utils.c		\
			ft_printf_c_utils.c		\
			ft_printf_s_utils.c		\
			ft_printf_p_utils.c		\
			ft_printf_sp_utils.c	\
			ft_itoa.c				\
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
