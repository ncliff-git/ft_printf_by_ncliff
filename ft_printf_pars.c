/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:28:37 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/08 21:20:56 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	удалить stdio.h 
*/
#include "ft_printf_list.h"
#include <stdio.h>

static void		pars_flag(char ***s, t_list **l_args)
{
	while ((***s) == '0' || (***s) == '-')
	{
		if ((*l_args)->flag == '-')
		{
			(*l_args)->arglen++;
			(**s)++;
			continue;
		}
		if ((***s) == '0')
			(*l_args)->flag = '0';
		if ((***s) == '-')
			(*l_args)->flag = '-';
		(*l_args)->arglen++;
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
		(*l_args)->arglen++;
		(**s)++;
		return ;
	}
	while ((***s) >= '0' && (***s) <= '9')
	{
		(*l_args)->widht = (*l_args)->widht * 10 + ((***s) - '0');
		(*l_args)->arglen++;
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
			(*l_args)->arglen++;
			(**s)++;
			return ;
		}
		while ((***s) >= '0' && (***s) <= '9')
		{
			(*l_args)->acacy = (*l_args)->acacy * 10 + ((***s) - '0');
			(*l_args)->arglen++;
			(**s)++;
		}
		(*l_args)->arglen++;
		return ;
	}
	return ;
}

int				pars_arg(char **s, va_list args)
{
	t_list	*l_args;

	(*s)++;
	if (!((l_args) = ft_listnew()))
		return (1);
	l_args->arglen++;
	pars_flag(&s, &l_args);
	pars_widht(&s, &l_args, args);
	pars_acy(&s, &l_args, args);
	if ((**s) == 'd')
		l_args->arg = (**s);
	(*s)++;
	l_args->arglen++;

	//	Тестовая часть
	printf("\nflag: %c\n", (*l_args).flag);
	printf("widht: %d\n", (*l_args).widht);
	printf("acacy: %d\n", (*l_args).acacy);
	printf("arg: %c\n", (*l_args).arg);
	printf("arglen: %d\n", (*l_args).arglen);
	// 
	free(l_args);
	return (0);
}
