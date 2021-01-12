/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 20:55:33 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/12 21:42:39 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*sum_in_char(int a)
{
	char *s1;

	if (a == 0)
	{
		if (!(s1 = malloc(1 * sizeof(char))))
			return (NULL);
		s1[0] = 0;
		return (s1);
	}
	if (!(s1 = malloc(2 * sizeof(char))))
		return (NULL);
	s1[0] = a;
	s1[1] = 0;
	return (s1);
}

int				ft_printf_c(t_list **l_args, va_list args, int point)
{
	char	*num;
	int		i;

	if (!(num = sum_in_char(va_arg(args, int))))
		return (-1);
	(num[point] == 0) ? point += 1 : 0;
	while (num[point] != '\0')
		point++;
	if ((*l_args)->acacy > (-1))
	{
		if ((*num) == '0' && (*l_args)->acacy == 0)
			point = 0;
		point = acacy_d((*l_args)->acacy, point, &num);
	}
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
