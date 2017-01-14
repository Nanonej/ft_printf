/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:58:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/13 18:34:30 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_wchar_to_str(wchar_t c, char **s)
{
	if (c <= 0x10FFFF)
	{
		*s = ft_strnew(4);
    	check_alloc((void*)s);
	    if (c <= 0x7F)
	        (*s)[0] = c;
	    else if (c < 0x7FF)
	    {
	        (*s)[0] = (c >> 6) + 0xC0;
	        (*s)[1] = (c & 0x3F) + 0x80;
	    }
	    else if (c < 0xFFFF)
	    {
	        (*s)[0] = (c >> 12) + 0xE0;
	        (*s)[1] = ((c >> 6) & 0x3F) + 0x80;
	        (*s)[2] = (c & 0x3F) + 0x80;
	    }
	    else
	    {
	        (*s)[0] = (c >> 18) + 0xF0;
	        (*s)[1] = (c >> 12) & 0x3F;
	        (*s)[2] = ((c >> 6) & 0x3F) + 0x80;
	        (*s)[3] = (c & 0x3F) + 0x80;
	    }
	}
}

int				ft_conv_c(t_form *f)
{
	wchar_t			c;

	if (f->conv == 'c' && f->mod != L)
		c = (unsigned char)va_arg(f->ap, int);
	else
		c = (wchar_t)va_arg(f->ap, wint_t);
	ft_wchar_to_str(c, &(f->arg));
	if (c == 0)
		return (1);
	return (ft_strlen(f->arg));
}

int				ft_conv_s(t_form *f)
{
	wchar_t		*s;

	if (f->conv == 's' && f->mod != L)
		s = va_arg(f->ap, char *);
	else
		s = va_arg(f->ap, wchar_t *);
	if (!s)
	{
		check_alloc((f->arg = ft_strdup("(null)")));
		return (ft_strlen(f->arg));
	}
	check_alloc((f->arg = ft_strdup(s)));
	return (ft_strlen(f->arg));
}

int				ft_conv_pct(t_form *f)
{
	f->arg = ft_strdup("%");
	check_alloc(f->arg);
	return (1);
}
