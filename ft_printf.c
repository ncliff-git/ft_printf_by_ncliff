/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:27:30 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/11 21:26:11 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char	*scp;
	va_list	args;
	int		lenstr;

	if (format == NULL)
		return (-1);
	scp = (char *)format;
	lenstr = 0;
	va_start(args, format);
	while ((*scp) != '\0')
	{
		if ((*scp) == '%')
		{
			lenstr += pars_arg(&scp, args);
			continue;
		}
		write(1, scp, 1);
		lenstr++;
		scp++;
	}
	va_end(args);
	return (lenstr);
}
