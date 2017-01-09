/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:58:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/09 13:46:21 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void   			 ft_wchar_to_str(wchar_t c, char **s)
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
    else if (c <= 0x10FFFF)
    {
        (*s)[0] = (c >> 18) + 0xF0;
        (*s)[1] = (c >> 12) & 0x3F;
        (*s)[2] = ((c >> 6) & 0x3F) + 0x80;
        (*s)[3] = (c & 0x3F) + 0x80;
    }
}

char			*ft_conv_c(t_form *form)
{
	char		c;
	wchar_t		lc;
	char		*arg;

	arg = NULL;
	if (form->mod == 'c' && !form->mod);
	{
		c = (char)va_arg(form->ap, int);
		arg = ft_strdup(&c);
		check_alloc((void *)&arg);
	}
	else if ((form->conv == 'c' && (form->mod)[0] == 'l') || form->conv == 'C')
	{
		lc = (wchar_t)va_arg(form->ap, wint_t);
		ft_wchar_to_str(lc, &arg);
	}
	return (arg);
}

// char    *ft_conv_s(va_list ap)
// {
//     char    *tmp;
//
//     tmp = ft_strdup(va_arg(ap, char *));
//     check_alloc((void *)tmp);
//     return (tmp);
// }
//
// char    *ft_conv_ws(va_list ap)
// {
//     wchar_t    *wstr;
//     char    *tmp;
//     char    *forfree;
//     char    *s;
//
//     tmp = ft_strnew(0);
//     check_alloc((void *)tmp);
//     wstr = va_arg(ap, wchar_t *);
//     while (*wstr)
//     {
//         ft_wchar_to_str(*wstr, &s);
//         forfree = tmp;
//         tmp = ft_strjoin(tmp, s);
//         check_alloc((void *)tmp);
//         wstr++;
//         free(forfree);
//         free(s);
//     }
//     return (tmp);
// }
