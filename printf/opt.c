/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:16:14 by lchim             #+#    #+#             */
/*   Updated: 2017/01/10 12:03:10 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_mod(t_form *form, char **format)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = *format;
	while (*tmp == 'j' || *tmp == 'z' || *tmp == 'h' || *tmp == 'l')
	{
		i++;
		tmp++;
	}
	if (i == 1 || i == 2)
	{
		tmp = ft_strsub(*format, 0, i);
		check_alloc((void *)tmp);
		form->mod = tmp;
	}
	*format += i;
	if (i == 2 && (!ft_strequ(form->mod, "ll") && !ft_strequ(form->mod, "hh")))
	{
		free(form->mod);
		form->mod = NULL;
		i++;
	}
	return ((i <= 2) ? 1 : 0);
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
	if (!check_mod(form, format))
		return (0);
	form->conv = **format;
	if (!check_conv(form->conv) || !check_conv_mod(form))
		return (0);
	(*format)++;
	return (1);
}
