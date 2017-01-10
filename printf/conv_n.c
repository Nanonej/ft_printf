/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:31:24 by lchim             #+#    #+#             */
/*   Updated: 2017/01/10 12:01:46 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_conv_d(t_form *form)
{
	intmax_t	nb;

	nb = ft_conv_intmax(form);
	form->arg = ft_itoa_base((nb > 0 ? nb : -nb), 10, (nb > 0 ? 0 : 1));
	check_alloc((void *)form->arg);
	return ((form->arg) ? 1 : 0);
}

int				ft_conv_u(t_form *form)
{
	form->arg = ft_itoa_base(ft_conv_uintmax(form), 10, 0);
	check_alloc((void *)form->arg);
	return ((form->arg) ? 1 : 0);
}

intmax_t		ft_conv_intmax(t_form *form)
{
	if (ft_strfind("d", form->conv) != -1)
	{
		if (!form->mod)
			return (va_arg(form->ap, int));
		else if (ft_strequ(form->mod, "hh"))
			return ((signed char)va_arg(form->ap, int));
		else if ((form->mod)[0] == 'h')
			return ((short)va_arg(form->ap, int));
		else if ((form->mod)[0] == 'z')
			return (va_arg(form->ap, size_t));
		else if ((form->mod)[0] == 'l')
			return (va_arg(form->ap, long int));
		else if (ft_strequ(form->mod, "ll"))
			return (va_arg(form->ap, long long int));
		else if ((form->mod)[0] == 'j')
			return (va_arg(form->ap, intmax_t));
	}
	return (va_arg(form->ap, long int));
}

uintmax_t		ft_conv_uintmax(t_form *form)
{
	if (ft_strfind("ouxb", form->conv) != -1)
	{
		if (!form->mod)
			return (va_arg(form->ap, unsigned int));
		else if (ft_strequ(form->mod, "hh"))
			return ((unsigned char)va_arg(form->ap, unsigned int));
		else if ((form->mod)[0] == 'h')
			return ((unsigned short)va_arg(form->ap, unsigned int));
		else if ((form->mod)[0] == 'z')
			return (va_arg(form->ap, size_t));
		else if ((form->mod)[0] == 'l')
			return (va_arg(form->ap, unsigned long int));
		else if (ft_strequ(form->mod, "ll"))
			return (va_arg(form->ap, unsigned long long int));
		else if ((form->mod)[0] == 'j')
			return (va_arg(form->ap, uintmax_t));
	}
	return (va_arg(form->ap, unsigned long int));
}
