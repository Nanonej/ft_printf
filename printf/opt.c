/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:16:14 by lchim             #+#    #+#             */
/*   Updated: 2017/01/12 23:41:47 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_mod(t_form *form, char **format)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = *format;
	while (ft_strfind("lhjzL", *tmp) != -1)
	{
		i++;
		tmp++;
	}
	check_alloc((void *)(tmp = ft_strsub(*format, 0, i)));
	*format += i;
	if (ft_strfind("-+0 #123456789.", **format) == -1)
	{
		if (!(check_conv((form->conv = **format))))
		{
			free(tmp);
			return (0);
		}
		if (*tmp)
			check_conv_mod(form, tmp);
	}
	free(tmp);
	(*format)++;
	return (1);
}

static void		check_prec(t_form *form, char **format)
{
	int			nb;
	int			count;

	(*format)++;
	form->prec = 0;
	if (**format == '*')
	{
		form->prec = va_arg(form->ap, int);
		(*format)++;
	}
	else if (**format >= '0' && **format <= '9')
	{
		count = 1;
		nb = ft_atoi(*format);
		while ((nb /= 10) != 0)
			count++;
		form->prec = ft_atoi(*format);
		*format += count;
	}
}

static void		check_len(t_form *form, char **format)
{
	int			nb;
	int			count;

	if (**format == '*')
	{
		form->len = va_arg(form->ap, int);
		(*format)++;
	}
	else if (**format >= '0' && **format <= '9')
	{
		count = 1;
		nb = ft_atoi(*format);
		while ((nb /= 10) != 0)
			count++;
		form->len = ft_atoi(*format);
		*format += count;
	}
}

static void		check_opt(t_form *form, char **format)
{
	while (ft_strfind("-+0 #", **format) != -1)
	{
		if (**format == '-')
			form->minus = '1';
		else if (**format == '+')
			form->plus = '1';
		else if (**format == '0')
			form->zero = '1';
		else if (**format == ' ')
			form->space = '1';
		else if (**format == '#')
			form->hash = '1';
		(*format)++;
	}
}

int				fill_opt(t_form *form, char **format)
{
	while (ft_strfind("-+0 #123456789.lhjzL", **format) != -1)
	{
		if (ft_strfind("-+0 #", **format) != -1)
			check_opt(form, format);
		else if (ft_strfind("123456789", **format) != -1)
			check_len(form, format);
		else if (**format == '.')
			check_prec(form, format);
		else
			if (check_mod(form, format))
				return (1);
	}
	if (!form->conv && check_conv((form->conv = **format)))
	{
		(*format)++;
		return (1);
	}
	return (0);
}
