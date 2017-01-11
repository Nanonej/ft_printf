/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:16:14 by lchim             #+#    #+#             */
/*   Updated: 2017/01/11 13:36:08 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		check_mod(t_form *form, char **format)
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
	check_alloc((void *)(form->mod = ft_strsub(*format, 0, i)));
	*format += i;
}

static void		check_prec(t_form *form, char **format)
{
	int			nb;
	int			count;

	if (**format != '.')
		return ;
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
	check_opt(form, format);
	check_len(form, format);
	check_prec(form, format);
	check_mod(form, format);
	form->conv = **format;
	if (!check_conv(form->conv))
		return (0);
	if (form->mod)
	{
		if ((form->mod)[0] == 'L' && ft_strfind("eEfF", form->conv) == -1)
		{
			free(form->mod);
			form->mod = NULL;
		}
	}
	if (form->mod)
		check_conv_mod(form);
	(*format)++;
	return (1);
}
