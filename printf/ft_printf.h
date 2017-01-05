/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:24 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/05 17:45:50 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> ////////////////////////////////////////////////////////////

typedef struct	s_opt
{
	char		minus;
	char		plus;
	char		zero;
	char		space;
	char		hash;
	int			len;
	int			prec;
	char		*mod;
	char		conv;
}				t_opt;

int				ft_printf(const char *format, ...);
char			*buff_until(char *buff, char **format);
char			*buff_conv(char *buff, char **format);
void			fill_array(int (**p)(char *, va_list, t_opt));

int				start_opt(t_opt *form_arg, char **format);
void			clear_opt(t_opt *form_arg);
void			check_opt(t_opt *form_arg, char **format);
void			check_len_prec(t_opt *form_arg, char **format, int ftbool);
void			check_mod(t_opt *form_arg, char **format);

int				ft_conv_s(char *buff, va_list ap, t_opt form_arg);

void			check_alloc(void *ptr);
int				check_conv(char c);

#endif
