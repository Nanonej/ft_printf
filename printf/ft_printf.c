/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:39:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/03 16:55:24 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*buff;
	int		i;

	i = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		buff = buff_until(format, &i);
		if (buff[i])
			buff = buff_conv(format, ap, &i);
	}
	va_end(ap);
	return (0);
}

char	*buff_until(char *format, int *i)
{
	char *tmp;

	tmp = ft_strsub(format, *i, ft_strfind(format, '%'))
	*i = ft_strlen(tmp);
	return (tmp);
}

char	*buff_conv(char *format, va_list ap, int *i)
{

}
