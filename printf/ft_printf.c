/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:39:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/13 21:30:23 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		buff_conv(t_form *f, char **format)
{
	if (fill_opt(f, format))
	{
		f->szarg = f->p[ft_strfind("sSpdDioOuUxXcCbBfF%", f->conv)](f);
		if (f->szarg == -1)
		{
			init_clear(&f);
			return (0);
		}
		format_prec(f);
		free_swap(&(f->buff), ft_memcat(f->buff, f->arg, f->szbuff, f->szarg));
		check_alloc((void *)f->buff);
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

	pos = ft_strfind(*format, '%');
	if (pos == 0)
		return ;
	if (pos == -1)
		pos = ft_strlen(*format);
	sub = ft_strsub(*format, 0, pos);
	check_alloc((void *)sub);
	free_swap(&(f->buff), ft_memcat(f->buff, sub, f->szbuff, pos));
	check_alloc((void *)f->buff);
	f->szbuff += pos;
	*format += pos;
	free(sub);
}

int				ft_printf(const char *format, ...)
{
	int			ret;
	t_form		*f;

	if (!format)
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
