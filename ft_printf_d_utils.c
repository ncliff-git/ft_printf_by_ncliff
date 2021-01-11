/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:27:12 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/11 21:22:20 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	widht_d(int widht, int point, char **num, t_list **l_args)
{
	int		widht2;
	char	*numcp;

	numcp = *num;
	widht2 = widht;
	while (widht > point)
	{
		if ((*num)[0] == '-' && (*l_args)->flag == '0' && (*l_args)->acacy < 0)
		{
			write(1, "-", 1);
			(*num)++;
			point--;
			widht--;
		}
		if ((*l_args)->flag == '0' && (*l_args)->acacy < 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		widht--;
	}
	write(1, (*num), point);
	free(numcp);
	return (widht2);
}

int	widht_d_minus(int widht, int point, char *num)
{
	int widht2;

	widht2 = widht;
	write(1, num, point);
	widht -= point;
	while (widht-- > 0)
		write(1, " ", 1);
	free(num);
	return (widht2);
}

int	acacy_d(int acacy, int point, char **num)
{
	int		sumzero;
	char	*s1;
	int		i;

	if (acacy < point)
		return (point);
	else
	{
		i = 0;
		sumzero = acacy - point;
		s1 = (char *)malloc(sumzero * sizeof(char) + 1);
		while (sumzero-- > 0)
			s1[i++] = '0';
		s1[i] = '\0';
		if ((**num) == '-')
		{
			s1 = ft_strjoin("-", s1, 1);
			(**num) = '0';
			acacy += 1;
		}
		*num = ft_strjoin(s1, *num, 0);
	}
	return (acacy);
}

int	ft_printf_d(t_list **l_args, va_list args, int point)
{
	char	*num;
	int		i;

	num = ft_itoa(va_arg(args, int));
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
