/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:39:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/07 17:43:19 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*buff;
	char	*(*p[14]) (va_list ap);

	buff = ft_strnew(0);
	check_alloc((void *)buff);
	va_start(ap, format);
	fill_array(p);
	while (*format)
	{
		buff = buff_until(buff, (char **)&format);
		if (*format)
		{
			buff = buff_conv(buff, (char **)&format, p, ap);
			if (buff == NULL)
				return (-1);
		}
	}
	ft_putstr(buff);
	free(buff);
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

char	*buff_conv(char *buff, char **format, char *(**p)(va_list), va_list ap)
{
	t_opt	form_arg;
	char	*arg;
	char	*tmp;

	tmp = buff;
	if (start_opt(&form_arg, format) == 1)
		return (NULL);
	if (form_arg.conv != '%')
		arg = p[ft_strfind("sSpdDioOuUxXcC", form_arg.conv)](ap);
	else
		arg = ft_strdup("%");
	check_alloc((void *)arg);
	buff = ft_strjoin(buff, arg);
	check_alloc((void *)buff);
	free(tmp);
	free(arg);
	return (buff);
}

void	fill_array(char *(**p)(va_list))
{
	p[0] = ft_conv_s;
	p[1] = ft_conv_ws;
	// p[2] = ft_conv_p;
	p[3] = ft_conv_d;
	// p[4] = ft_conv_d;
	p[5] = ft_conv_d;
	// p[6] = ft_conv_o;
	// p[7] = ft_conv_o;
	// p[8] = ft_conv_u;
	// p[9] = ft_conv_u;
	// p[10] = ft_conv_x;
	// p[11] = ft_conv_x;
	p[12] = ft_conv_c;
	p[13] = ft_conv_wc;
}
