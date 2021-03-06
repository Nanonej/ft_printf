/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:31:28 by lchim             #+#    #+#             */
/*   Updated: 2017/04/02 15:54:53 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_conv_o(t_form *f)
{
	uintmax_t	nb;

	nb = ft_conv_uintmax(f);
	if (f->conv == 'o' && nb == 0 && f->hash == 1 && f->prec != 0)
		f->hash = 0;
	if (nb == 0 && f->prec == 0)
		check_alloc((f->arg = ft_strnew(0)));
	else
		check_alloc((f->arg = ft_itoa_base(nb, 8, 0)));
	return (ft_strlen(f->arg));
}

int				ft_conv_x(t_form *f)
{
	uintmax_t	nb;

	nb = ft_conv_uintmax(f);
	if (nb == 0 && f->prec == 0)
		check_alloc((f->arg = ft_strnew(0)));
	else
		check_alloc((f->arg = ft_itoa_base(nb, 16, 0)));
	if (nb == 0 && f->conv != 'p')
		f->hash = 0;
	if (f->conv == 'p')
	{
		f->conv = 'x';
		f->hash = 1;
	}
	return (ft_strlen(f->arg));
}

int				ft_conv_b(t_form *f)
{
	uintmax_t	nb;

	nb = ft_conv_uintmax(f);
	if (nb == 0 && f->prec == 0)
		check_alloc((f->arg = ft_strnew(0)));
	else
		check_alloc((f->arg = ft_itoa_base(nb, 2, 0)));
	return (ft_strlen(f->arg));
}
