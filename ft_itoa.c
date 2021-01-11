/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:05:39 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/11 21:22:07 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_sum(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*min_int_itoa(int n)
{
	char	*num;
	int		i;

	i = 11;
	num = (char *)malloc(i * sizeof(char));
	if (num == NULL)
		return (NULL);
	num[12] = 0;
	n = 2147483647;
	while (i-- > 0)
	{
		num[i] = (n % 10) + '0';
		n /= 10;
	}
	num[10] = '8';
	num[0] = '-';
	return (num);
}

static char	*ils_int_itoa(int n)
{
	char	*num;
	int		i;

	i = num_sum(n);
	num = (char *)malloc(i * sizeof(char) + 1);
	if (num == NULL)
		return (NULL);
	num[i] = 0;
	while (i-- > 0)
	{
		num[i] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}

static char	*mins_int_itoa(int n)
{
	char	*num;
	int		i;
	int		min;

	i = num_sum(n);
	num = (char *)malloc(i * sizeof(char) + 1);
	if (num == NULL)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		min = 1;
	}
	num[i] = '\0';
	while (i-- > 0)
	{
		num[i] = (n % 10) + '0';
		if (min == 1)
			num[0] = '-';
		n /= 10;
	}
	return (num);
}

char		*ft_itoa(int n)
{
	char *num;

	if (n == -2147483648)
		num = min_int_itoa(n);
	else if (n >= 0)
		num = ils_int_itoa(n);
	else
		num = mins_int_itoa(n);
	return (num);
}
