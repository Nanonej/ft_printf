/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:09:13 by lchim             #+#    #+#             */
/*   Updated: 2017/01/04 17:41:47 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		start_opt(t_opt *form_arg, char *buff, int *i)
{
	form_arg->minus = '0';
	form_arg->plus = '0';
	form_arg->zero = '0';
	form_arg->space = '0';
	form_arg->hash = '0';
	form_arg->len = 0;
	form_arg->prec = 0;
	form_arg->mod = NULL;
	check_opt(form_arg, buff, i);
	check_len_prec(form_arg, buff, i, 0);
	check_mod(form_arg, buff, i);
}

void		check_opt(t_opt *form_arg, char *buff, int *i)
{
	while (buff[*i] == '-' || buff[*i] == '+' || buff[*i] == '0'\
	|| buff[*i] == ' ' || buff[*i] == '#')
	{
		if (buff[*i] == '-')
			form_arg->minus = '1';
		else if (buff[*i] == '+')
			form_arg->plus = '1';
		else if (buff[*i] == '0')
			form_arg->zero = '1';
		else if (buff[*i] == ' ')
			form_arg->space = '1';
		else if (buff[*i] == '#')
			form_arg->hash = '1';
		(*i)++;
	}
}

void		check_len_prec(t_opt *form_arg, char *buff, int *i, int ftbool)
{
	int		n;
	int		count;
	int		tmp;

	if (buff[*i] >= '0' && buff[*i] <= '9')
	{
		n = *i;
		count = ft_atoi(&buff[n]);
		tmp = 0;
		while (count)
		{
			count /= 10;
			tmp++;
		}
		*i += tmp;
		if (ftbool == 0)
			form_arg->len = ft_atoi(&buff[n]);
		else
			form_arg->prec = ft_atoi(&buff[n]);
	}
	if (buff[*i] == '.')
	{
		(*i)++;
		check_len_prec(form_arg, buff, i, 1);
	}
}

void		check_mod(t_opt *form_arg, char *buff, int *i)
{
	char	*tmp;
	int		count;

	count = 0;
	tmp = ft_strnew(2);
	check_alloc(tmp);
	while (buff[*i] == 'h' || buff[*i] == 'l' || buff[*i] == 'j' \
	|| buff[*i] == 'z')
	{
		tmp[count] = buff[*i];
		count++;
		(*i)++;
	}
	form_arg->mod = ft_strdup(tmp);
	check_alloc(form_arg->mod);
	free(tmp);
}
