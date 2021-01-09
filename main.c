/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:27:30 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/09 16:29:34 by ncliff           ###   ########.fr       */
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
	return (lenstr);
}

int main()
{
	int a;
	a = ft_printf("%10d\n%10.5d\n\n", 0, 123456);
	ft_printf("\n\n%d\n", a);
	ft_printf("\n%5.5ds", -120);
	ft_printf("\n%10ds", 12345);
	ft_printf("\n%10ds", 13456);
	ft_printf("\n%10ds\n\n\n", 1234567);


	printf("\n\n%d\n", a);
	printf("\n%5.5ds", -120);
	printf("\n%10ds", 12345);
	printf("\n%10ds", 13456);
	printf("\n%10ds", 1234567);
	return (0);
}
