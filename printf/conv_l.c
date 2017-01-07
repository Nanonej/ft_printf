/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:58:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/07 13:45:19 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wchar_to_str(wchar_t c)
{
	char s[5];

	ft_strclr(s);
	if (c <= 0x7F)
		s[0] = c;
	else if (c < 0x7FF)
	{
		s[0] = (c >> 6) + 0xC0;
		s[1] = (c & 0x3F) + 0x80;
	}
	else if (c < 0xFFFF)
	{
		s[0] = (c >> 12) + 0xE0;
		s[1] = ((c >> 6) & 0x3F) + 0x80;
		s[2] = (c & 0x3F) + 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		s[0] = (c >> 18) + 0xF0;
		s[1] = (c >> 12) & 0x3F;
		s[2] = ((c >> 6) & 0x3F) + 0x80;
		s[3] = (c & 0x3F) + 0x80;
	}
	return (s);
}

char	*ft_conv_s(char *buff, va_list ap, t_opt form_arg)
{
	char	*tmp;

	if (form_arg.conv)
	{
		tmp = buff;
		buff = ft_strjoin(buff, va_arg(ap, char *));
		check_alloc((void *)buff);
		free(tmp);
	}
	return (buff);
}

char	*ft_conv_ws(char *buff, va_list ap, t_opt form_arg)
{
	wchar_t	*wstr;
	char	*tmp;

	if (form_arg.conv)
	{
		wstr = va_arg(ap, wchar_t *)
		while (*wstr != 0)
		{
			tmp = buff;
			buff = ft_strjoin(buff, ft_wchar_to_str(*wstr));
			check_alloc((void *)buff);
			free(tmp);
		}
	}
	return (buff);
}
