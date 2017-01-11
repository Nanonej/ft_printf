/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:39:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/11 23:17:08 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*buff_until(char *buff, char **format)
{
	char		*sub;
	int			pos;

	pos = ft_strfind(*format, '%');
	if (pos == 0)
		return (buff);
	if (pos == -1)
		pos = ft_strlen(*format);
	sub = ft_strsub(*format, 0, pos);
	check_alloc((void *)sub);
	buff = free_swap(buff, ft_strjoin(buff, sub));
	check_alloc((void *)buff);
	*format += pos;
	free(sub);
	return (buff);
}

static int		buff_conv(t_form *form, char **format)
{
	if (fill_opt(form, format))
	{
		if (!(form->p[ft_strfind("sSpdDioOuUxXcCbBeEfF%", form->conv)](form)))
		{
			init_clear(&form);
			return (0);
		}
		form->buff = free_swap(form->buff, ft_strjoin(form->buff, form->arg));
		check_alloc((void *)form->buff);
	}
	if (form->arg)
		free(form->arg);
	return (1);
}

int				ft_printf(const char *format, ...)
{
	int			ret;
	t_form		*form;

	if (!format)
		return (-1);
	form = init_form(form);
	va_start(form->ap, format);
	while (*format)
	{
		form->buff = buff_until(form->buff, (char **)&format);
		if (*format)
		{
			format++;
			if (!buff_conv(form, (char **)&format))
				return (-1);
			init_opt(form);
		}
	}
	ft_putstr(form->buff);
	ret = ft_strlen(form->buff);
	init_clear(&form);
	return (ret);
}
