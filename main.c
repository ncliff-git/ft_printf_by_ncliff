/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:27:30 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/08 20:44:51 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_list.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	char	*scp;
	va_list	args;
	int		lenstr;

	scp = (char *)format;
	lenstr = 0;
	va_start(args, format);
	while ((*scp) != '\0')
	{
		if((*scp) == '%')
		{
			lenstr += pars_arg(&scp, args);
			continue;
		}
		write(1, scp, 1);
		lenstr++;
		scp++;
	}
	va_end(args);

	printf("%s", format);
	return (lenstr);
}

int main()
{
	int a;
	a = ft_printf("as %d sa %0-12.12d %.d", 12);
	printf("\n\n\n%d", a);
	return (0);
}
