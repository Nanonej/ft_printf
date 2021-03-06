/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:39:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/04/02 18:43:07 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		buff_conv(t_form *f, char **format)
{
	if (fill_opt(f, format))
	{
		f->szarg = f->p[ft_strfind("sSpdDioOuUxXcCbB%", f->conv)](f);
		if (f->szarg == -1)
		{
			init_clear(&f);
			return (0);
		}
		format_prec(f);
		ft_memcpy(f->buff + f->szbuff, f->arg, f->szarg);
		f->szbuff += f->szarg;
	}
	if (f->arg)
		free(f->arg);
	return (1);
}

static void		buff_until(t_form *f, char **format)
{
	char		*sub;
	int			pos;

	if (**format == '%')
		return ;
	pos = ft_strfind(*format, '%');
	if (pos == -1)
		pos = ft_strlen(*format);
	sub = ft_strsub(*format, 0, pos);
	check_alloc(sub);
	ft_memcpy(f->buff + f->szbuff, sub, pos);
	f->szbuff += pos;
	*format += pos;
	free(sub);
}

static int		only_percent(char *format)
{
	size_t	i;

	i = -1;
	while (ft_iswhitespace(format[++i]))
		;
	if (format[i] != '%')
		return (0);
	while (ft_iswhitespace(format[++i]))
		;
	return (format[i] == '\0' ? 1 : 0);
}

int				ft_printf(const char *format, ...)
{
	int			ret;
	t_form		*f;

	if (!format || only_percent((char *)format))
		return (-1);
	f = init_form(f);
	va_start(f->ap, format);
	while (*format)
	{
		buff_until(f, (char **)&format);
		if (*format)
		{
			format++;
			if (!buff_conv(f, (char **)&format))
				return (-1);
			init_opt(f);
		}
	}
	write(1, f->buff, f->szbuff);
	ret = f->szbuff;
	init_clear(&f);
	return (ret);
}
