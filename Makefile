NAME	=	libftprintf.a

CFLAGS	=	-Wall -Werror -Wextra

HEADER	=	ft_printf.h

CC		=	gcc

OPTION	=	-c -I $(HEADER)

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
			ft_printf.c

OBJ		=	${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
