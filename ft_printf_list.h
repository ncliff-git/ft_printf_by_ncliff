/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:28:17 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/09 15:17:40 by ncliff           ###   ########.fr       */
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
int					ft_printf_d(t_list **l_args, va_list args);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);

#endif
