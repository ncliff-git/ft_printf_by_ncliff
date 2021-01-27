/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sp_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:53:28 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/26 13:24:52 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*sum_in_char(int a)
{
	char *s1;

	if (a == 0)
	{
		if (!(s1 = (char *)malloc(1 * sizeof(char))))
			return (NULL);
		s1[0] = 0;
		return (s1);
	}
	if (!(s1 = (char *)malloc(2 * sizeof(char))))
		return (NULL);
	s1[0] = a;
	s1[1] = 0;
	return (s1);
}

static void		ft_nulldell(t_prnt **l_args)
{
	if ((*l_args)->acacy >= 0 && (*l_args)->flag == '0')
		(*l_args)->acacy = -1;
	return ;
}

int				ft_printf_sp(t_prnt **l_args, int point)
{
	char	*num;
	int		i;

	if (!(num = sum_in_char('%')))
		return (-1);
	if (num[point] == 0)
		point++;
	ft_nulldell(l_args);
	while (num[point] != '\0')
		point++;
	if ((*l_args)->widht > point && (*l_args)->flag != '-')
		return (widht_d((*l_args)->widht, point, &num, l_args));
	else if ((*l_args)->widht > point && (*l_args)->flag == '-')
		return (widht_d_minus((*l_args)->widht, point, num));
	else
	{
		i = write(1, num, point);
		free(num);
		return (i);
	}
	return (0);
}
