/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:09:13 by lchim             #+#    #+#             */
/*   Updated: 2017/01/05 14:15:11 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			start_opt(t_opt *form_arg, char **format)
{
	clear_opt(form_arg);
	check_opt(form_arg, format);
	check_len_prec(form_arg, format, 0);
	check_mod(form_arg, format);
	if (check_conv((form_arg->conv = **format)) == 1)
	{
		form_arg->conv = 0;
		return (1);
	}
	(*format)++;
	return (0);
}

void		clear_opt(t_opt *form_arg)
{
	form_arg->minus = '0';
	form_arg->plus = '0';
	form_arg->zero = '0';
	form_arg->space = '0';
	form_arg->hash = '0';
	form_arg->len = 0;
	form_arg->prec = 0;
	form_arg->mod = NULL;
	form_arg->conv = 0;
}

void		check_opt(t_opt *form_arg, char **format)
{
	while (**format == '-' || **format == '+' || **format == '0' || \
	**format == ' ' || **format == '#')
	{
		if (**format == '-')
			form_arg->minus = '1';
		else if (**format == '+')
			form_arg->plus = '1';
		else if (**format == '0')
			form_arg->zero = '1';
		else if (**format == ' ')
			form_arg->space = '1';
		else if (**format == '#')
			form_arg->hash = '1';
		(*format)++;
	}
}

void		check_len_prec(t_opt *form_arg, char **format, int ftbool)
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
			form_arg->len = ft_atoi(*format);
		else
			form_arg->prec = ft_atoi(*format);
		*format += count;
	}
	if (**format == '.')
	{
		(*format)++;
		check_len_prec(form_arg, format, 1);
	}
}

void		check_mod(t_opt *form_arg, char **format)
{
	int		count;
	char	*tmp;

	count = 0;
	tmp = *format;
	while (*tmp == 'j' || *tmp == 'z' || *tmp == 'h' || *tmp == 'l')
	{
		count++;
		tmp++;
	}
	if (count == 1 || count == 2)
	{
		tmp = ft_strsub(*format, 0, count);
		form_arg->mod = tmp;
	}
	if (count == 2 && (!ft_strequ(form_arg->mod, "ll") && \
	!ft_strequ(form_arg->mod, "hh")))
	{
		free(form_arg->mod);
		form_arg->mod = NULL;
	}
	*format += count;
}
