/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:24 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/10 13:23:36 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdio.h> ////////////////////////////////////////////////////////////

typedef struct	s_form
{
	char		*buff;
	char		*arg;
	va_list		ap;
	int			(*p[17])(struct s_form *form);
	char		minus;
	char		plus;
	char		zero;
	char		space;
	char		hash;
	int			len;
	int			prec;
	char		*mod;
	char		conv;
}				t_form;

typedef int		(*t_array)(t_form *form);

int				ft_printf(const char *format, ...);

t_form			*init_form(t_form *form);
void			init_opt(t_form *form);
void			init_clear(t_form **form);

int				fill_opt(t_form *form, char **format);

int				ft_conv_c(t_form *form);

int				ft_conv_d(t_form *form);
int				ft_conv_u(t_form *form);
intmax_t		ft_conv_intmax(t_form *form);
uintmax_t		ft_conv_uintmax(t_form *form);

int				ft_conv_o(t_form *form);
int				ft_conv_x(t_form *form);
int				ft_conv_p(t_form *form);
int				ft_conv_b(t_form *form);

void			check_alloc(void *ptr);
int				check_conv(char c);
int				check_conv_mod(t_form *form);
char			*free_swap(char *src, char *dst);

#endif
