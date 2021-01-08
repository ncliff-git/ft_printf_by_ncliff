/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:26:36 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/08 20:44:21 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_list.h"

t_list		*ft_listnew(void)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->flag = 0;
	new->arg = 0;
	new->acacy = -1;
	new->widht = 0;
	new->arglen = 0;
	return (new);
}
