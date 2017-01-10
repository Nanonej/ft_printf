/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:31:28 by lchim             #+#    #+#             */
/*   Updated: 2017/01/10 13:49:39 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_conv_o(t_form *form)
{
	form->arg = ft_itoa_base(ft_conv_uintmax(form), 8, 0);
	check_alloc((void *)form->arg);
	return ((form->arg) ? 1 : 0);
}

int				ft_conv_x(t_form *form)
{
	char		*tmp;

	form->arg = ft_itoa_base(ft_conv_uintmax(form), 16, 0);
	check_alloc((void *)form->arg);
	if (form->conv == 'X')
	{
		tmp = form->arg;
		while (*tmp)
		{
			if (*tmp >= 'a' && *tmp <= 'z')
				*tmp -= 32;
			tmp++;
		}
	}
	return ((form->arg) ? 1 : 0);
}

int				ft_conv_b(t_form *form)
{
	form->arg = ft_itoa_base(ft_conv_uintmax(form), 2, 0);
	check_alloc((void *)form->arg);
	return ((form->arg) ? 1 : 0);
}
