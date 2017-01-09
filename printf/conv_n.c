/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:31:24 by lchim             #+#    #+#             */
/*   Updated: 2017/01/09 20:25:03 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_conv_d(t_form *form)
{
	intmax_t	nb;

	if (form->conv != 'D')
	{
		if (!form->mod)
			nb = va_arg(form->ap, int);
		else if (ft_strequ(form->mod, "hh"))
			nb = (signed char)va_arg(form->ap, int);
		else if ((form->mod)[0] == 'h')
			nb = (short)va_arg(form->ap, int);
		else if ((form->mod)[0] == 'z')
			nb = va_arg(form->ap, unsigned int);
		else if ((form->mod)[0] == 'l')
			nb = va_arg(form->ap, long int);
		else if (ft_strequ(form->mod, "ll"))
			nb = va_arg(form->ap, long long int);
		else if ((form->mod)[0] == 'j')
			nb = va_arg(form->ap, intmax_t);
	}
	else if (form->conv == 'D' && !form->mod)
		nb = va_arg(form->ap, long int);
	form->arg = ft_itoa_base(nb ? nb : -nb, 10, nb ? 0 : 1);
	check_alloc((void *)form->arg);
	return ((form->arg) ? 1 : 0);
}
