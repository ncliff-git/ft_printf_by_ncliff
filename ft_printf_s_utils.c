/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 21:35:11 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/25 21:28:49 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char			*print_null(void)
{
	char *str;

	if (!(str = (char *)malloc(7 * sizeof(char))))
		return (NULL);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}

static char			*ft_strdup(char *s1, int var)
{
	char	*s1dup;
	int		i;

	if (s1 == NULL)
		return (NULL);
	s1dup = (char *)malloc((ft_strlen_pr(s1) + 1) * sizeof(char));
	i = 0;
	if (s1dup == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s1dup[i] = s1[i];
		i++;
	}
	if (var == 1)
		free(s1);
	s1dup[i] = '\0';
	return (s1dup);
}

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	sizedst;
	int		pntd;

	pntd = 0;
	if (!dst || !src)
		return (sizeof(0));
	if (dstsize <= 0)
		return (ft_strlen_pr(src));
	sizedst = ft_strlen_pr(src);
	while (src[pntd] != '\0' && dstsize - 1 > 0)
	{
		dst[pntd] = src[pntd];
		pntd++;
		dstsize--;
	}
	dst[pntd] = '\0';
	return (ft_strlen_pr(src));
}

static int			acacy_s(int acacy, int point, char **num)
{
	if (acacy > point)
		return (point);
	else
	{
		(*num)[acacy] = '\0';
		*num = ft_strdup(*num, 1);
	}
	return (acacy);
}

int					ft_printf_s(t_list **l_args, va_list args, int point)
{
	char	*num;
	int		i;

	num = ft_strdup(va_arg(args, char *), 0);
	if (num == NULL)
		num = print_null();
	while (num[point] != '\0')
		point++;
	if ((*l_args)->acacy > (-1))
	{
		if ((*num) == '0' && (*l_args)->acacy == 0)
			point = 0;
		point = acacy_s((*l_args)->acacy, point, &num);
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
