/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:55:38 by lchim             #+#    #+#             */
/*   Updated: 2017/01/12 18:32:23 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_conv_f(t_form *form)
{
	int			i;
	double		e;
	long double	f;
	char		sign;

	if (form->prec == -1 || form->prec >= 10)
		form->prec = 6;
	if (form->mod == UL)
		f = va_arg(form->ap, long double);
	else
	{
		e = va_arg(form->ap, double);
		f = (long double)e;
	}
	form->arg = ft_dtoa(f > 0 ? f : -f, form->prec, f > 0 ? 0 : 1);
	check_alloc((void *)form->arg);
	if (!form->hash && (form->arg)[ft_strlen(form->arg) - 1] == '.')
		(form->arg)[ft_strlen(form->arg) - 1] = '\0';
	if (form->arg[0] == '.')
	{
		form->arg = free_swap(form->arg, ft_strjoin("0", form->arg));
		check_alloc((void *)form->arg);
	}
	return ((form->arg) ? 1 : 0);
}
