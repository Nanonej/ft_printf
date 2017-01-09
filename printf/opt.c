/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:16:14 by lchim             #+#    #+#             */
/*   Updated: 2017/01/09 16:10:40 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				fill_opt(t_form *form, char **format)
{
	(*format)++;
	init_opt(form);
	check_opt(form, format);
	check_len_prec(form, format, 0);
	if (**format == '.')
	{
		(*format)++;
		check_len_prec(form, format, 1);
	}
	check_mod(form, format);
	if (check_conv((form->conv = **format)) != 1)
	{
		(*format)++;
		return (1);
	}
	return (0);
}

void			check_opt(t_form *form, char **format)
{
	while (**format == '-' || **format == '+' || **format == '0' || \
	**format == ' ' || **format == '#')
	{
		if (**format == '-')
			form->minus = 1;
		else if (**format == '+')
			form->plus = 1;
		else if (**format == '0')
			form->zero = 1;
		else if (**format == ' ')
			form->space = 1;
		else if (**format == '#')
			form->hash = 1;
		(*format)++;
	}
}

void			check_len_prec(t_form *form, char **format, int ftbool)
{
	int		nb;
	int		count;

	if (**format >= '0' && **format <= '9')
	{
		count = 1;
		nb = ft_atoi(*format);
		while ((nb /= 10) != 0)
			count++;
		if (!ftbool)
			form->len = ft_atoi(*format);
		else
			form->prec = ft_atoi(*format);
		*format += count;
	}
	if (**format == '*')
	{
		if (!ftbool)
			form->len = va_arg(form->ap, int);
		if (ftbool)
			form->prec = va_arg(form->ap, int);
	}
}

void			check_mod(t_form *form, char **format)
{
	int		i;
	char	*tmp;

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
	if (i == 2 && (!ft_strequ(form->mod, "ll") && !ft_strequ(form->mod, "hh")))
	{
		free(form->mod);
		form->mod = NULL;
	}
	*format += i;
}
