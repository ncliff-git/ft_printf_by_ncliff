/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:28:17 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/11 12:55:51 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_LIST_H
# define FT_PRINTF_LIST_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_list
{
	int				flag;
	char			*data;
	int				widht;
	int				acacy;
	char			arg;
}					t_list;

t_list				*ft_listnew(void);
void				ft_listadd_back(t_list **lst, t_list *new);
int					pars_arg(char **s, va_list args);
int					ft_printf_choice(t_list **l_args, va_list args);
int					ft_printf_d(t_list **l_args, va_list args, int point);
int					widht_d(int widht, int point, char **num, t_list **l_args);
int					widht_d_minus(int widht, int point, char *num);
int					acacy_d(int acacy, int point, char **num);
char				*ft_itoa(int n);
char				*ft_strjoin(char *s1, char *s2, int var);
void				pars_test(t_list **l_args);
int					ft_printf_h(t_list **l_args, va_list args, int point);
char				ft_printf_hex(unsigned int hex, t_list **t_arg);
int					ft_printf_u(t_list **l_args, va_list args, int point);
int					ft_printf_c(t_list **l_args, va_list args, int point);
int					ft_printf_s(t_list **l_args, va_list args, int point);
int					ft_printf_p(t_list **l_args, va_list args, int point);
int					ft_printf_sp(t_list **l_args, int point);
int					ft_strlen(const char *s);


#endif
