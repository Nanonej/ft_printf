/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:24 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/07 17:30:21 by lchim            ###   ########.fr       */
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
char			*buff_conv(char *buff, char **format, char *(**p)(va_list), va_list ap);
void			fill_array(char *(**p)(va_list));

int				start_opt(t_opt *form_arg, char **format);
void			clear_opt(t_opt *form_arg);
void			check_opt(t_opt *form_arg, char **format);
void			check_len_prec(t_opt *form_arg, char **format, int ftbool);
void			check_mod(t_opt *form_arg, char **format);

char			*opt_plus_space(char *arg, char plus, char space);
char			*opt_len(char *arg, int len, char minor, char zero);
char			*opt_prec(char *arg, int prec);

void 			ft_wchar_to_str(wchar_t c, char **s);
char			*ft_conv_s(va_list ap);
char			*ft_conv_ws(va_list ap);
char			*ft_conv_c(va_list ap);
char			*ft_conv_wc(va_list ap);

void			check_alloc(void *ptr);
int				check_conv(char c);

#endif
