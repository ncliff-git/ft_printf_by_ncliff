/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:28:37 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/11 21:22:35 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pars_flag(char ***s, t_list **l_args)
{
	while ((***s) == '0' || (***s) == '-')
	{
		if ((*l_args)->flag == '-')
		{
			(**s)++;
			continue;
		}
		if ((***s) == '0')
			(*l_args)->flag = '0';
		if ((***s) == '-')
			(*l_args)->flag = '-';
		(**s)++;
	}
	return ;
}

static void		pars_widht(char ***s, t_list **l_args, va_list args)
{
	if ((***s) == '*')
	{
		(*l_args)->widht = va_arg(args, int);
		if ((*l_args)->widht < 0)
		{
			(*l_args)->widht = (*l_args)->widht * (-1);
			(*l_args)->flag = '-';
		}
		(**s)++;
		return ;
	}
	while ((***s) >= '0' && (***s) <= '9')
	{
		(*l_args)->widht = (*l_args)->widht * 10 + ((***s) - '0');
		(**s)++;
	}
	return ;
}

static void		pars_acy(char ***s, t_list **l_args, va_list args)
{
	if ((***s) == '.')
	{
		(*l_args)->acacy = 0;
		(**s)++;
		if ((***s) == '*')
		{
			(*l_args)->acacy = va_arg(args, int);
			if ((*l_args)->acacy < 0)
				(*l_args)->acacy = -1;
			(**s)++;
			return ;
		}
		while ((***s) >= '0' && (***s) <= '9')
		{
			(*l_args)->acacy = (*l_args)->acacy * 10 + ((***s) - '0');
			(**s)++;
		}
		return ;
	}
	return ;
}

int				pars_arg(char **s, va_list args)
{
	t_list	*l_args;
	int		lenarg;

	(*s)++;
	if ((**s) == '%')
	{
		(*s)++;
		return (write(1, "%", 1));
	}
	if (!((l_args) = ft_listnew()))
		return (0);
	pars_flag(&s, &l_args);
	pars_widht(&s, &l_args, args);
	pars_acy(&s, &l_args, args);
	l_args->arg = (**s);
	(*s)++;
	lenarg = ft_printf_choice(&l_args, args);
	free(l_args);
	return (lenarg);
}
