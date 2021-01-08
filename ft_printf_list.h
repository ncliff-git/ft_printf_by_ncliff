/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:28:17 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/07 16:20:17 by ncliff           ###   ########.fr       */
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
	int				arglen;
}					t_list;

t_list				*ft_listnew(void);
void				ft_listadd_back(t_list **lst, t_list *new);
int					pars_arg(char **s, va_list args);

#endif
