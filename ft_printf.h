/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:28:17 by ncliff            #+#    #+#             */
/*   Updated: 2021/01/25 21:29:54 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_prnt
{
	int				flag;
	int				widht;
	int				acacy;
	char			arg;
}					t_prnt;

int					ft_printf(const char *format, ...);
t_prnt				*ft_prntnew_pr(void);
int					pars_arg(char **s, va_list args);
int					ft_printf_choice(t_prnt **l_args, va_list args);
int					ft_printf_d(t_prnt **l_args, va_list args, int point);
int					widht_d(int widht, int point, char **num, t_prnt **l_args);
int					widht_d_minus(int widht, int point, char *num);
int					acacy_d(int acacy, int point, char **num);
char				*ft_itoa_pr(int n);
char				*ft_strjoin_pr(char *s1, char *s2, int var);
void				pars_test(t_prnt **l_args);
int					ft_printf_h(t_prnt **l_args, va_list args, int point);
char				ft_printf_hex(unsigned int hex, t_prnt **t_arg);
int					ft_printf_u(t_prnt **l_args, va_list args, int point);
int					ft_printf_c(t_prnt **l_args, va_list args, int point);
int					ft_printf_s(t_prnt **l_args, va_list args, int point);
int					ft_printf_p(t_prnt **l_args, va_list args, int point);
int					ft_printf_sp(t_prnt **l_args, int point);
int					ft_strlen_pr(const char *s);

#endif
