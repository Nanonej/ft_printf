/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:58:49 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/05 17:45:36 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_s(char *buff, va_list ap, t_opt form_arg)
{	char *tmp;

	tmp = buff;
	buff = ft_strjoin(buff, va_arg(ap, char*));
	check_alloc((void *)buff);
	free(tmp);
	return (0);
}
