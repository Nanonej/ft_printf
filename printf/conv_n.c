/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:31:24 by lchim             #+#    #+#             */
/*   Updated: 2017/01/14 11:42:49 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_conv_d(t_form *f)
{
	intmax_t	nb;

	nb = ft_conv_intmax(f);
	if (nb == 0 && f->prec == 0)
		check_alloc((f->arg = ft_strnew(0)));
	else
	{
		f->sign = (nb >= 0 ? 0 : 1);
		nb = (nb >= 0 ? nb : -nb);
		check_alloc((f->arg = ft_itoa_base(nb, 10, 0)));
	}
	if (f->sign)
	{
		f->plus = 0;
		f->space = 0;
	}
	if (f->plus)
		f->space = 0;
	if (f->prec == -1 && f->zero == 1 && !f->minus)
		f->prec = f->len - f->plus - f->sign - f->space;
	return (ft_strlen(f->arg));
}

int				ft_conv_u(t_form *f)
{
	uintmax_t	nb;

	nb = ft_conv_uintmax(f);
	if (nb == 0 && f->prec == 0)
		check_alloc((f->arg = ft_strnew(0)));
	else
		check_alloc((f->arg = ft_itoa_base(nb, 10, 0)));
	if (f->prec == -1 && f->zero == 1 && !f->minus)
		f->prec = f->len;
	return (ft_strlen(f->arg));
}

int				ft_conv_f(t_form *f)
{
	long double d;

	if (f->mod == UL)
		d = va_arg(f->ap, long double);
	else
		d = va_arg(f->ap, double);
	if (f->prec == -1)
		f->prec = 6;
	printf("%d\n", f->prec);
	f->arg = ft_dtoa(d < 0 ? -d : d, f->prec, d < 0 ? 1 : 0);
	check_alloc(f->arg);
	if (f->prec == 0 && f->mod != UL)
		f->arg[ft_strlen(f->arg) - 1] = '\0';
	return (ft_strlen(f->arg));
}

intmax_t		ft_conv_intmax(t_form *f)
{
	if (!f->mod && f->conv == 'd')
		return (va_arg(f->ap, int));
	else if (!f->mod && f->conv == 'D')
		return (va_arg(f->ap, long int));
	else if (f->mod == HH)
		return ((signed char)va_arg(f->ap, int));
	else if (f->mod == H)
		return ((short)va_arg(f->ap, int));
	else if (f->mod == Z)
		return (va_arg(f->ap, size_t));
	else if (f->mod == L)
		return (va_arg(f->ap, long int));
	else if (f->mod == LL)
		return (va_arg(f->ap, long long int));
	return (va_arg(f->ap, intmax_t));
}

uintmax_t		ft_conv_uintmax(t_form *f)
{
	if (!f->mod && ft_strfind("OU", f->conv) != -1)
		return (va_arg(f->ap, unsigned long int));
	else if (!f->mod && ft_strfind("ouxXb", f->conv) != -1)
		return (va_arg(f->ap, unsigned int));
	else if (f->mod == HH)
		return ((unsigned char)va_arg(f->ap, unsigned int));
	else if (f->mod == H && f->conv != 'U')
		return ((unsigned short)va_arg(f->ap, unsigned int));
	else if (f->mod == Z)
		return (va_arg(f->ap, size_t));
	else if (f->mod == L)
		return (va_arg(f->ap, unsigned long int));
	else if (f->mod == LL)
		return (va_arg(f->ap, unsigned long long int));
	return (va_arg(f->ap, uintmax_t));
}
