/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:26:36 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/25 21:30:46 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prnt			*ft_listnew_pr(void)
{
	t_prnt	*new;

	if (!(new = (t_prnt *)malloc(sizeof(t_prnt))))
		return (NULL);
	new->flag = 0;
	new->arg = 0;
	new->acacy = -1;
	new->widht = 0;
	return (new);
}

int				ft_printf_choice(t_prnt **l_args, va_list args)
{
	if ((*l_args)->arg == 'd' || (*l_args)->arg == 'i')
		return (ft_printf_d(l_args, args, 0));
	else if ((*l_args)->arg == 'X' || (*l_args)->arg == 'x')
		return (ft_printf_h(l_args, args, 0));
	else if ((*l_args)->arg == 'u')
		return (ft_printf_u(l_args, args, 0));
	else if ((*l_args)->arg == 'c')
		return (ft_printf_c(l_args, args, 0));
	else if ((*l_args)->arg == 's')
		return (ft_printf_s(l_args, args, 0));
	else if ((*l_args)->arg == 'p')
		return (ft_printf_p(l_args, args, 0));
	else if ((*l_args)->arg == '%')
		return (ft_printf_sp(l_args, 0));
	else
	{
		va_arg(args, int);
		write(1, "##ERROR##", 9);
	}
	return (0);
}

int				ft_strlen_pr(const char *s)
{
	int n;

	n = 0;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		s++;
		n++;
	}
	return (n);
}

char			*ft_strjoin_pr(char *s1, char *s2, int var)
{
	char	*strjn;
	int		i;
	int		n;

	if ((s1 == NULL && var < 3) || s2 == NULL
	|| !(strjn = (char *)malloc((ft_strlen_pr(s1) + ft_strlen_pr(s2)) + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		strjn[i] = s1[i];
		i++;
	}
	if (var == 0)
		free(s1);
	n = 0;
	while (s2[n] != '\0')
	{
		strjn[i] = s2[n];
		i++;
		n++;
	}
	free(s2);
	strjn[i] = '\0';
	return (strjn);
}
