/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:58:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/07 15:09:10 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wchar_to_str(wchar_t c, char **s)
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
	char	*s;

	if (form_arg.conv)
	{
		wstr = va_arg(ap, wchar_t *);
		while (*wstr != 0)
		{
			tmp = buff;
			buff = ft_strjoin(buff, ft_wchar_to_str(*wstr, &s));
			check_alloc((void *)buff);
			free(tmp);
			free(s);
		}
	}
	return (buff);
}

char	*ft_conv_c(char *buff, va_list ap, t_opt form_arg)
{
	char	*s;
	char	*tmp;

	s = ft_strnew(1);
	check_alloc((void*)s);
	s[0] = va_arg(ap, int);
	if (form_arg.conv)
	{
		tmp = buff;
		buff = ft_strjoin(buff, s);
		check_alloc((void *)buff);
		free(tmp);
	}
	free(s);
	return (buff);
}

char	*ft_conv_wc(char *buff, va_list ap, t_opt form_arg)
{
	char	*tmp;
	char	*s;

	if (form_arg.conv)
	{
		tmp = buff;
		buff = ft_strjoin(buff, ft_wchar_to_str(va_arg(ap, wchar_t), &s));
		check_alloc((void *)buff);
		free(tmp);
		free(s);
	}
	return (buff);
}
