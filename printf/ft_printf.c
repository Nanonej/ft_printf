/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:39:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/09 10:57:05 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (buff_conv(form, (char **)&format))
				return (-1);
		}
	}
	ft_putstr(form->buff);
	ret = ft_strlen(form->buff);
	init_clear(&form);
	return (ret);
}

char			*buff_until(char *buff, char **format)
{
	char		*tmp;
	char		*sub;
	int			pos;

	pos = ft_strfind(*format, '%');
	if (pos == 0)
		return (buff);
	if (pos == -1)
		pos = ft_strlen(*format);
	sub = ft_strsub(*format, 0, pos);
	check_alloc((void *)sub);
	tmp = ft_strjoin(buff, sub);
	check_alloc((void *)tmp);
	*format += pos;
	free(buff);
	free(sub);
	return (tmp);
}

int				buff_conv(t_form *form, char **format)
{
	if (!(fill_opt(form, format)))
	{
		init_clear(&form);
		return (1);
	}
	form->p[ft_strfind("sSpdDioOuUxXcC", form->conv)](form);
	return (0);
}
