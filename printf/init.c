/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:29:18 by lchim             #+#    #+#             */
/*   Updated: 2017/01/12 15:55:59 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_array(t_array *p)
{
	// p[0] = ft_conv_s;
	// p[1] = ft_conv_s;
	p[2] = ft_conv_x;
	p[3] = ft_conv_d;
	p[4] = ft_conv_d;
	p[5] = ft_conv_d;
	p[6] = ft_conv_o;
	p[7] = ft_conv_o;
	p[8] = ft_conv_u;
	p[9] = ft_conv_u;
	p[10] = ft_conv_x;
	p[11] = ft_conv_x;
	p[12] = ft_conv_c;
	p[13] = ft_conv_c;
	p[14] = ft_conv_b;
	p[15] = ft_conv_b;
	p[16] = ft_conv_f;
	p[17] = ft_conv_f;
	// p[18] = ft_conv_e;
	// p[19] = ft_conv_e;
	p[20] = ft_conv_pct;
}

t_form			*init_form(t_form *form)
{
	form = (t_form *)malloc(sizeof(t_form));
	check_alloc((void *)form);
	form->buff = ft_strnew(0);
	check_alloc((void *)form->buff);
	init_array(form->p);
	init_opt(form);
	return (form);
}

void			init_opt(t_form *form)
{
	form->arg = NULL;
	form->minus = 0;
	form->plus = 0;
	form->zero = 0;
	form->space = 0;
	form->hash = 0;
	form->len = -1;
	form->prec = -1;
	form->mod = 0;
	form->conv = '\0';
}

void			init_clear(t_form **form)
{
	va_end((*form)->ap);
	if ((*form)->buff)
		free((*form)->buff);
	if ((*form)->arg)
		free((*form)->arg);
	init_opt(*form);
	free(*form);
	*form = NULL;
}
