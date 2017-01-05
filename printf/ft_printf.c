/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:39:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/05 15:34:24 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*buff;

	buff = ft_strnew(0);
	check_alloc((void *)buff);
	va_start(ap, format);
	while (*format)
	{
		buff = buff_until(buff, (char **)&format);
		if (*format)
		{
			buff = buff_conv(buff, (char **)&format);
			if (buff == NULL)
				return (-1);
		}
	}
	va_end(ap);
	return (0);
}

char	*buff_until(char *buff, char **format)
{
	int		pos;
	char	*tmp;

	pos = ft_strfind(*format, '%');
	if (pos == -1)
	{
		tmp = ft_strjoin(buff, *format);
		*format += ft_strlen(*format);
	}
	else
	{
		tmp = ft_strjoin(buff, ft_strsub(*format, 0, pos));
		*format += pos + 1;
	}
	check_alloc((void *)tmp);
	free(buff);
	return (tmp);
}

char	*buff_conv(char *buff, char **format)
{
	t_opt	form_arg;

	if (start_opt(&form_arg, format) == 1)
		return (NULL);
	return (buff);
}
