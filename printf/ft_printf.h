/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:24 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/04 18:29:14 by lchim            ###   ########.fr       */
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

// typedef 		int	(*t_ptf)(va_list ap);

int				ft_printf(const char *format, ...);
char			*buff_conv(char *buff, char *format, va_list ap, int *i);
char			*buff_until(char *buff, char *format, int *i);
void			check_alloc(void *ptr);
void			start_opt(t_opt *form_arg, char *buff, int *i);
void			check_opt(t_opt *form_arg, char *buff, int *i);
void			check_len_prec(t_opt *form_arg, char *buff, int *i, int ftbool);
void			check_mod(t_opt *form_arg, char *buff, int *i);

#endif
