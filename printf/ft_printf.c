/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:39:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/04 17:41:59 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*buff;
	int		i;

	i = 0;
	va_start(ap, format);
	buff = ft_strnew(0);
	check_alloc((void *)buff);
	while (format[i])
	{
		buff = buff_until(buff, (char *)format, &i);
		if (format[i])
			buff = buff_conv(buff, (char *)format, ap, &i);
	}
	va_end(ap);
	return (0);
}

char	*buff_until(char *buff, char *format, int *i)
{
	char *tmp;

	tmp = ft_strjoin(buff, ft_strsub(format, *i, ft_strfind(format, '%')));
	check_alloc((void *)tmp);
	*i = ft_strlen(ft_strsub(format, *i, ft_strfind(format, '%')));
	free(buff);
	return (tmp);
}

char	*buff_conv(char *buff, char *format, va_list ap, int *i)
{
	t_opt	form_arg;

	start_opt(&form_arg, format, i);
	return (NULL);
}

void	check_alloc(void *ptr)
{
	if (!ptr)
		exit(EXIT_FAILURE);
}
