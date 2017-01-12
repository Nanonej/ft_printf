/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:31:24 by lchim             #+#    #+#             */
/*   Updated: 2017/01/13 00:15:00 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_conv_d(t_form *form)
{
	intmax_t	nb;

	nb = ft_conv_intmax(form);
	form->arg = ft_itoa_base((nb > 0 ? nb : -nb), 10, (nb > 0 ? 0 : 1));
	check_alloc((void *)form->arg);
	if (form->arg && form->arg[0] == '-')
	{
		form->plus = 0;
		form->space = 0;
	}
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
		else if (form->mod == HH)
			return ((signed char)va_arg(form->ap, int));
		else if (form->mod == H)
			return ((short)va_arg(form->ap, int));
		else if (form->mod == Z)
			return (va_arg(form->ap, size_t));
		else if (form->mod == L)
			return (va_arg(form->ap, long int));
		else if (form->mod == LL)
			return (va_arg(form->ap, long long int));
		else
			return (va_arg(form->ap, intmax_t));
	}
	return (va_arg(form->ap, long int));
}

uintmax_t		ft_conv_uintmax(t_form *form)
{
	if (ft_strfind("ouUxXb", form->conv) != -1)
	{
		if (!form->mod && form->conv != 'U')
			return (va_arg(form->ap, unsigned int));
		else if (form->mod == HH)
			return ((unsigned char)va_arg(form->ap, unsigned int));
		else if (form->mod == H && form->conv != 'U')
			return ((unsigned short)va_arg(form->ap, unsigned int));
		else if (form->mod == Z)
			return (va_arg(form->ap, size_t));
		else if (form->mod == L)
			return (va_arg(form->ap, unsigned long int));
		else if (form->mod == LL)
			return (va_arg(form->ap, unsigned long long int));
		else
			return (va_arg(form->ap, uintmax_t));
	}
	return ((int)va_arg(form->ap, unsigned long int));
}
