/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:31:28 by lchim             #+#    #+#             */
/*   Updated: 2017/01/13 23:45:59 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_conv_o(t_form *f)
{
	uintmax_t	nb;

	nb = ft_conv_uintmax(f);
	if (nb == 0 && f->prec == 0)
		check_alloc((f->arg = ft_strnew(0)));
	else
		check_alloc((f->arg = ft_itoa_base(nb, 8, 0)));
	if (f->prec == -1 && f->zero == 1 && !f->minus)
		f->prec = f->len;
	f->prec -= f->hash;
	return (ft_strlen(f->arg));
}

int				ft_conv_x(t_form *f)
{
	uintmax_t	nb;

	nb = ft_conv_uintmax(f);
	if (f->hash)
		f->hash++;
	if (nb == 0)
		f->hash = 0;
	if (nb == 0 && f->prec == 0)
		check_alloc((f->arg = ft_strnew(0)));
	else
		check_alloc((f->arg = ft_itoa_base(nb, 16, 0)));
	if (f->prec == -1 && f->zero == 1 && !f->minus)
		f->prec = f->len - f->hash;
	return (ft_strlen(f->arg));
}

int				ft_conv_b(t_form *f)
{
	uintmax_t	nb;

	nb = ft_conv_uintmax(f);
	f->arg = ft_itoa_base(nb, 2, 0);
	check_alloc((void *)f->arg);
	if (f->prec == -1 && f->zero == 1 && !f->minus)
		f->prec = f->len;
	return (ft_strlen(f->arg));
}
