/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:58:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/11 13:39:04 by lchim            ###   ########.fr       */
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

int				ft_conv_c(t_form *form)
{
	char		c;
	wchar_t		lc;

	if (form->conv == 'c' && !form->mod)
	{
		c = (char)va_arg(form->ap, int);
		form->arg = ft_strnew(1);
		check_alloc((void *)form->arg);
		(form->arg)[0] = c;
	}
	else if (form->conv == 'c' || form->conv == 'C')
	{
		lc = (wchar_t)va_arg(form->ap, wint_t);
		ft_wchar_to_str(lc, &(form->arg));
	}
	return ((form->arg) ? 1 : 0);
}

int		ft_conv_pct(t_form *form)
{
	form->arg = ft_strdup("%");
	check_alloc((void *)form->arg);
	return ((form->arg) ? 1 : 0);
}

// int				ft_conv_s(t_form *form)
// {
// 	wchar_t		*wstr;
// 	char		*s;
//
// 	if (form->conv == 's' && !form->mod)
// 	{
// 		form->arg = va_arg(form->ap, char *);
// 	}
// 	else if ((form->conv == 's'  && (form->mod)[0] == 'l') || form->conv == 'S')
// 	{
// 		form->arg = ft_strnew(0);
// 		wstr = va_arg(form->ap, wchar_t *);
// 		while (*wstr)
// 		{
// 			check_alloc((void *)form->arg);
// 			ft_wchar_to_str(*wstr, &s);
// 			form->arg = free_swap(form->arg, ft_strjoin(form->arg, s));
// 	        wstr++;
// 	        free(s);
// 		}
// 	}
// 	return ((form->arg) ? 1 : 0);
// }
