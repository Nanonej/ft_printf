/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:24 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/09 15:59:08 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> ////////////////////////////////////////////////////////////

typedef struct	s_form
{
	char		*buff;
	va_list		ap;
	char		*(*p[14])(struct s_form *form);
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

typedef char	*(*t_array)(t_form *form);

int				ft_printf(const char *format, ...);
char			*buff_until(char *buff, char **format);
int				buff_conv(t_form *form, char **format);

t_form			*init_form(t_form *form);
void			init_array(t_array *p);
void			init_opt(t_form *form);
void			init_clear(t_form **form);

int				fill_opt(t_form *form, char **format);
void			check_opt(t_form *form, char **format);
void			check_len_prec(t_form *form, char **format, int ftbool);
void			check_mod(t_form *form, char **format);

char			*ft_conv_c(t_form *form);
char			*ft_conv_s(t_form *form);
char			*ft_conv_ws(t_form *form);
void 			ft_wchar_to_str(wchar_t c, char **s);

void			check_alloc(void *ptr);
int				check_conv(char c);
#endif
