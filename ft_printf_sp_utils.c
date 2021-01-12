/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sp_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:53:28 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/12 15:34:24 by ncliff           ###   ########.fr       */
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

static int		widht_sp(int widht, int point, char **num, t_list **l_args)
{
	int		widht2;
	char	*numcp;

	numcp = *num;
	widht2 = widht;
	while (widht > point)
	{
		if ((*l_args)->flag == '0')
			write(1, "0", 1);
		else
			write(1, " ", 1);
		widht--;
	}
	write(1, (*num), point);
	free(numcp);
	return (widht2);
}

int				ft_printf_sp(t_list **l_args, int point)
{
	char	*num;
	int		i;

	num = sum_in_char('%');
	if (num[point] == 0)
		point++;
	if ((*l_args)->flag == '-' || (*l_args)->widht == 0)
		return (write(1, "%", 1));
	while (num[point] != '\0')
		point++;
	if ((*l_args)->acacy > (-1))
		return (widht_sp((*l_args)->widht, point, &num, l_args));
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
