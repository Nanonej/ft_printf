/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_ft_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:19:33 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/05 17:23:01 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type(int (**p)(char*, char**, va_list))
{
	int (*p[14]) (char *buff, char **format, va_list ap);

	p[0] = ft_conv_s;
	p[1] = ft_conv_ws;
	p[2] = ft_conv_p;
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
	p[13] = ft_conv_uc;
}
