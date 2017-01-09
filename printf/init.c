/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:29:18 by lchim             #+#    #+#             */
/*   Updated: 2017/01/09 13:28:58 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void			init_array(t_array *p)
{
	p[0] = NULL;
	// p[1] = ft_conv_ws;
	// p[2] = ft_conv_p;
	// p[3] = ft_conv_d;
	// p[4] = ft_conv_d;
	// p[5] = ft_conv_d;
	// p[6] = ft_conv_o;
	// p[7] = ft_conv_o;
	// p[8] = ft_conv_u;
	// p[9] = ft_conv_u;
	// p[10] = ft_conv_x;
	// p[11] = ft_conv_x;
	p[12] = ft_conv_c;
	p[13] = ft_conv_c;
}

void			init_opt(t_form *form)
{
	form->minus = 0;
	form->plus = 0;
	form->zero = 0;
	form->space = 0;
	form->hash = 0;
	form->len = 0;
	form->prec = -1;
	form->mod = NULL;
	form->conv = 0;
}

void			init_clear(t_form **form)
{
	va_end((*form)->ap);
	free((*form)->buff);
	(*form)->buff = NULL;
	if ((*form)->mod)
		free((*form)->mod);
	(*form)->mod = NULL;
	free(*form);
	*form = NULL;
}
